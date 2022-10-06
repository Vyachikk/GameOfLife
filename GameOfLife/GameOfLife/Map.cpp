#include "Map.h"
#include "Logic.h"

Logic lg;

Map::Map()
{
	rectangle.setSize(Vector2f(SIZE, SIZE));

	Screen = new int* [H];
	for (int i = 0; i < H; i++)
		Screen[i] = new int[W];

	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			Screen[i][j] = 0;

	NextStep = new int* [H];
	for (int i = 0; i < H; i++)
		NextStep[i] = new int[W];

	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			NextStep[i][j] = 0;
}

Map::Map(RenderWindow& window)
{ 
	this->window = &window;
	rectangle.setSize(Vector2f(SIZE, SIZE));

	Screen = new int* [H];
	for (int i = 0; i < H; i++)
		Screen[i] = new int[W];

	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			Screen[i][j] = 0;

	NextStep = new int* [H];
	for (int i = 0; i < H; i++)
		NextStep[i] = new int[W];

	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			NextStep[i][j] = 0;
}

void Map::screenRender()
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			switch (Screen[i][j])
			{
			case 1: rectangle.setFillColor(Color(0, 0, 0)); break;
			case 0: continue;
			}
			
			rectangle.setPosition(j * SIZE, i * SIZE);
			window->draw(rectangle);
		}
	}
}

void Map::lineRender()
{
	for (int i = 0; i < SCREEN_H; i+= SIZE)
	{
		for (int j = 0; j < SCREEN_W; j+= SIZE)
		{
			Vertex line1[] =
			{
				Vertex(Vector2f(j, i), Color(0, 0, 0)),
				Vertex(Vector2f(j, 1040), Color(0, 0, 0))
			};

			Vertex line2[] =
			{
				Vertex(Vector2f(1920, i), Color(0, 0, 0)),
				Vertex(Vector2f(j, i), Color(0, 0, 0))
			};

			window->draw(line1, 2, Lines);
			window->draw(line2, 2, Lines);
		}
	}
}
