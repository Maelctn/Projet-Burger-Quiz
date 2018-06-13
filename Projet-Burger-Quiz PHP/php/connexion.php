<?php
session_start();
require 'connexionBDD.php'; // Fichier connexion à la BDD
require 'class.php'; // Fichier des classes

/**
* \brief Vérrifie si les champs du formulaire de connexion sont remplis. Si non, reste sur la page de connexion.
*/
if(!empty($_POST['connect_login']) && !empty($_POST['connect_pwd'])){

	/**
	* \brief Affectation des valeurs des champs à des variables
	*/
	$login_connect = $_POST['connect_login'];
	$password_connect = $_POST['connect_pwd'];
	
	/**
	* \brief Encryption du password
	*/
	$password_connect=sha1($password_connect);
	
	/**
	* \brief Récupération des données de la base Joueur sous forme de tableau
	*/
	$select = $bdd->prepare("SELECT * FROM Joueur");
	$select->execute();
	$joueurs=$select->fetchAll(PDO::FETCH_CLASS, 'Joueur');
	$login_exist = 0; // Booléen initialisé à 0

	/**
	* \brief Vérification si le login rentré existe déja et si le password sont corrects
	*/
	foreach ($joueurs as $joueur){
		if($joueur->getLOGIN() == $login_connect && $joueur->getPASSWORD() == $password_connect){
			$login_exist = 1;
			/**
			* \brief Variable de session type tableau qui récupère id du joueur connecté
			*/
			$_SESSION["id_joueur"] = $joueur->getID_LOGIN();
		}
	}

	if($login_exist == 1){
			// Tout est OK on passe au menu
			header('Location: ../html/menu.html');
		}else{		
			// Ici le login ou le password sont incorrects
			header('Location: ../index.php');
		}

}else{
	// Les champs ne sont pas remplis, on renvoit à la page d'erreur
	header('Location: ../index.php');
}
?>