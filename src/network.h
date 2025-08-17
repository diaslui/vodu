#pragma once

#ifndef NETWORK_H_
#define NETWORK_H_


#include "rtc/rtc.hpp"
#include <nlohmann/json.hpp>
#include "settings.h"
#include <iostream>

using std::shared_ptr;
using std::weak_ptr;
template <class T> weak_ptr<T> make_weak_ptr(shared_ptr<T> ptr) { return ptr; }

extern std::unordered_map<std::string, shared_ptr<rtc::PeerConnection>> peerConnectionMap;
extern std::unordered_map<std::string, shared_ptr<rtc::DataChannel>> dataChannelMap;

extern shared_ptr<rtc::PeerConnection> createPeerConnection(const rtc::Configuration &rtcConfig,
													 weak_ptr<rtc::WebSocket> wws, std::string id);
extern std::string randomId(size_t length);


class Network {
public:
    Network();

    std::future<void> wsConnect();

    

private:
    void wsHandler();
    std::shared_ptr<rtc::WebSocket> wsClient;
    std::shared_ptr<std::promise<void>> wsPromise;
};

#endif