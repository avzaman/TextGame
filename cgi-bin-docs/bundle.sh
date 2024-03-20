g++ -c ProcessCgi.cpp -lcgicc -std=c++11
g++ -c Game.cpp -std=c++11
g++ -c main.cpp  -lcgicc -std=c++11
g++ -o project3 main.o Game.o ProcessCgi.o 
chmod 705 project3