<!DOCTYPE html>
<html>
<head>
	<title> Projet Final Burger Quiz </title>
	<link rel="stylesheet" type="text/css" href="css/style.css">
	<link href="https://fonts.googleapis.com/css?family=Carter+One" rel="stylesheet">  
	<script src="js/verif_champs.js"></script>
	<meta charset="utf-8">
</head>
</body>
<header> 
	<a href="index.php"> <img src="images/logo.png" alt="Logo Burger"/> </a>
	<h1> BURGER QUIZ </h1>
	<a href="index.php"> <img src="images/deco.png" alt="Logo Isen"/> </a>
</header>

<section id="section_index">
	<h2> Se connecter </h2>
	<form method="POST" action="php/connexion.php">
		LOGIN : <input type="text" name="connect_login" onblur="VerifConnect_Login(this)"/> <br>
		PASSWORD : <input type="password" name="connect_pwd" onblur="VerifConnect_Pwd(this)"/> <br>
		<input type="submit" value="VALIDER" /> <br>
	</form>

	<h2> S'inscrire </h2>
	<form method="POST" action="php/inscription.php">
		LOGIN : <input type="text" name="inscrip_login" onblur="VerifInscrip_Login(this)"/> <br>
		PASSWORD : <input type="password" name="inscrip_pwd" onblur="VerifInscrip_Pwd(this)"/> <br>
		PASSWORD : <input type="password" name="verif_inscrip_pwd" onblur="VerifInscrip_Pwd2(this)"/> <br>
		<input type="submit" value="VALIDER" onsubmit="return verifForm(this)" /> <br>
	</form>		 
</section>

<footer id="footer_index">
	<div>
		<p> BALAN Pierre <br> COTTEN Maël </p>
	</div>

	<div>
		<p> ISEN BREST <br> 2018 </p>
	</div>	
</footer>
</body>
</html>