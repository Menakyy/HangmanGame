#include "Application.h"

Application::Application() : _playerCreator(), _passwordFileReader(), _wordManager(_passwordFileReader)
{
}

Application::~Application()
{
}

void Application::run()
{
    _playerCreator.createPlayers();
    _passwordFileReader.drawPassword();
    _wordManager.getPasswordFromFile();
    _wordManager.printPassword();

    while (true)
    {
        char letter;
        std::cout << "Enter letter: ";
        std::cin >> letter;

        _wordManager.guessLetter(letter);
    }
}
