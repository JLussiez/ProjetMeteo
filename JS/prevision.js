//connexion du websocket
const ws = new WebSocket("ws://192.168.64.155:16050");
//récéption des messages du serveur
ws.addEventListener("message"), async(event, isBinary) => {
    message = String(event.data);
    console.log(event.data);
    
    if (message.split(';')[0] == '') {
        var Json = message.split(';')[1];
        //découpage du dossier json
        var data = JSON.parse(Json);
        //récupération des champs du tableau
        let logo = document.getElementById('logo');
        let prevision = document.getElementById('prevision');
        let dureee = document.getElementById('duree');
        let date = document.getElementById('date');

        logo.innerHTML = data[i]
        prevision.innerHTML = data[i]
        dureee.innerHTML = data[i]
        date.innerHTML = data[i]
    }
}