//
// Created by Vuk Markovic on 13.4.22..
//

#ifndef TESTINGCLION_HTTPCLIENT_H
#define TESTINGCLION_HTTPCLIENT_H

#include <iostream>
#include <json/json.h>
#include <unordered_map>

class HttpClient {
protected:
    virtual void setUrl(const std::string & url) = 0;
    virtual void setBody(const Json::Value & body) = 0;
    virtual void setBody(const std::string & body) = 0;
    virtual void setQuery(const std::unordered_map<std::string, std::string> & query) = 0;
    virtual void setHeaders(const std::unordered_map<std::string, std::string> & headers) = 0;
    virtual std::string getResponse() = 0;
    virtual std::string getUrl() = 0;
    virtual void run() = 0;
};

#endif //TESTINGCLION_HTTPCLIENT_H
