<?php
session_start();

require 'connexionBDD.php'; // Fichier connexion à la BDD
require 'class.php'; // Fichier des classes

/**
* \brief Tableau des réponses cochées par le joueur
*/
$tab_post = array();
$bonne_rep = 0;
$mauvaise_rep = 0;


/**
* \brief Met les valeurs des réponses cochées dans le tableau prévu
*/
for($i=0; $i<$_SESSION["taille_tab_choix"]; $i++){
	for($j=0; $j<$_SESSION["taille_index_choix"]; $j++){
		array_push($tab_post, $_POST[$j.'_'.$i]);
	}
}

/**
* \brief Compare le tableau des réponses et le tableau des valeurs cochées. Incrémentation des bonnes réponses ou mauvaises
*/
for($k=0; $k<sizeof($tab_post); $k++){
	if($tab_post[$k] == $_SESSION["reponse_choix"][$k]){
		$bonne_rep = $bonne_rep + 100;
	}else{
		$mauvaise_rep++;		
	}
}

/**
* \brief Récupère le temps du chrono
*/
$temps = $_POST['temps'];

/**
* \brief Calcul le score et arrondit à l'entier supérieur
*/ 
$score = ceil($bonne_rep-$temps*5);

$select_joueur = $bdd->prepare("SELECT * FROM Joueur");
$select_joueur->execute();
$joueurs = $select_joueur->fetchAll(PDO::FETCH_CLASS, 'Joueur');

/**
* \brief Si le score du joueur est NULL, insert le score de la partie. Si le joueur possède déjà un score, vérifie s'il est plus petit que le dernier score obtenu, si oui, l'insert à la place.
*/
foreach ($joueurs as $joueur){
	if($joueur->getID_LOGIN() == $_SESSION["id_joueur"]){
		if($joueur->getBEST_SCORE() == NULL){
			$inser_score = $bdd->prepare("UPDATE Joueur SET best_score= ".$score." WHERE id_login= ".$_SESSION["id_joueur"]);
			$inser_score->execute();
		}else if($joueur->getBEST_SCORE() != NULL){	
			$inser_score = $bdd->prepare("UPDATE Joueur SET best_score= ".$score." WHERE id_login= ".$_SESSION["id_joueur"]." AND best_score < ".$score);
			$inser_score->execute();
		}
	}
}

/**
* \brief Variable de session de type tableau qui récupère le score final
*/
$_SESSION["score"] = $score;

header('Location: ../html/palmares.php');
?>