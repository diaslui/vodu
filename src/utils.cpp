#include <iostream>

#include "utils.h"
#include <string>


#include <algorithm>
#include <memory>
#include <random>

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


std::string randomId(size_t length) {
	using std::chrono::high_resolution_clock;
	static thread_local std::mt19937 rng(
	    static_cast<unsigned int>(high_resolution_clock::now().time_since_epoch().count()));
	static const std::string characters(
	    "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	std::string id(length, '0');
	std::uniform_int_distribution<int> uniform(0, int(characters.size() - 1));
	std::generate(id.begin(), id.end(), [&]() { return characters.at(uniform(rng)); });
	return id;
}

}