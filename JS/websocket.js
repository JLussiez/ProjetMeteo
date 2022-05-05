var ws = new WebSocket("ws://192.168.64.155:16050");
var ws;

function initConnection(){
  if (window.MozWebSocket){
    window.WebSocket = window.MozWebSocket;
  }
  if (!window.WebSocket){
    alert("Votre navigateur ne prend pas en charge les websocket");
    return false;
  }
 
  ws = new WebSocket("ws://192.168.64.155:16050"); 
  return true;
}

ws.onopen = function() { $('#etat').html('Connexion établie'); }

socket.onopen = function (event) {      
    socket.send('{ "type": "texte", "message": "Prêt" }' );     
  };

socket.onmessage=function(event) { 
    var data = JSON.parse(event.data);
    switch(data.type)
    {
       case "text":
           document.getElementById("message").innerHTML = data.message;
           break;
    }
};

socket.onclose = function (event) {      
    alert("Fin de communication");
  };

$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
socket_bind($socket, "192.168.64.155", 16050);

$changed = $mesSockets;
$write = $except = [];
socket_select($changed, $write, $except, null);
$bytes = socket_recv($socket, $buffer, 2048, 0);
socket_close($socket);