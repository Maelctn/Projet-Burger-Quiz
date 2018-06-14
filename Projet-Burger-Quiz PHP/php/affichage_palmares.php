<?php
session_start();

require 'connexionBDD.php'; // Fichier connexion à la BDD
require 'class.php'; // Fichier des classes

// Récupère le score de la partie jouée
echo "<h3> Votre score : ".$_SESSION["score"]. " points ! </h3>";

/**
* \brief Sélectionne dans la table Joueur le login et le meilleur score quand il n'est pas null.
*/
$select_score = $bdd->prepare("SELECT login, best_score FROM Joueur WHERE best_score IS NOT NULL AND best_score>0");
$select_score->execute();
/**
* \brief Crée un tableau d'objet Joueur contenant les login et les best_score
*/
$joueurs = $select_score->fetchAll(PDO::FETCH_CLASS, 'Joueur');


// Trie les score en ordre décroissant
arsort($joueurs);

/**
* \brief Affiche les login et les scores des meilleurs joueurs dans l'ordre décroissant, sous forme de tableau html.
*/
echo "<table>";
echo "<tr><th> Login </th><th> Best Score </th></tr>";
foreach ($joueurs as $joueur){
	echo "<tr><td><center>".$joueur->getLOGIN()."</center></td><td><center>".$joueur->getBEST_SCORE()."</center></td></tr>";

}
echo "</table>";

?>