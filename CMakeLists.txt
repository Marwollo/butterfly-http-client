cmake_minimum_required(VERSION 3.21)
project(ButterflyHTTPClient)

include(FetchContent)

find_package(jsoncpp CONFIG REQUIRED)
find_package(CURL REQUIRED)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)
include_directories("${JSONCPP_INCLUDE_DIRS}")

add_executable(ButterflyHTTPClient main.cpp src/Requestable.h src/impl/Request.cpp src/Request.h src/HttpClient.h src/impl/CurlClient.cpp src/CurlClient.h)

target_link_libraries(ButterflyHTTPClient PRIVATE jsoncpp_object jsoncpp_static JsonCpp::JsonCpp ${CURL_LIBRARIES})