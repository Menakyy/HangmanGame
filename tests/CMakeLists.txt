cmake_minimum_required(VERSION 3.20)
project("MyProjectTests")

add_executable(${PROJECT_NAME}
    "testAppMain.cpp"
    "appTests/FirstTest.cpp"
    "appTests/PlayerTests.cpp"
    "../app/player/Player.cpp"
    "../app/player/PlayerCreator.cpp")

target_link_libraries(${PROJECT_NAME} PRIVATE "CppUTest")