#ifndef APP_GAME_GAME
#define APP_GAME_GAME

#include "app/player/Player.h"
#include "app/player/PlayerCreator.h"
#include "app/wordManager/WordManager.h"

#include <iostream>
#include <string>

class Game
{
public:
    static const int POINTS = 10;

    Game(PlayerCreator& playerCreator, WordManager& wordManager);
    ~Game();

    void playGame();
    void setPlayerPoints();

private:
    PlayerCreator& _playerCreator;
    WordManager&   _wordManager;
    Player&        _player;
};


#endif /* APP_GAME_GAME */
