#pragma once
#include "Movement.h"
#include <SFML/Graphics.hpp>


class Player
{
	private: 
		sf::Vector2f default_velocity;
		sf::Vector2f default_acceleration;
		sf::Vector2f default_position;
		sf::Vector2f act_velocity;
		sf::Vector2f act_acceleration;
		sf::Vector2f act_position;
		Movement<Player>* mov;
		sf::Sprite player_image;


	public:
		Player(sf::Vector2f default_velocity, sf::Vector2f default_acceleration, sf::Vector2f default_position,sf::String path);
		void playerAction(sf::Event& event);

		

};

