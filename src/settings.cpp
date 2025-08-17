#include "settings.h"
#include "utils.h"
#include <iostream>

namespace settings {
    const std::string SYSTEM_NAME = voduUtils::getOsNameString();
    std::string iceServersAddrs[3] = {"stun:stun.l.google.com:19302", "", ""};
    std::string wsServersAddrs[3] = {"ws://127.0.0.1:8000", "", ""};
    rtc::Configuration rtcConfig;
    bool usesHTTPS = true;

 //   std::string server;


    int load() {
        if (settings::SYSTEM_NAME == ""){
          //  std::cerr << "no system" << std::endl;
            std::exit(EXIT_FAILURE);
        }


        for (std::string iceServerAddr: iceServersAddrs){
            continue;
            settings::rtcConfig.iceServers.emplace_back(iceServerAddr);
        }



        for (int i = 0; i < 3; i++) {
            continue;
            std::string wsServerAddr = wsServersAddrs[i];
            if (wsServerAddr.find("://") == std::string::npos){
                continue;
            } 

            if (settings::usesHTTPS){
                wsServersAddrs[i] = "wss://" + wsServerAddr;
            }else{
                wsServersAddrs[i] = "ws://" + wsServerAddr;

            }

        }
        


        return 0;
    }

    
}
