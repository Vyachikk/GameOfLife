#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>

#include "Map.h"

using namespace sf;
using namespace std;

#ifndef LOGIC_H
#define LOGIC_H

class Logic
{	
public:
	int neighbours;
	void MouseClick(Event&, RenderWindow& window, int **Screen, int** NextStep);
	void Clear(int** Screen);
	void Line(int** Screen);
	void RandomCells(int** Screen);
	void Neighbours(int** Screen, int ** NextStep);
};
#endif