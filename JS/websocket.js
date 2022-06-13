//websocket.js réalisé par Lussiez Julien

// Connexion au serveur Websocket
const ws = new WebSocket("ws://192.168.64.155:16050");

ws.onopen = function () {
    console.log("WebSocket connecté");
}

// récupération du fichier JSON, puis on effectue un PARSE pour récupèrer les données
ws.onmessage = function(event) {
    console.log(event.data);

    var msg = JSON.parse(event.data);

    var pression = msg.pression;
    var temperature = msg.temperature;
    var hydrometrie = msg.hydrometrie;
    var journuit = msg.journuit;
    var pluie = msg.pluie;
    var quantitePluie = msg.quantitepluie;
 
    if(journuit == 1){
        var JourNuitt = "Jour";
    }else{
        var JourNuitt = "Nuit";
    }

    if(pluie == 1){
        var Pleut = "Il ne pleut pas";
    }else{
        var Pleut = "Il pleut"
    }

// affichage des données
    document.getElementById("Pression").innerHTML = pression;
    document.getElementById("Temperature").innerHTML = parseFloat( temperature ).toFixed( 2 );
    document.getElementById("Humidite").innerHTML = parseFloat( hydrometrie ).toFixed( 2 );
    document.getElementById("DayTime").innerHTML = JourNuitt;
    document.getElementById("RainAmmount").innerHTML = quantitePluie;
    document.getElementById("Pluie").innerHTML = Pleut;
  };