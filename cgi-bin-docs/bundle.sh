g++ -c ProcessCgi.cpp -std=c++11
g++ -c Game.cpp -std=c++11
g++ -c main.cpp  -std=c++11
g++ -o project3 main.o Game.o ProcessCgi.o -lcgicc
chmod 705 project3
chmod 705 ../public-html-docs/project3.php
chmod 705 ../public-html-docs/style.css
cp -fp project3 ../../../cgi-bin/project3
cp -fp ProcessCgi.h ../../../cgi-bin/ProcessCgi.h
cp -fp Game.h ../../../cgi-bin/Game.h
cp -fp ../public-html-docs/project3.php ../../project3.php
cp -fp ../public-html-docs/style.css ../../style.css