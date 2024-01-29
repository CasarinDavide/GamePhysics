#pragma once
#include <SFML/Graphics.hpp>
class Animation 
{
	public:
        template<typename T>
        static void UpdateTexture(T& target, sf::Vector2i& start_pos, sf::Vector2i box_size, int rows, int columns)
        {
            // Update texture position every frame
            start_pos.x += box_size.x; // Increment x-coordinate by 96

            // Reset x-coordinate and increment y-coordinate when reaching the end of the row
            if (start_pos.x >= box_size.x * (columns - 1))
            {
                start_pos.x = 0;
                start_pos.y += box_size.y;
            }

            // Reset to the beginning when reaching the end of the texture
            if (start_pos.y >= box_size.y * (rows))
            {
                start_pos = sf::Vector2i(0, 0);
            }
        }

        template<typename T>
        static sf::Vector2f flipTexture(T& target)
        {
            if (target.isLeftKeyPressed())
            {
                return sf::Vector2f(-1, 1);
            }

            if (target.isRightKeyPressed())
            {
                return sf::Vector2f(1, 1);
            }
            
            return sf::Vector2f(0, 0);
        }

};