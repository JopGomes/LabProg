#!/bin/bash
g++ -c QueenTrab.cpp
g++ -c QueenTrab.cpp -Ijoseph//Documents/SFML-2.5.1-linux-gcc-64-bit/SFML-2.5.1/include
g++ QueenTrab.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app
