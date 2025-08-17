
#include "settings.h"
#include <iostream>
#include "network.h"


int main(){

    settings::load();

    std::cout << settings::SYSTEM_NAME;

    Network thisNetwork;

    thisNetwork.wsConnect();

    while (true)
    {
        /* code */
    }
    
    

    return 0;


}