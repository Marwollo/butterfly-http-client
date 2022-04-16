# Butterfly HTTP Client
This repository represents a very simple HTTP client based on CURL (wrapped the C-styled library in C++  style to support the latest C++ features and coding conventions), providing an easy to use interface for creating requests and handling responses.

### Features
- Easy to use builder-pattern interface for creating requests.
- Based on well-maintained [open-source-parsers/jsoncpp](https://github.com/open-source-parsers/jsoncpp) library.


The library is still in the state of work in progress.

### Example
Consider the following example in order to use the library. More examples will be available as the library development progresses.

```c++
#include <iostream>
#include <json/json.h>
#include <butterfly/request.h>

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
```