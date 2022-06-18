#!/bin/bash
g++ -c QueenTrab.cpp
g++ -c QueenTrab.cpp -ISFML/include
g++ QueenTrab.o -o sfml-app -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
./sfml-app
