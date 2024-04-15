#include "WordManager.h"

WordManager::WordManager(PasswordFileReader& _passwordFileReader) : _passwordFileReader(_passwordFileReader)
{
}

WordManager::~WordManager()
{
}

void WordManager::getPasswordFromFile()
{
    _password       = _passwordFileReader.getPassword();
    _guessedLetters = std::string(_password.length(), '_');
}

void WordManager::printPassword()
{
    std::cout << "Password: " << _guessedLetters << std::endl;
}

void WordManager::printGuessedLetters()
{
    std::cout << "Guessed letters: " << _guessedLetters << std::endl;
}

void WordManager::guessLetter(const char letter)
{
    for (int i = 0; i < _password.length(); i++)
    {
        if (_password[i] == letter)
        {
            _guessedLetters[i] = letter;
        }
    }
    printGuessedLetters();
}
