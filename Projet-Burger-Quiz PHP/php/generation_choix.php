<?php 
require 'connexionBDD.php'; // Fichier connexion à la BDD
require 'class.php'; // Fichier des classes

/**
* \brief Récupère le choix de partie du joueur
*/
$choix = $_POST['select_choix_partie'];


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
* \brief Récupère les 3 id des questions de la partie sélectionnée
*/
$select_id_questions = $bdd->prepare("SELECT id_question FROM Partie_Question WHERE id_partie=".$choix);
$select_id_questions->execute();
/**
* \brief Crée un tableau d'objet Partie_Question contenant les id_question
*/
$id_questions = $select_id_questions->fetchAll(PDO::FETCH_CLASS, 'Partie_Question');
/**
* \brief Récupère toute la table pour les 3 questions sélectionnées
*/
foreach($id_questions as $id_question){
	$select_question = $bdd->prepare("SELECT * FROM Question WHERE id_question=".$id_question->getID_QUESTION());
	$select_question->execute();
	$questions = $select_question->fetchAll(PDO::FETCH_CLASS, 'Question');

	/**
	* \brief Affiche les 3 questions
	*/
	foreach($questions as $question){
		echo "<h2><center>".$question->getQUESTION()."</center></h2>";

		/**
		* \brief Sélectionne 3 propositions aléatoirement pour chacune des questions
		*/
		$select_prop = $bdd->prepare("SELECT * FROM Proposition WHERE id_question=".$question->getID_QUESTION()." ORDER BY RAND() LIMIT ".$nb_propositions);
		$select_prop->execute();
		$propositions = $select_prop->fetchAll(PDO::FETCH_CLASS, 'Proposition');


		/**
		* \brief Affiche les propositions choisies aléatoirement
		*/
		$j=0;
		foreach ($propositions as $proposition){
			echo "<h3><center>".$proposition->getPROPOSITION()."</center></h3><br>";
		
			/**
			* \brief Récupère en variable de session les réponses pour les propositions générées
			*/
			$_SESSION["reponse_choix"][$indexSession] = $proposition->getREPONSE(); // Tableau des réponses pour chaque proposition
			$indexSession++;

			// Affiche les boutons radio des choix
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
}

/**
* \brief Récupère en variable de session la valeur de index
*/
$_SESSION["taille_index_choix"] = $index; // Tableau de la taille finale de l'index
/**
* \brief Récupère en variable de session la valeur du nombre de propositions par question
*/
$_SESSION["taille_tab_choix"]= sizeof($propositions); // Tableau du nombre de questions par partie
?>