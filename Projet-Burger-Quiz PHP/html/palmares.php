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

<section id="section_palmares">
	<img src="../images/trophee.png" alt="Trophée"/>
	<h2> Palmarès </h2>
	<img src="../images/trophee.png" alt="Trophée"/>
	<?php require '../php/affichage_palmares.php';?>
	<form method="POST" action="nouvelle_partie.php">
		<input type="SUBMIT" value="NOUVELLE PARTIE"/>
	</form> 
</section>

<footer id="footer_palmares">
	<div>
		<p> BALAN Pierre <br> COTTEN Maël </p>
	</div>

	<div>
		<p> ISEN BREST <br> 2018 </p>
	</div>	
</footer>
</body>
</html>