// GameOfLife.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include"functions.h"
#include <time.h>
#include <io.h>
#include <fcntl.h>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	srand(time(NULL));
	int size=10; 
	int interval=1000;

	int** currentGeneration = new int* [size];
	for (int i = 0; i < size; ++i)
		currentGeneration[i] = new int[size] {};

	int** nextGeneration = new int* [size];
	for (int i = 0; i < size; ++i)
		nextGeneration[i] = new int[size] {};
	mainLoop(currentGeneration, nextGeneration, size, interval);
}
