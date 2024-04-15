#ifndef APP_APPLICATION
#define APP_APPLICATION


#include "app/passwordFileReader/PasswordFileReader.h"
#include "app/player/PlayerCreator.h"
#include "app/wordManager/WordManager.h"

class Application
{
public:
    Application();
    ~Application();

    void run();

private:
    PlayerCreator      _playerCreator;
    PasswordFileReader _passwordFileReader;
    WordManager        _wordManager;
};


#endif /* APP_APPLICATION */
