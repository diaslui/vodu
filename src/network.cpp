#include "network.h"
#include <nlohmann/json.hpp>
#include "settings.h"
#include "network.h"

Network::Network()
    : wsClient(std::make_shared<rtc::WebSocket>()),
      wsPromise(std::make_shared<std::promise<void>>()) {
        this->wsHandler();
      }

void Network::wsConnect() {
    wsClient->open(settings::wsServersAddrs[0]);
    this->wsPromise->get_future().wait();

}

void Network::wsHandler() {
    wsClient->onOpen([this]() {
        std::cout << "WS:: connected" << std::endl;
        wsClient->send("ping");
        this->wsPromise->set_value();
    });

    wsClient->onError([this](std::string s) {
        std::cerr << "\n WS:: Error: " << s << "\n";
        this->wsPromise->set_exception(std::make_exception_ptr(std::runtime_error(s)));
    });

    wsClient->onClosed([]() {
        std::cout << "WS:: Conn Closed\n";
    });


    wsClient->onMessage([this](auto data) {
        if (!std::holds_alternative<std::string>(data)) {
            return;
        }

        nlohmann::json message = nlohmann::json::parse(std::get<std::string>(data));

        auto it = message.find("id");
        if (it == message.end()) return;
        auto id = it->get<std::string>();

        it = message.find("type");
        if (it == message.end()) return;
        auto type = it->get<std::string>();

   
    });
}
