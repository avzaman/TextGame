g++ -c ProcessCgi.cpp -std=c++11
g++ -c Game.cpp -std=c++11
g++ -c main.cpp  -std=c++11
g++ -o project3 main.o Game.o ProcessCgi.o -lcgicc
chmod 705 project3