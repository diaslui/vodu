import {addConnection} from "./storage"


export const clientMsgHandler = (msgType: string, data: object) => {

    switch (msgType){

        case "whoami":
            addConnection(
              //  data.instanceId,
                data.socketId,
                data.hostname,
                data.username
            );

        break;





    }

};
