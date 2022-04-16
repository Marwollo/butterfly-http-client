//
// Created by Vuk Markovic on 13.4.22..
//

#ifndef TESTINGCLION_REQUEST_H
#define TESTINGCLION_REQUEST_H

#include <src/Requestable.h>
#include <src/CurlClient.h>
#include <json/json.h>

namespace butterfly {

    class Request : public Requestable {
        std::string url;
        Json::Value body;
        std::unordered_map<std::string, std::string> query;
        std::unordered_map<std::string, std::string> headers;
    public:
        Request &withUrl(const std::string &url) override;

        Request &withBody(const Json::Value &body) override;

        Request &withQuery(const std::unordered_map<std::string, std::string> &query) override;

        Request &withQueryField(const std::string &key, const std::string &value) override;

        Request &withHeaders(const std::unordered_map<std::string, std::string> &headers) override;

        Request &withHeaderField(const std::string &key, const std::string &value) override;

        const std::unordered_map<std::string, std::string> &getQuery() const override;

        const Json::Value &getBody() const override;

        const std::unordered_map<std::string, std::string> &getHeaders() const override;

        const std::string &getUrl() const override;

        std::string send() const override;
    };

}

#endif //TESTINGCLION_REQUEST_H
