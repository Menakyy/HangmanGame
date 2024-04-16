#include "app/Application.h"
#include "utils/logger/Logger.h"

#include <iostream>

using namespace std;

int main()
{
    Logger::initialize("log.txt", Logger::LogLevel::info);
    Logger::info("Welcome in Hangman Game!");

    Application app;
    app.init();

    Logger::shutdown();

    return 0;
}
