#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

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
        cout << "<br> made it out of cons";

        cout << "<br>Chosen char: " << proc.getChosen();
        cout << "<br>Count int: " << proc.getCount();
        cout << "<br>Text string:<br>" << proc.getText();
    }
    catch (const std::exception &e)
    {
        cout << "Exception caught during ProcessCgi construction: " << e.what() << endl;
        exit(1);
    }
}
// I made a temporary main function to test out ProcessCgi class and compile script <3 -Vince