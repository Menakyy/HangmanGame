#ifndef APP_WORDMANAGER_WORDMANAGER
#define APP_WORDMANAGER_WORDMANAGER


#include "app/passwordFileReader/PasswordFileReader.h"

#include <iostream>
#include <string>

class WordManager
{
public:
    WordManager(PasswordFileReader& _passwordFileReader);
    ~WordManager();

    void getPasswordFromFile();
    void printPassword();
    void printGuessedLetters();
    void guessLetter(const char letter);

private:
    PasswordFileReader& _passwordFileReader;
    std::string         _password       = "";
    std::string         _guessedLetters = "";
};


#endif /* APP_WORDMANAGER_WORDMANAGER */
