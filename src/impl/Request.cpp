//
// Created by Vuk Markovic on 13.4.22..
//

#include "src/Request.h"

using namespace butterfly;
/*
 * Requestable
 */
Request & Request::withUrl(const std::string & url) {
    this->url = url;
    return *this;
}

const std::string & Request::getUrl() const {
    return this->url;
}

std::string Request::send() const {
    CurlClient client;
    client.setUrl(this->getUrl());
    client.setBody(this->getBody());
    client.run();
    return client.getResponse();
}


Request & Request::withBody(const Json::Value & body) {
    this->body = body;
    return *this;
}

Request & Request::withQuery(const std::unordered_map<std::string, std::string> &query) {
    this->query = query;
    return *this;
}

Request & Request::withQueryField(const std::string &key, const std::string &value) {
    this->query[key] = value;
    return *this;
}

Request & Request::withHeaders(const std::unordered_map<std::string, std::string> &headers) {
    this->headers = headers;
    return *this;
}

Request & Request::withHeaderField(const std::string &key, const std::string &value) {
    this->headers[key] = value;
    return *this;
}

const std::unordered_map<std::string, std::string> &Request::getQuery() const {
    return this->query;
}

const Json::Value & Request::getBody() const {
    return this->body;
}

const std::unordered_map<std::string, std::string> &Request::getHeaders() const {
    return this->headers;
}


