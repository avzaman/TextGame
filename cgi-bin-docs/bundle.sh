g++ -c ProcessCgi.cpp -std=c++11
g++ -c Game.cpp -std=c++11
g++ -c main.cpp  -std=c++11
g++ -o project3 main.o Game.o ProcessCgi.o -lcgicc
chmod 705 project3
chmod 705 ../project3.php
cp -fi project3 ../../cgi-bin
cp -fi ProcessCgi.h ../../cgi-bin
cp -fi Game.h ../../cgi-bin
cp -fi ../project3.php ../../CPS3525