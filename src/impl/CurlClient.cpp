//
// Created by Vuk Markovic on 13.4.22..
//

#include "src/CurlClient.h"

CurlClient::CurlClient() : headers(nullptr) {
    this->client = curl_easy_init();
    curl_easy_setopt(this->client, CURLOPT_WRITEFUNCTION,
                     +[](void* contents, size_t size, size_t nmemb, void * userp)
                     {
                         ((std::string*)userp)->append((char*)contents, size * nmemb);
                         return size * nmemb;
                     });
    curl_easy_setopt(this->client, CURLOPT_WRITEDATA, this->readBuffer.c_str());
}

void CurlClient::setUrl(const std::string & url) {
    this->url = url;
}

void CurlClient::run() {
    curl_easy_setopt(this->client, CURLOPT_HTTPHEADER, this->headers);
    curl_easy_setopt(this->client, CURLOPT_POSTFIELDS, this->body.c_str());
    curl_easy_setopt(this->client, CURLOPT_POSTFIELDSIZE, this->body.length());
    curl_easy_setopt(this->client, CURLOPT_URL, this->getUrl().c_str());
    auto res = curl_easy_perform(this->client);
    if (res) {
        std::cout << "An error has occurred." << std::endl;
    }
}

std::string CurlClient::getResponse() {
    return this->readBuffer;
}


void CurlClient::setQuery(const std::unordered_map<std::string, std::string> &query) {
    for (const auto & parameter : query) {
        this->query += parameter.first + "=" + parameter.second + "&";
    }
}

void CurlClient::setHeaders(const std::unordered_map<std::string, std::string> &headers) {
    for (const auto & header : headers) {
        std::string headerFormatted = header.first + ": " + header.second;
        curl_slist_append(this->headers, headerFormatted.c_str());
    }
}

void CurlClient::setBody(const std::string &body) {
    this->headers = curl_slist_append(this->headers, "Content-Type: text/plain");
    this->body = body;
}

void CurlClient::setBody(const Json::Value &body) {
    this->headers = curl_slist_append(this->headers, "Content-Type: application/json");
    Json::FastWriter streamWriterBuilder;
    this->body = streamWriterBuilder.write(body);
}

std::string CurlClient::getUrl() {
    return this->url + "?" + this->query;
}

