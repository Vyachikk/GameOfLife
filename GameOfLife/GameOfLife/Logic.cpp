#include <dos.h>
#include "Logic.h"

Map mp;

void Logic::MouseClick(Event& event, RenderWindow& window, int **Screen, int** NextStep)
{
	Vector2i mousePos = Mouse::getPosition(window);

	
		if (Mouse::isButtonPressed(Mouse::Left)) { Screen[mousePos.y / SIZE][mousePos.x / SIZE] = 1; }

		if (Mouse::isButtonPressed(Mouse::Right)) { Screen[mousePos.y / SIZE][mousePos.x / SIZE] = 0; }
	

	if (event.type == Event::KeyPressed)
	{
		if (event.key.code == Keyboard::Space) { Neighbours(Screen, NextStep); } // Hold Space 

		if (event.key.code == Keyboard::C) { Clear(Screen); }

		if (event.key.code == Keyboard::R) { RandomCells(Screen); }

		if (event.key.code == Keyboard::L) { Line(Screen); }
	}
}

void Logic::Clear(int** Screen)
{
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			Screen[i][j] = 0;
}

void Logic::Line(int** Screen)
{
	for (int j = 5; j < W - 5; j++)
		Screen[H / 2][j] = 1;
}

void Logic::RandomCells(int** Screen)
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			Screen[i][j] = rand() % (1 - 0 + 1) + 0;
		}
	}
}

void Logic::Neighbours(int** Screen, int** NextStep)
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			NextStep[i][j] = Screen[i][j];
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			neighbours = Screen[(i + H - 1) % H][j] +
				Screen[(i + H + 1) % H][j] +
				Screen[i][(j + W - 1) % W] +
				Screen[i][(j + W + 1) % W] +
				Screen[(i + H - 1) % H][(j + W - 1) % W] +
				Screen[(i + H + 1) % H][(j + W - 1) % W] +
				Screen[(i + H - 1) % H][(j + W + 1) % W] +
				Screen[(i + H + 1) % H][(j + W + 1) % W];

			if (neighbours < 2 || neighbours > 3)
				NextStep[i][j] = 0;
			else if (neighbours == 3)				
				NextStep[i][j] = 1;		
		}
	}	
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			Screen[i][j] = NextStep[i][j];
		}
	}
}


