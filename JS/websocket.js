// Crée une connexion WebSocket
const socket = new WebSocket('ws://192.168.64.222');

// La connexion est ouverte
socket.addEventListener('open', (event) => {
  socket.send('Coucou serveur !');
});