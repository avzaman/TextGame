#include <string>
#include <iostream>

class Game
{
    private:
        char _chosen;
        int _count;
        string _text;
    public:
        int getResult();
        int countText();
};