#pragma once
#include "Movement.h"
#include <SFML/Graphics.hpp>
#include <string>


class Player
{
	private: 
		sf::Vector2f velocity;
		sf::Vector2f acceleration;
		sf::Vector2f position;
		Movement<Player>* mov;
		sf::Sprite *player_image;
		bool touching_ground = true;
		bool left_key_pressed = false;
		bool right_key_pressed = false;
		bool jumping = false;


	public:
		Player(sf::Vector2f velocity, sf::Vector2f acceleration, sf::Vector2f position, std::string path);
		Player(Player& pl);
		Player(Player&& pl);
		Player();
		const sf::Vector2f& getVelocity();
		void setVelocity(const sf::Vector2f& velocity);
		const sf::Vector2f& getAcceleration();
		void setAcceleration(const sf::Vector2f& acceleration);
		const sf::Vector2f& getPosition();
		void setPosition(const sf::Vector2f& position);
		const bool isTouchingGround();
		const bool isLeftKeyPressed();
		const bool isRightKeyPressed();
		const bool isJumping();
		void setTouchingGround(const bool touching_ground);
		void setLeftKeyPressed(const bool left_key_pressed);
		void setRightKeyPressed(const bool right_key_pressed);
		void setJumping(const bool jumping);
		void playerAction(sf::Event& event);
		Player& operator=(const Player& pl);
		sf::Sprite& getSprite();
		void move();
		/*TODO IMPLEMENT PLAYER ANIMATION*/

};

