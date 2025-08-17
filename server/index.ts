import WebSocket, { WebSocketServer } from 'ws';
const PORT = 8000;

const wss = new WebSocketServer({ port: PORT });

wss.on('connection', (ws: WebSocket) => {
  console.log('new client connected');

  ws.on('message', (message: string) => {
    const incomingMessage = message.toString();
    console.log(`rcv msg: ${incomingMessage}`);
    if (incomingMessage === 'ping') {
      ws.send('pong');
      console.log('pong');
    }
  });

  ws.on('close', () => {
    console.log('client disconnected.');
  });

  ws.on('error', (error: Error) => {
    console.error('ws error:', error);
  });
});