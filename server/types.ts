
export interface MessagePayload {
  connType: string;
  msgType: string;
  data: object
}

export interface ControllerConnection {
    instanceId: string;
    socketId: string;
    hostname: string;
}

export interface ClientConnection{
    instanceId: string;
    socketId: string;
    hostname: string;
    username: string;
    controllers: ControllerConnection[];
}