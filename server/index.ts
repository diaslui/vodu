import WebSocket, { WebSocketServer } from "ws";
import type { MessagePayload } from "./types";

const PORT = 8000;

const wss = new WebSocketServer({ port: PORT });

const voduparser = () => {};

wss.on("connection", (ws: WebSocket) => {
  console.log("new client connected");

  ws.on("message", (message: string) => {
    const payload: MessagePayload = JSON.parse(message.toString());
    console.log("received:", payload);
    if (payload.connType == "voduclient") {
      console.log("rcv msg from client");
      console.log(` msgData :${payload.data}`);
    }
  });

  ws.on("close", () => {
    console.log("client disconnected.");
  });

  ws.on("error", (error: Error) => {
    console.error("ws error:", error);
  });
});
