#ifndef APP_PLAYER_PLAYER
#define APP_PLAYER_PLAYER

#include <string>

class Player
{
public:
    Player(const std::string& name);
    ~Player(){};

    void        setName(const std::string& name) { _name = name; };
    std::string getName() const { return _name; }
    void        setScore(int score) { _score = score; };
    int         getScore() const { return _score; }

private:
    std::string _name{ "" };
    int         _score{ 0 };
};


#endif /* APP_PLAYER_PLAYER */
