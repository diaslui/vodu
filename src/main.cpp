#include "rtc/rtc.hpp"
#include "settings.h"
#include <iostream>

using std::shared_ptr;
using std::weak_ptr;
template <class T> weak_ptr<T> make_weak_ptr(shared_ptr<T> ptr) { return ptr; }


void setup(){

    auto ws = std::make_shared<rtc::WebSocket>();

	std::promise<void> wsPromise;
	auto wsFuture = wsPromise.get_future();
 
	ws->onOpen([&wsPromise]() {
		std::cout << "WS:: connected" << std::endl;
		wsPromise.set_value();
	});

    ws->onError([&wsPromise](std::string s){
           std::cerr << "\n Ws:: Error \n"; 
          wsPromise.set_exception(std::make_exception_ptr(std::runtime_error(s)));
        });

    ws->onClosed([](){
        std::cout << "Ws:: Conn Closed";
        });

    auto config = settings::rtcConfig;
    ws-> onMessage([&config, wws = make_weak_ptr(ws)](auto data){

        std::cout << "new message";

    });

    ws->open(settings::wsServersAddrs[0]);
    
    wsFuture.get();

    

}



int main(){
    settings::load();
    std::cout << settings::SYSTEM_NAME;

    setup();


    return 0;
}