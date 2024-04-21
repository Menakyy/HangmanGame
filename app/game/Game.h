#ifndef APP_GAME_GAME
#define APP_GAME_GAME

#include "app/hangmanDrawer/HangMan.h"
#include "app/player/Player.h"
#include "app/player/PlayerCreator.h"
#include "app/wordManager/WordManager.h"

#include <cctype>
#include <iostream>
#include <string>

class Game
{
public:
    static const int POINTS = 10;

    Game(PlayerCreator& playerCreator, WordManager& wordManager);
    ~Game();

    void playGame();

    void endRound();

    void guessLetterByPlayer();

    void guessWordByPlayer();

    bool isWordGuessed() const { return _wordManager.isWordGuessed(); }

    bool wannaGuessWord();

    void setPlayerPoints();

    void printPlayerPoints();

    void newGame();

    bool isAvailableWordLeft() const { return _wordManager.isAvailableWordLeft(); }

    void exitGame(const std::string& message);

    bool isLetter(char ch) { return std::isalpha(ch) != 0; }

private:
    PlayerCreator& _playerCreator;
    WordManager&   _wordManager;
    Player*        _player;
    HangmanDrawer  _hangmanDrawer;
    bool           isGuessed       = false;
    bool           isGuessedLetter = false;
};


#endif /* APP_GAME_GAME */
