#include "PasswordFileReader.h"

#include "utils/logger/Logger.h"

#include <algorithm>
#include <fstream>
#include <iostream>

PasswordFileReader::PasswordFileReader()
{
    calculateNumberOfLinesInFile();
}

PasswordFileReader::~PasswordFileReader()
{
}

void PasswordFileReader::drawPassword()
{
    randomLineAndGetPassword();
}

void PasswordFileReader::calculateNumberOfLinesInFile()
{
    std::ifstream file("app/passwordFileReader/passwords.txt");
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            _fileLines++;
        }
        file.close();
    }
    else
    {
        Logger::error("Unable to open file");
    }

    Logger::info("Number of lines in file: %d", _fileLines);
}

void PasswordFileReader::randomLineAndGetPassword()
{
    while (true)
    {
        srand(time(nullptr));
        int randomLine = (rand() % _fileLines) + 1;
        Logger::info("Random line: %d", randomLine);
        bool passwordStatus = checkForPassword(randomLine);
        if (passwordStatus)
        {
            getPasswordFromFile(randomLine);
            break;
        }
    }
}

bool PasswordFileReader::checkForPassword(int password)
{
    auto it = std::find(_passwords.begin(), _passwords.end(), password);
    if (it == _passwords.end())
    {
        _passwords.push_back(password);
        return true;
    }
    return false;
}

void PasswordFileReader::getPasswordFromFile(int drawnLine)
{
    std::ifstream file("app/passwordFileReader/passwords.txt");
    if (file.is_open())
    {
        std::string line;
        int         currentLine = 0;

        while (std::getline(file, line))
        {
            currentLine++;
            if (currentLine == drawnLine)
            {
                _password = line;
                Logger::info("Password: %s", _password.c_str());
                break;
            }
        }
        {
            _fileLines++;
        }
        file.close();
    }
    else
    {
        Logger::error("Unable to open file");
    }
}
