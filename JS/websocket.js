const ws = new WebSocket("ws://192.168.64.155:16050");

ws.onopen = function () {
    console.log("WebSocket connecté");
}

ws.onmessage = function(event) {
    console.log(event.data);

    var msg = JSON.parse(event.data);

    var pression = msg.pression;
    var temperature = msg.temperature;
    var hydrometrie = msg.hydrometrie;
    var journuit = msg.journuit;
    var pluie = msg.pluie;
    var quantitePluie = msg.quantitepluie;
    
    document.getElementById("Pression").innerHTML = pression;
    document.getElementById("Temperature").innerHTML = temperature;
    document.getElementById("Humidite").innerHTML = hydrometrie;
    document.getElementById("DayTime").innerHTML = journuit;
    document.getElementById("Pluie").innerHTML = pluie;
    document.getElementById("RainAmmount").innerHTML = quantitePluie;
  };