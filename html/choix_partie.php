<!DOCTYPE html>
<html>
<head>
	<title> Projet Final Burger Quiz </title>
	<link rel="stylesheet" type="text/css" href="../css/style.css">
	<link href="https://fonts.googleapis.com/css?family=Carter+One" rel="stylesheet">
	<meta charset="utf-8">
</head>
</body>
<header> 
	<a href="menu.html"> <img src="../images/logo.png" alt="Logo Burger"/> </a>
	<h1> BURGER QUIZ </h1>
	<a href="../index.php"> <img src="../images/deco.png" alt="Logo Isen"/> </a>
</header>

<section id="section_choix_partie">
	<h2> Choix de la partie : </h2>
	<form method="POST" action="choix.php">
		<select name="select_choix_partie">	
		<?php
		require '../php/connexionBDD.php'; // Fichier connexion à la BDD
		require '../php/class.php'; // Fichier des classes

		$select_partie = $bdd->prepare("SELECT id_partie FROM Partie");
		$select_partie->execute();
		$id_parties = $select_partie->fetchAll(PDO::FETCH_CLASS, 'Partie');

		foreach($id_parties as $id_partie){
			echo "<option>".$id_partie->getID_PARTIE()."</option>";
		}
		?>

		</select> <br>

		<input type="submit" value="JOUER !" /> <br>
	</form>
</section>

<footer id="footer_choix_partie">
	<div>
		<p> BALAN Pierre <br> COTTEN Maël </p>
	</div>

	<div>
		<p> ISEN BREST <br> 2018 </p>
	</div>	
</footer>
</body>
</html>