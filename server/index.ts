import http from 'http';
import { server as WebSocketServer, request as WebSocketRequest, connection as WebSocketConnection, IMessage } from 'websocket';

interface Clients {
    [id: string]: WebSocketConnection;
}

const clients: Clients = {};

const httpServer = http.createServer((req, res) => {
    console.log(`${req.method?.toUpperCase()} ${req.url}`);

    const respond = (code: number, data: string, contentType = 'text/plain') => {
        res.writeHead(code, {
            'Content-Type': contentType,
            'Access-Control-Allow-Origin': '*',
        });
        res.end(data);
    };

    respond(404, 'Not Found');
});

const wsServer = new WebSocketServer({ httpServer });
wsServer.on('request', (req: WebSocketRequest) => {
    console.log(`WS  ${req.resource}`);

    const { path } = req.resourceURL;
    const splitted = path.split('/');
    splitted.shift();
    const id = splitted[0];

    const conn = req.accept(null, req.origin);
    conn.on('message', (data: IMessage) => {
        if (data.type === 'utf8') {
            console.log(`Client ${id} << ${data.utf8Data}`);

            const message = JSON.parse(data.utf8Data as string) as { id: string; [key: string]: any };
            const destId = message.id;
            const dest = clients[destId];
            if (dest) {
                message.id = id;
                const msgData = JSON.stringify(message);
                console.log(`Client ${destId} >> ${msgData}`);
                dest.send(msgData);
            } else {
                console.error(`Client ${destId} not found`);
            }
        }
    });
    conn.on('close', () => {
        delete clients[id];
        console.error(`Client ${id} disconnected`);
    });

    clients[id] = conn;
});

const endpoint = process.env.PORT || '8000';
const splitted = endpoint.split(':');
const port = Number(splitted.pop());
const hostname = splitted.join(':') || '127.0.0.1';