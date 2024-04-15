cmake_minimum_required(VERSION 3.20)
project("MyProjectTests")

set(SRC_FILES
    "../app/player/Player.cpp"
    "../app/player/PlayerCreator.cpp"
    "../app/passwordFileReader/PasswordFileReader.cpp"
    "../utils/logger/Logger.cpp"
)

add_executable(${PROJECT_NAME}
    "testAppMain.cpp"
    "appTests/FirstTest.cpp"
    "appTests/PlayerTests.cpp"
    "appTests/PasswordFileReaderTests.cpp"
    ${SRC_FILES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE "CppUTest")