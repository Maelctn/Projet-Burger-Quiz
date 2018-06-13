<?php

/**
* \author Maël COTTEN
* \date 12/06/2018
* \brief Class Joue correspondant à la table Joue. Attributs privés : id_login, id_partie. Retourne par getter les attributs privés.
*/
class Joue{
	private $id_login;
	private $id_partie;

	public function getID_LOGIN(){
		return $this->id_login;
	}

	public function getID_PARTIE(){
		return $this->id_partie;
	}
}

/**
* \author Maël COTTEN
* \date 12/06/2018
* \brief Class Joueur correspondant à la table Joueur. Attributs privés : id_login, best_score, login, password. Retourne par getter les attributs privés.
*/
class Joueur{
	private $best_score;
	private $id_login;
	private $login;
	private $password;

	public function getBEST_SCORE(){
		return $this->best_score;
	}

	public function getID_LOGIN(){
		return $this->id_login;
	}

	public function getLOGIN(){
		return $this->login;
	}

	public function getPASSWORD(){
		return $this->password;
	}
}

/**
* \author Maël COTTEN
* \date 12/06/2018
* \brief Class Partie correspondant à la table Partie. Attributs privés : id_partie, score. Retourne par getter les attributs privés.
*/
class Partie{
	private $id_partie;
	private $score;

	public function getID_PARTIE(){
		return $this->id_partie;
	}

	public function getSCORE(){
		return $this->score;
	}
}

/**
* \author Maël COTTEN
* \date 12/06/2018
* \brief Class Partie_Question correspondant à la table Partie_Question. Attributs privés : id_partie, id_question. Retourne par getter les attributs privés.
*/
class Partie_Question{
	private $id_partie;
	private $id_question;

	public function getID_PARTIE(){
		return $this->id_partie;
	}

	public function getID_QUESTION(){
		return $this->id_question;
	}
}

/**
* \author Maël COTTEN
* \date 12/06/2018
* \brief Class Proposition correspondant à la table Proposition. Attributs privés : id_proposition, id_question, proposition, reponse. Retourne par getter les attributs privés.
*/
class Proposition{
	private $id_proposition;
	private $id_question;
	private $proposition;
	private $reponse;

	public function getID_PROPOSITION(){
		return $this->id_proposition;
	}

	public function getID_QUESTION(){
		return $this->id_question;
	}	

	public function getPROPOSITION(){
		return $this->proposition;
	}

	public function getREPONSE(){
		return $this->reponse;
	}
}

/**
* \author Maël COTTEN
* \date 12/06/2018
* \brief Class Question correspondant à la table Question. Attributs privés : choix_1, choix_2, id_question, id_theme, question. Retourne par getter les attributs privés.
*/
class Question{
	private $choix_1;
	private $choix_2;
	private $id_question;
	private $id_theme;
	private $question;

	public function getCHOIX_1(){
		return $this->choix_1;
	}	

	public function getCHOIX_2(){
		return $this->choix_2;
	}

	public function getID_QUESTION(){
		return $this->id_question;
	}

	public function getID_THEME(){
		return $this->id_theme;
	}

	public function getQUESTION(){
		return $this->question;
	}
}

/**
* \author Maël COTTEN
* \date 12/06/2018
* \brief Class Theme correspondant à la table Theme. Attributs privés : id_theme, theme. Retourne par getter les attributs privés.
*/
class Theme{
	private $id_theme;
	private $theme;

	public function getID_THEME(){
		return $this->id_theme;
	}

	public function getTHEME(){
		return $this->theme;
	}
}

?>