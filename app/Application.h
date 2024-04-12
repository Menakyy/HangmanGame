#ifndef APP_APPLICATION
#define APP_APPLICATION


#include "app/passwordFileReader/PasswordFileReader.h"
#include "app/player/PlayerCreator.h"

class Application
{
public:
    Application();
    ~Application();

    void run();

private:
    PlayerCreator      _playerCreator;
    PasswordFileReader _passwordFileReader;
};


#endif /* APP_APPLICATION */
