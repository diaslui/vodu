#include "utils.h"
#include "settings.h"
#include <iostream>

namespace settings {
    const std::string SYSTEM_NAME = voduUtils::getOsNameString();

    int load() {
        if (settings::SYSTEM_NAME == ""){
          //  std::cerr << "no system" << std::endl;
            std::exit(EXIT_FAILURE);
        }
        return 0;
    }

    
}
