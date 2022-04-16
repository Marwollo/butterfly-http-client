//
// Created by Vuk Markovic on 13.4.22..
//

#ifndef TESTINGCLION_REQUESTABLE_H
#define TESTINGCLION_REQUESTABLE_H

#include <iostream>
#include <unordered_map>
#include <json/json.h>

class Requestable {
protected:
    virtual Requestable & withUrl(const std::string & url) = 0;
    virtual Requestable & withBody(const Json::Value & body) = 0;
    virtual Requestable & withQuery(const std::unordered_map<std::string, std::string> & query) = 0;
    virtual Requestable & withQueryField(const std::string & key, const std::string & value) = 0;
    virtual Requestable & withHeaders(const std::unordered_map<std::string, std::string> & headers) = 0;
    virtual Requestable & withHeaderField(const std::string & key, const std::string & value) = 0;
    virtual const std::unordered_map<std::string, std::string> & getQuery() const = 0;
    virtual const Json::Value & getBody() const = 0;
    virtual const std::unordered_map<std::string, std::string> & getHeaders() const = 0;
    virtual const std::string & getUrl() const = 0;
    virtual std::string send() const = 0;
};


#endif //TESTINGCLION_REQUESTABLE_H
