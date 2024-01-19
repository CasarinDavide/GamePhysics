#include "Player.h"


Player::Player(sf::Vector2f default_velocity, sf::Vector2f default_acceleration, sf::Vector2f default_position,sf::String path)
{
	sf::Texture player_texture;
	if (!player_texture.loadFromFile(path))
	{
		throw __std_exception_data();
	}

	this->act_position = this->act_position = default_position;
	this->act_acceleration = this->default_acceleration = default_acceleration;
	this->act_velocity = this->default_velocity  = default_velocity;
	
	/* TODO implement a method that given any image it fits on the player */
	this->player_image.setTexture(player_texture);
	this->player_image.setScale(0.1f, 0.1f);

	this->mov = new Movement<Player>(*this);

}

void Player::playerAction(sf::Event& event)
{
	this->mov->movementController(event);
	this->mov->movement();
}
