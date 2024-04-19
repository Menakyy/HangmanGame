cmake_minimum_required(VERSION 3.20)
project("MyProjectTests")
find_program(VALGRIND "valgrind")

set(SRC_FILES
    "../app/player/Player.cpp"
    "../app/player/PlayerCreator.cpp"
    "../app/passwordFileReader/PasswordFileReader.cpp"
    "../utils/logger/Logger.cpp"
    "../app/wordManager/WordManager.cpp"
    "../app/hangmanDrawer/HangMan.cpp"
)

add_executable(${PROJECT_NAME}
    "testAppMain.cpp"
    "appTests/PlayerTests.cpp"
    "appTests/PasswordFileReaderTests.cpp"
    "appTests/WordManagerTests.cpp"
    "appTests/HangManTests.cpp"
    ${SRC_FILES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE "CppUTest")

set(TEST_EXECUTABLE "MyProjectTests")
set(CPPUTEST_ARGS "-o" "junit" "-v")

add_test(
    NAME "${PROJECT_NAME}"
    COMMAND "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TEST_EXECUTABLE}"
    ${CPPUTEST_ARGS})

if(ENABLE_VALGRIND AND VALGRIND)
    set(MEMORYCHECK_COMMAND_OPTIONS "--leak-check=full --show-leak-kinds=all")
    add_test(
        NAME "${PROJECT_NAME}Valgrind"
        COMMAND valgrind
        --vgdb=no
        --leak-check=full
        --show-leak-kinds=all
        --error-exitcode=1
        --track-origins=yes
        --trace-children=yes
        --verbose
        "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TEST_EXECUTABLE}"
        ${CPPUTEST_ARGS}
    )
else()
    message(SEND_ERROR "Valgrind not found. Please install Valgrind.")
endif()