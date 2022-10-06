#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>

using namespace sf;
using namespace std;

#define H 100	//16 = 50, 8 = 100, 4 = 200
#define W 200	//16 = 100, 8 = 200, 4 = 400

#define SIZE 8

#define SCREEN_H 800
#define SCREEN_W 1600

#ifndef MAP_H
#define MAP_H

class Map
{
private:
	RenderWindow *window;
public:
	RectangleShape rectangle; 
	Map();
	Map(RenderWindow& window);
	int** Screen;
	int** NextStep;
	void screenRender();
	void lineRender();
};
#endif
