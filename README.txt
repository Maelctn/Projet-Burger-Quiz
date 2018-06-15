########## BASE DE DONNEES : ##########

Aller dans : /Projet-Burger-Quiz\ PHP/sql

Importer dans la BDD le script : BDD.sql
Puis importer le script : RempliBDD.sql



########## APPLICATION QT : ##########

Aller dans : /Projet-Burger-Quiz\ CPP/Interface_Qt 

Vérifier si présence de : QT += widgets (en-dessous de QT += core gui), si non, l'ajouter.
Vérifier si présence de : LIBS += -lmysqlcppconn (en dessous greaterThan(QT_MAJOR_VERSION, 4): QT += widgets), si non, l'ajouter.

Executer la commande : qmake
Puis la commande : make
Lancer l'application : ./Projet_Burger_Quiz
/!\ Si une erreur de compilation apparait, executer un "make clean" puis relancer la compilation /!\


########## APPLICATION PHP : ##########

Aller dans : /Projet-Burger-Quiz\ PHP/php

Dans connexionBDD.php : 
	Dans la variable $myDsn :
		Changer "localhost" par l'adresse de votre base de données (laisser en localhost si vous etes en local) 
		Changer "Projet_Burger_Quiz" par le nom de votre base de données
	Dans la variable $myUserDb :
		Changer 'Projet_Burger_Quiz' par le login de votre base de données
	Dans la varibale $myPwdBd :
		Changer 'mael' par le mot de passe de votre base de données 



########## DOC : ##########

Doc PHP/JS : /Projet-Burger-Quiz PHP/doc/html : ouvrir index.html
Doc CPP/Qt : /Projet-Burger-Quiz CPP/Doc_Qt/html : ouvrir index.html
