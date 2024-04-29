#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

#include "Game.h"
#include "ProcessCgi.h"

int main()
{
    cout << "Content-type:text/html\r\n\r\n";
    cout << "<html>\n";
    cout << "<head>\n";
    cout << "<title>CPS 3525 project 2</title>\n";
    cout << "</head>\n";
    cout << "<body>\n";
    cout << "<h2>CPS 3525 Project 3</h2>\n";

    cout << "<br> before constructor";

    try
    {
        ProcessCgi proc; // Attempt to construct ProcessCgi object
        cout << "<br> User's Input:";

        cout << "<br>Chosen char: " << proc.getChosen();
        cout << "<br>Count int: " << proc.getCount();
        cout << "<br>Text string:<br>" << proc.getText();

        Game *game = new Game(proc.getChosen(), proc.getCount(), proc.getText()); // Crete a Game object and process inputs

        // Get the results from the Game class
        int results = game->getResult();

        if (results == 0)
        {
            cout << "<br> You guessed the right number!!";
        }
        else if (results > 0)
        {
            cout << "<br> Your guess is too high";
        }
        else
        {
            cout << "<br> Your guess is too low";
        }
    }
    catch (const std::exception &e)
    {
        cout << "Exception caught during ProcessCgi or Game construction: " << e.what() << endl;
        exit(1);
    }

    cout << "</body>\n";
    cout << "</html>\n";

    return 0;
}
