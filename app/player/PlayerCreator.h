#ifndef APP_PLAYER_PLAYERCREATOR
#define APP_PLAYER_PLAYERCREATOR

#include "app/player/Player.h"

#include <vector>

class PlayerCreator
{
public:
    PlayerCreator();
    ~PlayerCreator();

    void                createPlayers();
    int                 getNumberOfPlayers();
    void                getPlayerNames(int numPlayers);
    void                addPlayer(const std::string& playerName);
    void                printPlayers();
    std::vector<Player> getPlayers() const { return _players; }

private:
    std::vector<Player> _players = {};
};


#endif /* APP_PLAYER_PLAYERCREATOR */
