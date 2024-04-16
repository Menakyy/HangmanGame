#ifndef APP_APPLICATION
#define APP_APPLICATION


#include "app/game/Game.h"
#include "app/passwordFileReader/PasswordFileReader.h"
#include "app/player/PlayerCreator.h"
#include "app/wordManager/WordManager.h"

class Application
{
public:
    Application();
    ~Application();

    void init();
    void run();

private:
    PlayerCreator      _playerCreator;
    PasswordFileReader _passwordFileReader;
    WordManager        _wordManager;
    Game               _game;
};


#endif /* APP_APPLICATION */
