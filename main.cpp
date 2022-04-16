#include <iostream>
#include <json/json.h>
#include <src/Request.h>

int main() {
    Json::Value body;
    body["title"] = "Foo";
    body["body"] = "Bar";
    body["userId"] = 123;
    butterfly::Request request = butterfly::Request()
                        .withUrl("https://jsonplaceholder.typicode.com/posts")
                        .withBody(body);
    std::cout << request.send();
    return 0;
}
