#ifndef APP_HANGMAN_HANGMAN
#define APP_HANGMAN_HANGMAN

#include <iostream>
#include <vector>

class HangmanDrawer
{
private:
    int                      currentPart  = 0;
    std::vector<std::string> hangmanParts = { "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========",
                                              "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========",
                                              "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========",
                                              "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========",
                                              "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========",
                                              "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========",
                                              "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========" };

public:
    void fail()
    {
        if (currentPart < hangmanParts.size())
        {
            draw();
        }
    }

    void draw()
    {
        if (currentPart < hangmanParts.size())
        {
            std::cout << std::endl;
            std::cout << "Hangman: " << std::endl;
            std::cout << hangmanParts[currentPart] << std::endl;
            currentPart++;
            std::cout << std::endl;
        }
    }

    bool isFullyDrawn() const { return currentPart >= hangmanParts.size(); }

    void reset() { currentPart = 0; }
};


#endif /* APP_HANGMAN_HANGMAN */
