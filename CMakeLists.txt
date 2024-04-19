cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project("MyProject")

option(CLANG_TIDY OFF "Enable clang-tidy checks.")
option(ENABLE_VALGRIND ON "Enable Valgrind for tests.")

if(ENABLE_VALGRIND)
    add_compile_definitions(CPPUTEST_MEM_LEAK_DETECTION_DISABLED)
endif()

include_directories("lib/" "./")

add_executable(${PROJECT_NAME}
    "main.cpp"
    "utils/logger/Logger.cpp"
    "app/Application.cpp"
    "app/player/Player.cpp"
    "app/player/PlayerCreator.cpp"
    "app/passwordFileReader/PasswordFileReader.cpp"
    "app/wordManager/WordManager.cpp"
    "app/game/Game.cpp"
    "app/wordManager/WordManager.cpp"
    "app/hangmanDrawer/HangMan.cpp")

if(BUILD_TESTING)
    include(CTest)
    add_subdirectory("lib/cpputest")
    add_subdirectory("tests")
endif()

if(CLANG_TIDY)
    set_target_properties(${PROJECT_NAME} PROPERTIES CXX_CLANG_TIDY "clang-tidy")
endif()