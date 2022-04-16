//
// Created by Vuk Markovic on 13.4.22..
//

#ifndef TESTINGCLION_CURLCLIENT_H
#define TESTINGCLION_CURLCLIENT_H

#include <src/HttpClient.h>
#include <curl/curl.h>
#include <iostream>
#include <unordered_map>
#include <json/json.h>
#include <memory>

class CurlClient : public HttpClient {
private:
    CURL* client;
    struct curl_slist* headers;
    std::string readBuffer;
    std::string query;
    std::string body;
    std::string url;
public:
    CurlClient();
    void setUrl(const std::string & url) override;
    void setBody(const std::string & body) override;
    void setBody(const Json::Value & body) override;
    void setQuery(const std::unordered_map<std::string, std::string> & query) override;
    void setHeaders(const std::unordered_map<std::string, std::string> & headers) override;
    std::string getResponse() override;
    std::string getUrl() override;
    void run() override;
};


#endif //TESTINGCLION_CURLCLIENT_H
