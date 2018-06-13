<?php
require 'connexionBDD.php'; // Fichier connexion à la BDD
require 'class.php'; // Fichier des classes

$nb_questions = 3;
$nb_propositions = 3;
$index = 0;
$indexSession = 0;
$radio = "radio";
$choix1 = "choix1";
$choix2 = "choix2";
$choix3 = "Les deux";
$value1 = "1";
$value2 = "2";
$value3 = "3";
$score = NULL;

/**
* \brief Sélectionne 3 questions aléatoirement 
*/
$select_quest = $bdd->prepare("SELECT * FROM Question ORDER BY RAND() LIMIT ".$nb_questions);
$select_quest->execute();
$questions = $select_quest->fetchAll(PDO::FETCH_CLASS, 'Question');

/**
* \brief Crée une partie en initialisant le score à NULL 
*/
$creation_partie = $bdd->prepare("INSERT INTO Partie(score) VALUES(:score)");
$creation_partie->execute(array(':score' => $score));

/**
* \brief Récupère le dernier id inséré en base
*/
$id_partie = $bdd->lastInsertId();

/**
* \brief Affiche les questions choisies aléatoirement
*/
foreach ($questions as $question){
	echo "<h2><center>".$question->getQUESTION()."</center></h2>";
	
	/**
	* \brief Insert dans Partie_Question les 3 questions correspondantes à la partie jouée
	*/
	$insert_questions = $bdd->prepare("INSERT INTO Partie_Question(id_partie, id_question) VALUES(:id_partie, :id_question)");
	$insert_questions->execute(array('id_partie' => $id_partie, 'id_question' => $question->getID_QUESTION()));

	/**
	* \brief Sélectionne 3 propositions aléatoirement pour chacune des questions
	*/
	$select_prop = $bdd->prepare("SELECT proposition, reponse FROM Proposition WHERE id_question=".$question->getID_QUESTION()." ORDER BY RAND() LIMIT ".$nb_propositions);
	$select_prop->execute();
	$propositions = $select_prop->fetchAll(PDO::FETCH_CLASS, 'Proposition');

	/**
	* \brief Affiche les propositions choisies aléatoirement
	*/
	$j=0;
	foreach ($propositions as $proposition){
		echo "<h3><center>".$proposition->getPROPOSITION()."</center></h3><br>";

		/**
		* \brief Tableau des réponses pour chaque proposition
		*/
		$_SESSION["reponse"][$indexSession] = $proposition->getREPONSE();
		$indexSession++;

		/**
		* \brief Affiche les boutons radio des choix avec les choix
		*/
		echo "<input name=".$j."_".$index." type=".$radio." id=".$choix1." value=".$value1.">";
		echo "<label for=".$choix1.">".$question->getCHOIX_1()."</label>";

		echo "<input name=".$j."_".$index." type=".$radio." id=".$choix2." value=".$value2.">";
		echo "<label for=".$choix2.">".$question->getCHOIX_2()."</label>";

		echo "<input name=".$j."_".$index." type=".$radio." id=".$choix3." value=".$value3.">";
		echo "<label for=".$choix3.">".$choix3."</label><br>";

		$j++;
	}	
	$index++;
}


/**
* \brief Variable de session type tableau de la taille finale de l'index
*/
$_SESSION["taille_index"] = $index;
/**
* \brief Variable de session type tableau du nombre de questions par partie
*/
$_SESSION["taille_tab"]= sizeof($questions);
/**
* \brief Variable de session type tableau de l'id_partie en cours
*/
$_SESSION["id_partie"] = $id_partie;
?>