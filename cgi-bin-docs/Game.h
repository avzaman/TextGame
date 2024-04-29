#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#ifndef GAME_INCLUDED
#define GAME_INCLUDED

class Game
{
    private:
        char _key;
        int _usrCount;
        string _text;
    public:
        Game(char inKey, int inUsrCount, string inText);
        ~Game();
        int getResult();
        int countText(char key, string text);
};
#endif