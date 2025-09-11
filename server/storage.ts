import type {ClientConnection} from "./types"
export const clientsConnections = new Map<string, ClientConnection>();// yes is it a fuckin memory storage >://

export const addConnection = (clientConnection: ClientConnection): boolean => {
    clientsConnections.set(
        clientConnection.instanceId,
        clientConnection
    );
    return true;
}

export const removeConnection = (clientConnection: ClientConnection): boolean => {
    clientsConnections.delete(clientConnection.instanceId);
    return true;
}