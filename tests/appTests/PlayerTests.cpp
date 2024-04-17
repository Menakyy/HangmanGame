#include "CppUTest/TestHarness.h"
#include "app/player/Player.h"
#include "app/player/PlayerCreator.h"

#include <string>

TEST_GROUP(PlayerTestsGroup)
{
    Player*        player        = nullptr;
    Player*        player2       = nullptr;
    PlayerCreator* playerCreator = nullptr;

    void setup()
    {
        const std::string name  = "Player1";
        const std::string name2 = "Player2";

        player        = new Player(name);
        player2       = new Player(name2);
        playerCreator = new PlayerCreator();
    }

    void teardown()
    {
        delete player;
        delete player2;
        delete playerCreator;
    }
};

TEST(PlayerTestsGroup, PlayerTest)
{
    CHECK_EQUAL("Player1", player->getName());
    CHECK_EQUAL("Player2", player2->getName());

    CHECK_EQUAL(0, player->getScore());
    CHECK_EQUAL(0, player2->getScore());

    player->setScore(10);
    player2->setScore(20);

    CHECK_EQUAL(10, player->getScore());
    CHECK_EQUAL(20, player2->getScore());
}

TEST(PlayerTestsGroup, PlayerCreatorTest)
{
    const std::string name  = "Player1";
    const std::string name2 = "Player2";

    playerCreator->addPlayer(name);
    playerCreator->addPlayer(name2);
    CHECK_EQUAL(2, playerCreator->getPlayers().size());
    CHECK_EQUAL("Player1", playerCreator->getPlayers().at(0).getName());
    CHECK_EQUAL(0, playerCreator->getPlayers().at(0).getScore());
    CHECK_EQUAL("Player2", playerCreator->getPlayers().at(1).getName());
    CHECK_EQUAL(0, playerCreator->getPlayers().at(1).getScore());
}