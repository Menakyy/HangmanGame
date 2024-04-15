#include "PasswordFileReader.h"

#include "utils/logger/Logger.h"

#include <algorithm>
#include <fstream>
#include <iostream>

PasswordFileReader::PasswordFileReader(std::string passwordFile) : _passwordFile(passwordFile)
{
    srand(time(nullptr));
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
    std::ifstream file(_passwordFile);
    if (file.is_open())
    {
        _fileStatus = FileStatus::FILE_OK;
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
        _fileStatus = FileStatus::FILE_ERROR;
    }

    Logger::info("Number of lines in file: %d", _fileLines);
}

void PasswordFileReader::randomLineAndGetPassword()
{
    while (true)
    {
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
    std::ifstream file(_passwordFile);
    if (file.is_open())
    {
        _fileStatus = FileStatus::FILE_OK;
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
        file.close();
    }
    else
    {
        Logger::error("Unable to open file");
        _fileStatus = FileStatus::FILE_ERROR;
    }
}
