#include <SFML/Graphics.hpp>
#include <math.h>
#include "Movement.h"
#include <iostream>

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

    Sprite player;
    Sprite background;
    Vector2u TextureSize;  //Added to store texture size.
    Vector2u WindowSize;   //Added to store window size.

    RenderWindow window(VideoMode(1280, 720), "NOME FINESTRA");
    window.setFramerateLimit(60);
    RectangleShape rect;


    Texture texture;
    if (!texture.loadFromFile("C:\\Users\\casar\\OneDrive\\Desktop\\background.png"))
    {
        return;
    }

    Texture player_texure;
    if (!player_texure.loadFromFile("C:\\Users\\casar\\OneDrive\\Desktop\\player1.png"))
    {
        return;
    }

    TextureSize = texture.getSize(); //Get size of texture.
    WindowSize = window.getSize();             //Get size of window.

    float ScaleX = (float)WindowSize.x / TextureSize.x;
    float ScaleY = (float)WindowSize.y / TextureSize.y;     //Calculate scale.

    background.setTexture(texture);
    background.setScale(ScaleX, ScaleY);
    player.setTexture(player_texure);
    player.setScale(0.1f, 0.1f);

    Movement<Sprite> mov(player);

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

            // enable player movement by passing event
            mov.movementController(event);
        }

        
        mov.movement();
        // render
        
        window.clear();
        window.draw(background);
        window.draw(mov.getTarget());
        window.display();
    }
}