#include "Game.h"
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
   int value = countText(key, text);

   if(usrcount > value){
      return 1;
   }
   else if (usrcount < value){
      return -1;
   }
   else{
      return 0;
   }
}