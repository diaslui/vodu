
#include "utils.h"
#include <string>

namespace voduUtils {
    
OsName getOsNameEnum() {
    #ifdef _WIN32
    return OsName::Windows32;
    #elif _WIN64
    return OsName::Windows64;
    #elif __APPLE__ || __MACH__
    return OsName::MacOSX;
    #elif __linux__
    return OsName::Linux;
    #elif __FreeBSD__
    return OsName::FreeBSD;
    #elif __unix || __unix__
    return OsName::Unix;
    #else
    return OsName::Other;
    #endif

}

std::string getOsNameString(){
    #ifdef _WIN32
    return "Win32";
    #elif _WIN64
    return "Win64";
    #elif __APPLE__ || __MACH__
    return "MacOSX";
    #elif __linux__
    return "Linux";
    #elif __FreeBSD__
    return "FreeBSD";
    #elif __unix || __unix__
    return "Unix";
    #else
    return "";
    #endif
}

}