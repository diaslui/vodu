import { clientsConnections, removeConnection } from "./storage";

export const solveCloseConnection = (socketId: string) => {

    const clientConnection = clientsConnections.get(socketId);
    if (clientConnection) {
        removeConnection(clientConnection);
        return true;
    }

    const controllerConnection = clientsConnections.get(socketId);
    if (controllerConnection) {
        removeConnection(controllerConnection);
        return true;
    }

    return false;


};
