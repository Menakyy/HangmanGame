#include "Game.h"

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
            bool isGuessed = isWordGuessed();
            if (isGuessed)
            {
                setPlayerPoints();
                printPlayerPoints();
                newGame();
            }
        }
    }
}

void Game::guessLetterByPlayer()
{
    std::cout << " -->> Player " << _player->getName() << " turn <<-- " << std::endl;
    char letter;
    std::cout << "Enter letter: ";
    std::cin >> letter;
    bool isCorrectLetter = _wordManager.guessLetter(letter);
    if (!isCorrectLetter)
    {
        std::cout << "Letter is not in the word!" << std::endl;
        _hangmanDrawer.fail();
    }
}

void Game::setPlayerPoints()
{
    std::cout << "Player " << _player->getName() << " guessed the word!" << std::endl;
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
    _wordManager.printPassword();
    _hangmanDrawer.reset();
}
