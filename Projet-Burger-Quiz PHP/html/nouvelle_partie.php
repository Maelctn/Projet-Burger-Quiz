<?php session_start(); ?>

<!DOCTYPE html>
<html>
<head>
	<title> Projet Final Burger Quiz </title>
	<link rel="stylesheet" type="text/css" href="../css/style.css">
	<link href="https://fonts.googleapis.com/css?family=Carter+One" rel="stylesheet">  
	<script src="../js/chrono.js"></script>
	<meta charset="utf-8">
</head>
</body>
<header> 
	<a href="menu.html"> <img src="../images/logo.png" alt="Logo Burger"/> </a>
	<h1> BURGER QUIZ </h1>
	<a href="../index.php"> <img src="../images/deco.png" alt="Logo Isen"/> </a>
</header>

<section id="section_nouvelle_partie">

	<form method="POST" id="form_temps" action="../php/validation_rep.php">
		<input type="text" name="chronotime" id="chronotime" value="0:00:00"/>
		<?php require '../php/generation_partie.php'; ?>
		<input type="submit" value="VALIDER" onclick="chronoStop()"/> <br>
	</form>
</section>

<footer id="footer_nouvelle_partie">
	<div>
		<p> BALAN Pierre <br> COTTEN Maël </p>
	</div>

	<div>
		<p> ISEN BREST <br> 2018 </p>
	</div>	
</footer>
</body>
</html>
