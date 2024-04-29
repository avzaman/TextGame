#include "Game.h"
#include "ProcessCgi.h"

using namespace std;

int countText(char key, string text) 
{
   int x;
   for(char n : text){
      if(n == key){
         x++; // increment count when the selected char is found in the text, return it as an int to know how many times the selected char is in the text.
      }
      return x;
   }
}

int getResult(){
   char key = ProcessCgi::getChosen();
   int usrcount = ProcessCgi::getCount();
   string text = ProcessCgi::getText();
   int value = countText(key, text);

   if(usrcount > value){
      return 1; // return positive 1 if the selected int from web is greater than acutal value number
   }
   else if (usrcount < value){
      return -1; // reutrn negative 1 if the selected in from web is less than actual number
   }
   else if (usrcount == value){
      return 0; // return 0 for successfull 
   }
   else{
      cout << "Error in Game.cpp line 33"; // failsafe error
   }
}