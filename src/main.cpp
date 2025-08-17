#include "rtc/rtc.hpp"
#include "settings.h"
#include <iostream>


int main(){
    settings::load();
    std::cout << settings::SYSTEM_NAME;
 
    return 0;
}