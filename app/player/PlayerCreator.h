#ifndef APP_PLAYER_PLAYERCREATOR
#define APP_PLAYER_PLAYERCREATOR

#include "app/player/Player.h"

#include <vector>

class PlayerCreator
{
public:
    /**
     * @brief Default constructor for PlayerCreator.
     */
    PlayerCreator();

    /**
     * @brief Destructor for PlayerCreator.
     */
    ~PlayerCreator();

    /**
     * @brief Create players based on the number of players.
     */
    void createPlayers();

    /**
     * @brief Get the number of players.
     * @return The number of players.
     */
    int getNumberOfPlayers();

    /**
     * @brief Get the names of the players.
     * @param numPlayers The number of players.
     */
    void getPlayerNames(int numPlayers);

    /**
     * @brief Get the vector of players.
     * @return The vector of players.
     */
    std::vector<Player> getPlayers() const { return _players; }

    /**
     * @brief Add a player to the vector of players.
     * @param playerName The name of the player to add.
     */
    void addPlayer(const std::string& playerName);

private:
    /**
     * @brief Print the players' names.
     */
    void printPlayers();


private:
    std::vector<Player> _players = {}; /**< The vector of players. */
};


#endif /* APP_PLAYER_PLAYERCREATOR */
