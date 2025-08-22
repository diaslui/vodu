
#include "settings.h"
#include <iostream>
#include "network.h"
#include "platform/platformApi.h"


int main(){

    settings::load();

    std::cout << platformApi::getUsername();
    std::cout << platformApi::getHostname();

    std::cout << settings::SYSTEM_NAME;

    Network thisNetwork;



    thisNetwork.wsConnect();

    while (true)
    {
        /* code */
    }
    
    

    return 0;


}