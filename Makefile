BOX2DINCPATH = /home/kjpolwin/Box2D/include/box2d
BOX2DLIBPATH = ./
OPTIONS = -std=c++17 -Wall -Weffc++ -Wextra -Wsign-conversion -Wpedantic
TITLE = box2ddemo
OBJ = converter.o main.o box.o platform.o

output: $(OBJ)
	g++ $(OBJ) -o $(TITLE) -L$(BOX2DLIBPATH) -lsfml-graphics -lsfml-window -lsfml-system -lbox2d

clear: 
	rm main.o box.o platform.o $(TITLE)

main.o: main.cpp
	g++ -c main.cpp -isystem $(BOX2DINCPATH) $(OPTIONS)

box.o: box.h box.cpp
	g++ -c box.cpp -isystem $(BOX2DINCPATH) $(OPTIONS)

platform.o: platform.h platform.cpp
	g++ -c platform.cpp -isystem $(BOX2DINCPATH) $(OPTIONS)

converter.o: converter.h converter.cpp
	g++ -c converter.cpp -isystem $(BOX2DINCPATH) $(OPTIONS)

