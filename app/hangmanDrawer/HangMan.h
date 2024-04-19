#ifndef APP_HANGMANDRAWER_HANGMAN
#define APP_HANGMANDRAWER_HANGMAN

#include <iostream>
#include <vector>

class HangmanDrawer
{
public:
    HangmanDrawer();
    ~HangmanDrawer();

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

    int getCurrentPart() const { return currentPart; }

    std::vector<std::string> getHangmanParts() const { return hangmanParts; }

private:
    int                      currentPart  = 0;
    std::vector<std::string> hangmanParts = { "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========",
                                              "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========",
                                              "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========",
                                              "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========",
                                              "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========",
                                              "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========",
                                              "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========" };
};


#endif /* APP_HANGMANDRAWER_HANGMAN */
