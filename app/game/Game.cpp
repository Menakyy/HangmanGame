#include "Game.h"

#include <limits>

Game::Game(PlayerCreator& playerCreator, WordManager& wordManager)
    : _playerCreator(playerCreator),
      _wordManager(wordManager)
{
}

Game::~Game()
{
}

void Game::playGame()
{
    while (true)
    {
        for (auto& player : _playerCreator.getPlayers())
        {
            _player = &player;
            _wordManager.printGuessedLetters();
            guessLetterByPlayer();
            isGuessed = isWordGuessed();
            if (isGuessed)
            {
                endRound();
            }

            if (_hangmanDrawer.isFullyDrawn())
            {
                exitGame("Hangman is fully drawn!");
            }

            if (isGuessedLetter)
            {
                _wordManager.printGuessedLetters();
                guessWordByPlayer();
            }
            isGuessed = isWordGuessed();
            if (isGuessed)
            {
                endRound();
            }
        }
    }
}

void Game::endRound()
{
    setPlayerPoints();
    printPlayerPoints();
    if (isAvailableWordLeft())
    {
        newGame();
    }
    else
    {
        exitGame("No more words left!");
    }
}

void Game::guessLetterByPlayer()
{
    bool isCorrectLetter = false;

    std::cout << " -->> Player " << _player->getName() << " turn <<-- " << std::endl;
    char letter;
    std::cout << "Enter letter: ";

    std::cin >> std::ws;
    std::cin.get(letter);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    letter = static_cast<char>(std::tolower(static_cast<int>(letter)));
    if (isLetter(letter))
    {
        isCorrectLetter = _wordManager.guessLetter(letter);
    }
    else
    {
        std::cout << letter << " - Invalid input. Please enter a letter." << std::endl;
    }
    if (!isCorrectLetter)
    {
        std::cout << "Letter: " << letter << " is not in the word!" << std::endl;
        _hangmanDrawer.fail();
    }

    isGuessedLetter = isCorrectLetter;
}

void Game::guessWordByPlayer()
{
    bool guessWord = wannaGuessWord();
    if (guessWord)
    {
        std::string word;
        std::cout << "Enter word: ";
        std::cin >> word;
        _wordManager.guessWord(word);
        if (_wordManager.getWordStatus() == WordManager::WordStatus::WORD_INCORRECTLY_GUESSED)
        {
            std::cout << "Word: " << word << " is not correct!" << std::endl;
        }
    }
}

bool Game::wannaGuessWord()
{
    char choice;
    std::cout << "Do you want to guess the word? (y/n): ";
    std::cin >> std::ws;
    std::cin.get(choice);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    choice = static_cast<char>(std::tolower(static_cast<int>(choice)));
    if (isLetter(choice))
    {
        return choice == 'y';
    }
    return false;
}

void Game::setPlayerPoints()
{
    std::cout << "Player " << _player->getName() << " guessed the word! "
              << "[" << _wordManager.getPassword() << "]" << std::endl;
    int score = _player->getScore() + Game::POINTS;
    _player->setScore(score);
}

void Game::printPlayerPoints()
{
    for (auto& player : _playerCreator.getPlayers())
    {
        std::cout << "Player " << player.getName() << " points: " << player.getScore() << std::endl;
    }
}

void Game::newGame()
{
    std::cout << "New game!" << std::endl;
    _wordManager.getPasswordFromFile();
    // _wordManager.printPassword();
    _hangmanDrawer.reset();
    isGuessed = false;
    playGame();
}

void Game::exitGame(const std::string& message)
{
    std::cout << message << std::endl;
    std::cout << "Exit game!" << std::endl;
    exit(0);
}
