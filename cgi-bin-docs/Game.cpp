#include "Game.h"

using namespace std;

Game::Game(char inKey, int inUsrCount, string inText){
   _key = inKey;
   _usrCount = inUsrCount;
   _text = inText;
}

int Game::countText(char key, string text) 
{
   int x = 0;
   for(char n : text){
      if(n == key){
         x++; // increment count when the selected char is found in the text, return it as an int to know how many times the selected char is in the text.
      }
      cout << "<br> dlordelo -- countText value is: " << x;
      return x;
   }
}

int Game::getResult(){
   int value = countText(_key, _text);

   if(_usrCount > value){
      return 1; // return positive 1 if the selected int from web is greater than acutal value number
   }
   else if (_usrCount < value){
      return -1; // reutrn negative 1 if the selected in from web is less than actual number
   }
   else if (_usrCount == value){
      return 0; // return 0 for successfull 
   }
   else{
      cout << "Error in Game.cpp line 33"; // failsafe error
   }
}
