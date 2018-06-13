<?php
/**
* \brief Variable contenant l'adresse et le nom de la BDD
*/
$myDsn = 'mysql:host=localhost;dbname=Projet_Burger_Quiz;charset=UTF8';
/**
* \brief Variable contenant le login pour se connecter à la BDD
*/
$myUserDb = 'Projet_Burger_Quiz';
/**
* \brief Variable contenant le password pour se connecter à la BDD
*/
$myPwdDb = 'mael';

/**
* \brief Boucle de connexion à la BDD. Si échec, affichage de l'erreur.
*/
try{
	$bdd=new PDO($myDsn, $myUserDb, $myPwdDb);
}catch(PDOException $e){
  	echo 'Connexion échouée : '.$e->getMessage();
}
?>