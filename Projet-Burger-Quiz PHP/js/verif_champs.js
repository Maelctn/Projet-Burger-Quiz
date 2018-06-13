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
* \brief Vérfie si le champ est rempli
* \param Entrée : champ
*/
function VerifConnect_Login(champ){
	if(champ.value == ""){
		surligne(champ, true);
		return false;
	}else{
		surligne(champ, false);
		return true;
	}
}

/**
* \brief Vérfie si le champ est rempli
* \param Entrée : champ
*/
function VerifConnect_Pwd(champ){
	if(champ.value == ""){
		surligne(champ, true);
		return false;
	}else{
		surligne(champ, false);
		return true;
	}
}

/**
* \brief Vérfie si le champ est rempli
* \param Entrée : champ
*/
function VerifInscrip_Login(champ){
	if(champ.value == ""){
		surligne(champ, true);
		return false;
	}else{
		surligne(champ, false);
		return true;
	}
}

/**
* \brief Vérfie si le champ est rempli
* \param Entrée : champ
*/
function VerifInscrip_Pwd(champ){
	if(champ.value == ""){
		surligne(champ, true);
		return false;
	}else{
		surligne(champ, false);
		return true;
	}
}

/**
* \brief Vérfie si le champ est rempli
* \param Entrée : champ
*/
function VerifInscrip_Pwd2(champ){
	if(champ.value == ""){
		surligne(champ, true);
		return false;
	}else{
		surligne(champ, false);
		return true;
	}
}