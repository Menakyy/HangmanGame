#include "WordManager.h"

WordManager::WordManager(PasswordFileReader& _passwordFileReader) : _passwordFileReader(_passwordFileReader)
{
}

WordManager::~WordManager()
{
}

void WordManager::getPasswordFromFile()
{
    _passwordFileReader.drawPassword();
    _password = _passwordFileReader.getPassword();
    setPassword(_password);
    generateGuessedLetters();
}

void WordManager::printPassword()
{
    std::cout << "Password: " << _password << std::endl;
}

void WordManager::printGuessedLetters()
{
    std::cout << "Guessed letters: " << _guessedLetters << std::endl;
}

bool WordManager::guessLetter(const char letter)
{
    bool isLetterInPassword = false;
    for (int i = 0; i < _password.length(); i++)
    {
        if (_password[i] == letter)
        {
            _guessedLetters[i] = letter;
            isLetterInPassword = true;
        }
    }
    // printGuessedLetters();
    return isLetterInPassword;
}

void WordManager::guessWord(const std::string& word)
{
    if (word == _password)
    {
        _wordStatus     = WordStatus::WORD_CORRECTLY_GUESSED;
        _guessedLetters = _password;
        // printGuessedLetters();
        return;
    }
    _wordStatus = WordStatus::WORD_INCORRECTLY_GUESSED;
    // printGuessedLetters();
}

void WordManager::generateGuessedLetters()
{
    _guessedLetters = std::string(_password.length(), '_');
}
