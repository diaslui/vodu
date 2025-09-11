import WebSocket, { WebSocketServer } from "ws";
import type { MessagePayload } from "./types";
import { clientMsgHandler } from "./client";
import { controllerMsgHandler } from "./controller";
import { solveCloseConnection } from "./core";
import { log } from "./utils";

const PORT = 8000;

const wss = new WebSocketServer({ port: PORT }).on("listening", () => {
    log(`WebSocket server started on ws://localhost:${PORT}`, "info", "onListening");
});

wss.on("connection", (ws: WebSocket) => {
  console.log("new client connected");

  ws.on("message", (message: string) => {
    const payload: MessagePayload = JSON.parse(message.toString());
    console.log("received:", payload);
    (payload.data as { [key: string]: any }).socketId =
      ws._socket?.remoteAddress || null;
    if (payload.connType == "voduclient") {
      console.log("rcv msg from client");
      clientMsgHandler(payload.msgType, payload.data);
    } else if (payload.connType == "voducontroller") {
      console.log("rcv msg from controller");
      controllerMsgHandler(payload.msgType, payload.data);
    }
  });

  ws.on("close", () => {
    console.log("client disconnected.");
    return solveCloseConnection(ws._socket?.remoteAddress || "");
  });

  ws.on("error", (error: Error) => {
    console.error("ws error:", error);
  });
});
