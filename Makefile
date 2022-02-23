BOX2DINCPATH = path/to/include/box2d
BOX2DLIBPATH = path/to/box2d/lib
OPTIONS = -std=c++17 -Wall -Weffc++ -Wextra -Wsign-conversion -Wpedantic
TITLE = box2ddemo
OBJ = main.o box.o

output: main.o box.o
	g++ main.o box.o -o $(TITLE) -L$(BOX2DLIBPATH) -lsfml-graphics -lsfml-window -lsfml-system -lbox2d

clear: 
	rm main.o box.o

main.o: main.cpp
	g++ -c main.cpp -isystem $(BOX2DINCPATH) $(OPTIONS)

box.o: box.h box.cpp
	g++ -c box.cpp -isystem $(BOX2DINCPATH) $(OPTIONS)
