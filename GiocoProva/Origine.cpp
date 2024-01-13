#include <SFML/Graphics.hpp>
#include <math.h>
#include "Movement.h"


using namespace sf;


void initGame();

int main()
{
    initGame();
    return 0;
}

void initGame()
{
    // render finestra

    RenderWindow window(VideoMode(1280, 720), "NOME FINESTRA");
    window.setFramerateLimit(60);

    RectangleShape rect;
    Movement<RectangleShape> mov(rect);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape))
                window.close();

            // comandi spostamento
            mov.movement(event);
        }

        // check if the player is respecting constrains
        mov.updatePlayer();

        // render
        window.clear();
        window.draw(mov.getTarget());
        window.display();
    }
}