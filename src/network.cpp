#include "network.h"
#include <nlohmann/json.hpp>
#include "settings.h"
#include "network.h"

Network::Network()
    : wsClient(std::make_shared<rtc::WebSocket>()),
      wsPromise(std::make_shared<std::promise<void>>()) {
        this->wsHandler();
      }

std::future<void> Network::wsConnect() {
    auto future = wsPromise->get_future();
    wsClient->open(settings::wsServersAddrs[0]);
    return future;
}

void Network::wsHandler() {
    wsClient->onOpen([this]() {
        std::cout << "WS:: connected" << std::endl;
        wsPromise->set_value();
    });

    wsClient->onError([this](std::string s) {
        std::cerr << "\n WS:: Error: " << s << "\n";
        wsPromise->set_exception(std::make_exception_ptr(std::runtime_error(s)));
    });

    wsClient->onClosed([]() {
        std::cout << "WS:: Conn Closed\n";
    });

    auto config = settings::rtcConfig;

    wsClient->onMessage([this, config](auto data) {
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
