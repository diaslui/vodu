#ifndef SETTINGS_H_
#define SETTINGS_H_

#pragma once

#include "rtc/rtc.hpp"
#include <string>

namespace settings {
    extern const std::string SYSTEM_NAME;
    extern std::string iceServersAddrs[3];
    extern std::string wsServersAddrs[3];
    extern rtc::Configuration rtcConfig;
    extern bool usesHTTPS;

 //   std::string server;


    int load();
}


#endif
