#include "Application.h"

Application::Application()
{
}

Application::~Application()
{
}

void Application::run()
{
    // _playerCreator.createPlayers();
    for (int i = 0; i < 3; i++)
    {
        _passwordFileReader.drawPassword();
    }
}
