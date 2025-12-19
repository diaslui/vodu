#ifndef SETTINGS_H_
#define SETTINGS_H_

#pragma once

#include "rtc/rtc.hpp"
#include <string>

struct pcdefs {
    std::string hostname;
    std::string username;
    std::string systemName;
};

struct programdefs{
    std::string instanceId;
};

namespace settings {
    const pcdefs& thisPc();
    const programdefs& program();
    extern std::string iceServersAddrs[3];
    extern std::string wsServersAddrs[3];
    extern rtc::Configuration rtcConfig;
    extern bool usesHTTPS;

 //   std::string server;


    int load();
}


#endif
