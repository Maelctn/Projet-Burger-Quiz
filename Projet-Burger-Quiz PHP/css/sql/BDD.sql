#------------------------------------------------------------
#        Script MySQL.
#------------------------------------------------------------


#------------------------------------------------------------
# Table: Joueur
#------------------------------------------------------------

CREATE TABLE Joueur(
        id_login   Int  Auto_increment  NOT NULL ,
        login      Varchar (50) NOT NULL ,
        password   Varchar (50) NOT NULL ,
        best_score Int
	,CONSTRAINT Joueur_PK PRIMARY KEY (id_login)
)ENGINE=InnoDB CHARSET=utf8 COLLATE utf8_unicode_ci;


#------------------------------------------------------------
# Table: Partie
#------------------------------------------------------------

CREATE TABLE Partie(
        id_partie Int  Auto_increment  NOT NULL ,
        score     Int
	,CONSTRAINT Partie_PK PRIMARY KEY (id_partie)
)ENGINE=InnoDB CHARSET=utf8 COLLATE utf8_unicode_ci;


#------------------------------------------------------------
# Table: Theme
#------------------------------------------------------------

CREATE TABLE Theme(
        id_theme Int  Auto_increment  NOT NULL ,
        theme    Varchar (50) NOT NULL
	,CONSTRAINT Theme_PK PRIMARY KEY (id_theme)
)ENGINE=InnoDB CHARSET=utf8 COLLATE utf8_unicode_ci;


#------------------------------------------------------------
# Table: Question
#------------------------------------------------------------

CREATE TABLE Question(
        id_question Int  Auto_increment  NOT NULL ,
        question    Varchar (200) NOT NULL ,
        choix_1     Varchar (200) NOT NULL ,
        choix_2     Varchar (200) NOT NULL ,
        id_theme    Int NOT NULL
	,CONSTRAINT Question_PK PRIMARY KEY (id_question)

	,CONSTRAINT Question_Theme_FK FOREIGN KEY (id_theme) REFERENCES Theme(id_theme)
)ENGINE=InnoDB CHARSET=utf8 COLLATE utf8_unicode_ci;


#------------------------------------------------------------
# Table: Proposition
#------------------------------------------------------------

CREATE TABLE Proposition(
        id_proposition Int  Auto_increment  NOT NULL ,
        proposition    Varchar (200) NOT NULL ,
        reponse        TinyINT NOT NULL ,
        id_question    Int NOT NULL
	,CONSTRAINT Proposition_PK PRIMARY KEY (id_proposition)

	,CONSTRAINT Proposition_Question_FK FOREIGN KEY (id_question) REFERENCES Question(id_question)
)ENGINE=InnoDB CHARSET=utf8 COLLATE utf8_unicode_ci;


#------------------------------------------------------------
# Table: Partie_Question
#------------------------------------------------------------

CREATE TABLE Partie_Question(
        id_question Int NOT NULL ,
        id_partie   Int NOT NULL
	,CONSTRAINT Partie_Question_PK PRIMARY KEY (id_question,id_partie)

	,CONSTRAINT Partie_Question_Question_FK FOREIGN KEY (id_question) REFERENCES Question(id_question)
	,CONSTRAINT Partie_Question_Partie0_FK FOREIGN KEY (id_partie) REFERENCES Partie(id_partie)
)ENGINE=InnoDB CHARSET=utf8 COLLATE utf8_unicode_ci;


#------------------------------------------------------------
# Table: Joue
#------------------------------------------------------------

CREATE TABLE Joue(
        id_partie Int NOT NULL ,
        id_login  Int NOT NULL
	,CONSTRAINT Joue_PK PRIMARY KEY (id_partie,id_login)

	,CONSTRAINT Joue_Partie_FK FOREIGN KEY (id_partie) REFERENCES Partie(id_partie)
	,CONSTRAINT Joue_Joueur0_FK FOREIGN KEY (id_login) REFERENCES Joueur(id_login)
)ENGINE=InnoDB CHARSET=utf8 COLLATE utf8_unicode_ci;

