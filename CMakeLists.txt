cmake_minimum_required(VERSION 3.11)
project(JsonParse LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json)
