#include "CppUTest/TestHarness.h"
#include "app/passwordFileReader/PasswordFileReader.h"
#include "app/wordManager/WordManager.h"

#include <string>

TEST_GROUP(WordManagerTestsGroup)
{
    WordManager*        wordManager        = nullptr;
    PasswordFileReader* passwordFileReader = nullptr;

    void setup()
    {
        passwordFileReader = new PasswordFileReader();
        wordManager        = new WordManager(*passwordFileReader);
    }

    void teardown()
    {
        delete wordManager;
        delete passwordFileReader;
    }
};

TEST(WordManagerTestsGroup, InitTest)
{
    CHECK_EQUAL(WordManager::WordStatus::WORD_NOT_GUESSED, wordManager->getWordStatus());
    CHECK_EQUAL("", wordManager->getPassword());
    CHECK_EQUAL("", wordManager->getGuessedLetters());
}

TEST(WordManagerTestsGroup, GuessPasswordTest)
{
    std::string password       = "password";
    std::string guessedLetters = std::string(password.length(), '_');

    wordManager->setPassword(password);
    wordManager->generateGuessedLetters();
    CHECK_EQUAL(password, wordManager->getPassword());
    CHECK_EQUAL(guessedLetters, wordManager->getGuessedLetters());

    // Guessing the word
    wordManager->guessWord(password);
    CHECK_EQUAL(WordManager::WordStatus::WORD_CORRECTLY_GUESSED, wordManager->getWordStatus());
    CHECK_EQUAL(password, wordManager->getGuessedLetters());

    password       = "longpassword";
    guessedLetters = std::string(password.length(), '_');

    wordManager->setPassword(password);
    wordManager->generateGuessedLetters();
    CHECK_EQUAL(password, wordManager->getPassword());
    CHECK_EQUAL(guessedLetters, wordManager->getGuessedLetters());

    // Trying to guess the word
    wordManager->guessWord("shortpassword");
    CHECK_EQUAL(WordManager::WordStatus::WORD_INCORRECTLY_GUESSED, wordManager->getWordStatus());
    CHECK_EQUAL(guessedLetters, wordManager->getGuessedLetters());

    // Guessing the word
    wordManager->guessWord("longpassword");
    CHECK_EQUAL(WordManager::WordStatus::WORD_CORRECTLY_GUESSED, wordManager->getWordStatus());
    CHECK_EQUAL(password, wordManager->getGuessedLetters());
}

TEST(WordManagerTestsGroup, GuessLetterTest)
{
    std::string password       = "password";
    std::string guessedLetters = std::string(password.length(), '_');

    wordManager->setPassword(password);
    wordManager->generateGuessedLetters();
    CHECK_EQUAL(password, wordManager->getPassword());
    CHECK_EQUAL(guessedLetters, wordManager->getGuessedLetters());

    // Guessing the letter
    wordManager->guessLetter('p');
    CHECK_EQUAL("p_______", wordManager->getGuessedLetters());

    wordManager->guessLetter('d');
    CHECK_EQUAL("p______d", wordManager->getGuessedLetters());

    wordManager->guessLetter('s');
    CHECK_EQUAL("p_ss___d", wordManager->getGuessedLetters());

    wordManager->guessWord(password);
    CHECK_EQUAL(WordManager::WordStatus::WORD_CORRECTLY_GUESSED, wordManager->getWordStatus());
    CHECK_EQUAL(password, wordManager->getGuessedLetters());
}
