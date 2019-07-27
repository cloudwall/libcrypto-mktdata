// Copyright 2019 Kyle F. Downey
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef CRYPTO_MKTDATA_BITSTAMP_H
#define CRYPTO_MKTDATA_BITSTAMP_H

#include <experimental/optional>

#include <fmt/core.h>
#include <ixwebsocket/IXWebSocket.h>
#include <ixwebsocket/IXSocket.h>
#include <rapidjson/pointer.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/writer.h>
#include <spdlog/spdlog.h>

#include <cloudwall/crypto-mktdata/core.h>

using cloudwall::core::marketdata::Currency;
using cloudwall::core::marketdata::CurrencyPair;
using cloudwall::core::marketdata::OnRawFeedMessageCallback;
using cloudwall::core::marketdata::RawFeedMessage;
using cloudwall::core::marketdata::Subscription;

/// @brief Bitstamp websocket API v2
/// @see https://www.bitstamp.net/websocket/v2/
namespace cloudwall::bitstamp::marketdata {
    std::ostream& operator << (std::ostream& out, const Currency& ccy);
    std::ostream& operator << (std::ostream& out, const CurrencyPair& ccy_pair);

    class RawFeedClient {
    public:
        RawFeedClient(const Subscription& subscription, const OnRawFeedMessageCallback& callback);

        void connect();

        void disconnect();

        ~RawFeedClient();
    private:
        ix::WebSocket *websocket_;
        const OnRawFeedMessageCallback& callback_;
    };
}

#endif //CRYPTO_MKTDATA_BITSTAMP_H
