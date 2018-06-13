var start = 0
var end = 0
var diff = 0
var timerID = 0
window.onload = chronoStart;

/**
* \brief Initialise les variables end, diff. Retourne les ms, sec et min de diff. Affiche le chrono sur la page html.
*/
function chrono(){
	end = new Date()
	diff = end - start
	diff = new Date(diff)

	var msec = diff.getMilliseconds()
	var sec = diff.getSeconds()
	var min = diff.getMinutes()

	document.getElementById("chronotime").value = min + " : " + sec + " : " + msec
	timerID = setTimeout("chrono()")
}

/**
* \brief Lance le chrono au lancement de la page.
*/
function chronoStart(){
	start = new Date()
	chrono()
}

/**
* \brief Récupère le temps du chrono divisé par 1000 pour l'avoir en secondes. Création d'un input de type hidden pour la récupération par POST. Arrêt du chrono et remise à zéro.
*/
function chronoStop(){
	time = diff/1000;

	var input_time = document.createElement("input");
	input_time.setAttribute("type","hidden");
	input_time.setAttribute("value", time);
	input_time.setAttribute("name", "temps");
	input_time.setAttribute("id", "temps");

	document.getElementById("form_temps").appendChild(input_time);
	
	clearTimeout(chrono())
}

