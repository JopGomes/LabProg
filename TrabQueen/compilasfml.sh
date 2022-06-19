#!/bin/bash
g++ -c QueenTrab.cpp -I"C:\Users\Joseph\Documents\ESTUDOS\IME_GRADUACAO\IME_2022\COMP\LabProg\TrabQueen\SFML\SFML-2.5.1\include"
g++ QueenTrab.o -o Damas -L"C:\Users\Joseph\Documents\ESTUDOS\IME_GRADUACAO\IME_2022\COMP\LabProg\TrabQueen\SFML\SFML-2.5.1\lib" sfml-app -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
./sfml-app
