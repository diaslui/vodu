
#include "settings.h"
#include <iostream>
#include "network.h"


int main(){

   settings::load();

    std::cout << settings::SYSTEM_NAME;

    Network thisNetwork;

    auto futureConn = thisNetwork.wsConnect();
    futureConn.wait();

    

    return 0;


}