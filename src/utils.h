#ifndef UTILS_H_
#define UTILS_H_

#include <string>
#include <chrono>


#pragma once
namespace voduUtils {
    
enum class OsName {
        Windows32,
        Windows64,
        MacOSX,
        Linux,
        FreeBSD,
        Unix,
        Other
    };

    OsName getOsNameEnum();
    std::string getOsNameString();
    std::string randomId(size_t length);

}

#endif