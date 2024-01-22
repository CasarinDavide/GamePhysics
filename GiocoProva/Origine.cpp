#include <SFML/Graphics.hpp>
#include <math.h>
#include "Player.h"
#include <iostream>
#include <string>



void initGame();

int main()
{
    initGame();
    return 0;
}

void initGame()
{
    // render finestra

    sf::Sprite background;
    sf::Vector2u TextureSize;  //Added to store texture size.
    sf::Vector2u WindowSize;   //Added to store window size.

    sf::RenderWindow window(sf::VideoMode(1280, 720), "NOME FINESTRA");
    window.setFramerateLimit(60);
    sf::RectangleShape rect;


    sf::Texture texture;
    if (!texture.loadFromFile("source/img/background.png"))
    {
        return;
    }

    
        TextureSize = texture.getSize(); //Get size of texture.
        WindowSize = window.getSize();             //Get size of window.

        float ScaleX = (float)WindowSize.x / TextureSize.x;
        float ScaleY = (float)WindowSize.y / TextureSize.y;     //Calculate scale.

        background.setTexture(texture);
        background.setScale(ScaleX, ScaleY);
        
        /*
        sf::Vector2i texture_pos(0.f, 0.f);
        player.setTextureRect(sf::IntRect(texture_pos, sf::Vector2i(96.0f, 71.f)));
        */

        Player pl(sf::Vector2f(3.f, 40.f), sf::Vector2f(0.f, 4.f), sf::Vector2f(300.f, 560.0f), std::string("source/img/zapdos_leftside.png"));

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }

                if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                    window.close();

                // enable player movement by passing event
                pl.playerAction(event);

            }

            pl.move();

        

            /*
            // Update texture position every frame
            texture_pos.x += 96; // Increment x-coordinate by 96

            // Reset x-coordinate and increment y-coordinate when reaching the end of the row
            if (texture_pos.x >= 384)
            {
                texture_pos.x = 0;
                texture_pos.y += 71;
            }

            // Reset to the beginning when reaching the end of the texture
            if (texture_pos.y >= 142)
            {
                texture_pos = sf::Vector2i(0, 0);
            }

            player.setTextureRect(sf::IntRect(texture_pos, sf::Vector2i(96, 71)));
            */

            window.clear();
            window.draw(background);
            window.draw(pl.getSprite());
            window.display();
        }
}