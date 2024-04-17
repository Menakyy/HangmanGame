#ifndef APP_WORDMANAGER_WORDMANAGER
#define APP_WORDMANAGER_WORDMANAGER


#include "app/passwordFileReader/PasswordFileReader.h"

#include <iostream>
#include <string>

class WordManager
{
public:
    enum WordStatus
    {
        WORD_NOT_GUESSED,
        WORD_CORRECTLY_GUESSED,
        WORD_INCORRECTLY_GUESSED,
    } _wordStatus = WORD_NOT_GUESSED;

    WordManager(PasswordFileReader& _passwordFileReader);
    ~WordManager();

    void getPasswordFromFile();
    void printPassword();
    void printGuessedLetters();
    bool guessLetter(const char letter);
    void guessWord(const std::string& word);

    WordStatus getWordStatus() const { return _wordStatus; }

    void setPassword(const std::string& password) { _password = password; }

    std::string getPassword() const { return _password; }

    std::string getGuessedLetters() const { return _guessedLetters; }

    void generateGuessedLetters();

    bool isWordGuessed() const { return _password == _guessedLetters; }

private:
    PasswordFileReader& _passwordFileReader;
    std::string         _password       = "";
    std::string         _guessedLetters = "";
};


#endif /* APP_WORDMANAGER_WORDMANAGER */
