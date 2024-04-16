#include "Application.h"

Application::Application()
    : _playerCreator(),
      _passwordFileReader(),
      _wordManager(_passwordFileReader),
      _game(_playerCreator, _wordManager)
{
}

Application::~Application()
{
}

void Application::init()
{
    _playerCreator.createPlayers();
    _passwordFileReader.drawPassword();
    _wordManager.getPasswordFromFile();
    _wordManager.printPassword();

    run();
}

void Application::run()
{
    _game.playGame();
}
