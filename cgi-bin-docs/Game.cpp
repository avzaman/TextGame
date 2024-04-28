#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace cgicc;

int charcount () 
{

   bool debug = false; // change to true and re=compile to debug with fixed vars
   int asciiMAX = 126; // max keyboard expected input for ascii 
   int table[asciiMAX][3];

   for (int i = 0; i < asciiMAX; ++i) // initalize array with empty values
   { 
        table[i][0] = i;    // ASCii value
        table[i][1] = 0;    // count 
        table[i][2] = 0;    // character 
    }
   
   for (char x : mydata) // array to fill with values
   { 
      int ascii = int(x);
      table[ascii][1]++; // add to count value with current iterated char

      if (table[ascii][2] == 0) //check if value is in array, if so table[ASCIVALUE][2] == !0
      { 
         table[ascii][2] = x; //add it to the char identifier column, int conversion is done when added to int array
      }
   }

   cout << "<TABLE border=1>";
   cout << "<TH>ASCII #<TH>Char<TH>Count ";

   int max = 0, min = 99;
   for (int i = 0; i < asciiMAX; ++i)
   {
      if (table[i][1] > 0) // skips table elements with count == 0
      { 
         cout << "<TR><TD>"<<table[i][0] << "<TD>" << char(table[i][2]) <<"<TD>"<<table[i][1]; // print table
         if(table[i][1] > max){
            max = table[i][1];      // define max var to grab max count later
         }
         if(table[i][1] < min){
            min = table[i][1];     // define min var to grab max count later
         }
      }
   }
   cout << "</TABLE>";       // close table

   vector<char> maxArr;
   vector<char> minArr;
   for (int i = 0; i < asciiMAX; ++i)
   {
      if (table[i][1] > 0 && table[i][1] == max) { // skips table elements with count == 0  and adds them to char output array
         maxArr.push_back(table[i][2]);
      }
      if (table[i][1] >0 && table[i][1] == min){  // skips table elements with count == 0  and adds them to char output array
         minArr.push_back(table[i][2]);
      }
   }

   cout << "<br>Character: ";   // max count output 
   for(char k : maxArr)
   {
      if (k > 0){
         cout << k << " ";
      }
   }
   cout <<"has maximum count: " << max;

   cout << "<br>Character: ";    // max count output 
   for(char k : minArr)
   {
      if (k > 0){
         cout << k << " ";
      }
   }
   cout <<"has minimum count: " << min;

   cout << "</body>\n";
}