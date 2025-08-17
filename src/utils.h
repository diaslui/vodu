#ifndef UTILS_H_
#define UTILS_H_

#include <string>

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

}

#endif