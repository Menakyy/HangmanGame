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
            _player = player;
            std::cout << "Player " << player.getName() << " turn" << std::endl;
            char letter;
            std::cout << "Enter letter: ";
            std::cin >> letter;
            _wordManager.guessLetter(letter);
            setPlayerPoints();
        }
    }
}

void Game::setPlayerPoints()
{
    if (_wordManager.isWordGuessed())
    {
        std::cout << "Player " << _player.getName() << " guessed the word!" << std::endl;
        _player.setScore(Game::POINTS);
    }
}
