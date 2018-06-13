<?php
session_start();

require 'connexionBDD.php'; // Fichier connexion à la BDD
require 'class.php'; // Fichier des classes

/**
* \brief Vérifie si les champs sont remplis
*/
if(!empty($_POST['inscrip_login']) && !empty($_POST['inscrip_pwd']) && !empty($_POST['verif_inscrip_pwd'])){
	
	/**
	* \brief Affectation des valeurs des champs à des variables
	*/
	$login = $_POST['inscrip_login'];
	$password = $_POST['inscrip_pwd'];
	$verif_password = $_POST['verif_inscrip_pwd'];
	
	/**
	* \brief Encryption des deux password
	*/
	$password=sha1($password);
	$verif_password=sha1($verif_password);

	/**
	* \brief Récupération des données de la table Joueur sous forme de tableau
	*/

	$select = $bdd->prepare("SELECT * FROM Joueur");
	$select->execute();
	$joueurs=$select->fetchAll(PDO::FETCH_CLASS, 'Joueur');

	$login_exist = 0; // Booléen initialisé à 0

	/**
	* \brief Vérification si le login rentré existe déja ou non
	*/
	foreach ($joueurs as $joueur){
		if($joueur->getLOGIN() == $login){
			$login_exist = 1;
		}
	}
	
	// Ici il existe, on renvoit à la page d'erreur
	if($login_exist == 1){
		header('Location: ../index.php');
	}else{		
		/**
		* \brief Vérification que le mot de passe est correctement rentré 2 fois
		*/
		if($password == $verif_password){
			/**
			* \brief Insertion du compte du joueur en BDD
			*/ 
			$inser = $bdd->prepare("INSERT INTO Joueur(login,password) VALUES (:login,:password)");
			$inser->execute(array(':login' => $login, ':password' => $password));

			/**
			* \brief Récupère dernier id rentré en base
			*/
			$last_id_login = $bdd->lastInsertId();

			/**
			* \brief Variable de session type tableau qui récupère le dernier id rentré en base
			*/
			$_SESSION["id_joueur"] = $last_id_login;
			
			// Tout est OK on passe au menu
			header('Location: ../html/menu.html');
		}else{
			// Mots de passes différents, on renvoit à la page d'erreur
			header('Location: ../index.php');
		}
	}

}else{
	// Les champs ne sont pas remplis, on renvoit à la page d'erreur
	header('Location: ../index.php');
}

?>