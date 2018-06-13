/**
* \brief Surligne de la couleur choisie le champ non rempli
* \param Entrée : champ, erreur
*/
function surligne(champ, erreur){
	if(erreur){
		champ.style.backgroundColor = "#FF5F35";
	}else{
		champ.style.backgroundColor = "";
	}
}

/**
* \brief Vérfie si le champ est inférieur à 50 caractères
* \param Entrée : champ
*/
function VerifConnect_Login(champ){
	if(champ.value.length > 50){
		surligne(champ, true);
		return false;
	}else{
		surligne(champ, false);
		return true;
	}
}

/**
* \brief Vérfie si le champ est inférieur à 50 caractères
* \param Entrée : champ
*/
function VerifConnect_Pwd(champ){
	if(champ.value.length > 50){
		surligne(champ, true);
		return false;
	}else{
		surligne(champ, false);
		return true;
	}
}

/**
* \brief Vérfie si le champ est inférieur à 50 caractères
* \param Entrée : champ
*/
function VerifInscrip_Login(champ){
	if(champ.value.length > 50){
		surligne(champ, true);
		return false;
	}else{
		surligne(champ, false);
		return true;
	}
}

/**
* \brief Vérfie si le champ est inférieur à 50 caractères
* \param Entrée : champ
*/
function VerifInscrip_Pwd(champ){
	if(champ.value.length > 50){
		surligne(champ, true);
		return false;
	}else{
		surligne(champ, false);
		return true;
	}
}

/**
* \brief Vérfie si le champ est inférieur à 50 caractères
* \param Entrée : champ
*/
function VerifInscrip_Pwd2(champ){
	if(champ.value.length > 50){
		surligne(champ, true);
		return false;
	}else{
		surligne(champ, false);
		return true;
	}
}

/**
* \brief Vérifie si les variables correspondantes a la connexion sont vraies ou si celles de l'inscription le sont. Si non, empêche l'envoie du formulaire
* \param Entrée : f
*/
function verifForm(f){
   var connect_loginOk = VerifConnect_Login(f.connect_login);
   var connect_pwdOk = VerifConnect_Pwd(f.connect_pwd);
   var inscript_loginOk = VerifInscrip_Login(f.inscrip_login);
   var inscript_pwdOK =	VerifInscrip_Pwd(f.inscrip_pwd);
   var inscript_pwd2OK = VerifInscrip_Pwd2(f.inscrip_pwd);

   if(connect_loginOk && connect_pwdOk || inscript_loginOk && inscript_pwdOK && inscript_pwd2OK){
      return true;
   }else{
   	  alert("Veuillez remplir votre mot de passe ou votre login avec moins de 50 caractères");
      return false;
   }

}