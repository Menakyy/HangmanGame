#include "PlayerCreator.h"

#include "utils/logger/Logger.h"

#include <iostream>
#include <limits>
#include <string>

PlayerCreator::PlayerCreator()
{
}

PlayerCreator::~PlayerCreator()
{
}

void PlayerCreator::createPlayers()
{
    int players = getNumberOfPlayers();
    getPlayerNames(players);
    printPlayers();
}

int PlayerCreator::getNumberOfPlayers()
{
    int players = 0;

    Logger::info("Creating players...");
    while (true)
    {
        std::cout << "How many players are there? ";
        if (!(std::cin >> players))
        {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        bool correctPlayers = players >= 2 && players <= 4;
        if (not correctPlayers)
        {
            std::cout << "Invalid number of players. Please enter a number between 2 and 4." << std::endl;
        }
        else
        {
            break;
        }
    }

    return players;
}

void PlayerCreator::getPlayerNames(int numPlayers)
{
    std::string playerName;
    for (int i = 0; i < numPlayers; i++)
    {
        std::cout << "Enter player " << i + 1 << " name: ";
        std::cin >> playerName;
        addPlayer(playerName);
    }
}

void PlayerCreator::addPlayer(const std::string& playerName)
{
    Player player(playerName);
    _players.push_back(player);
}

void PlayerCreator::printPlayers()
{
    std::cout << "Printing players..." << std::endl;

    for (auto& player : _players)
    {
        std::cout << "Player name: " << player.getName() << std::endl;
    }
}
