#include "../platformApi.h"
#include <windows.h>
#include <string>



std::string getprogramid(){
    return std::string(GetCurrentProcessId())
}