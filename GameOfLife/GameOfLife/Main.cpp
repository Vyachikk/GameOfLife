#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>

#include "Logic.h"
#include "Map.h"

int main()
{ 
    Logic lg;
    RenderWindow window(VideoMode(SCREEN_W, SCREEN_H), "My window");
    Map mp(window);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            lg.MouseClick(event, window, mp.Screen, mp.NextStep);
        }
        window.clear(Color::White);
        mp.screenRender();
        window.display();
    }
}

