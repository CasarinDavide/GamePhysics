
#include "Player.h"
#include "Movement.h" 


/* TODO MAKE THE PLAYER INDIPENDENT FROM FRAMERATE*/
Player::Player(sf::Vector2f velocity, sf::Vector2f acceleration, sf::Vector2f position, std::string path)
{
	sf::Texture* player_texture = new sf::Texture();
	if (!player_texture->loadFromFile(path))
	{
		throw std::runtime_error("Failed to load player texture from file");
	}

	this->position = position;
	this->acceleration = acceleration;
	this->velocity = velocity;
	this->player_image = new sf::Sprite();

	this->player_image->setTexture(*player_texture);
	sf::Vector2i texture_pos(0.f, 0.f);
	this->player_image->setTextureRect(sf::IntRect(texture_pos, sf::Vector2i(96.0f, 71.f)));
	this->player_image->setPosition(this->position);
	this->img_box_size = {96, 71};
	this->actual_box_position = { 0,0 };
	this->numberOfSpriteRow = 2;
	this->numberOfSpriteColum = 5;

}

void Player::playerAction(sf::Event& event)
{
	Movement::movementController(event,*this);
	
}

void Player::move()
{
	Movement::movement(*this);
	this->changeAnimation();
}

Player::Player(Player&& pl)
{

}

Player::Player(Player& pl)
{

}

Player::Player()
{

}

const sf::Vector2f& Player::getVelocity()
{
	return this->velocity;
}
void Player::setVelocity(const sf::Vector2f& velocity)
{
	this->velocity = velocity;
}

const sf::Vector2f& Player::getAcceleration()
{
	return this->acceleration;
}

void Player::setAcceleration(const sf::Vector2f& acceleration)
{
	this->acceleration = acceleration;
}

const sf::Vector2f& Player::getPosition()
{
	return this->position;
}

void Player::setPosition(const sf::Vector2f& position)
{
	this->position.x = position.x;
	this->position.y = position.y;
	this->player_image->setPosition(this->position);
}

const bool Player::isTouchingGround()
{
	return this->touching_ground;
}
const bool Player::isLeftKeyPressed()
{
	return this->left_key_pressed;
}
const bool Player::isRightKeyPressed()
{
	return this->right_key_pressed;
}
const bool Player::isJumping()
{
	return this->jumping;
}


void Player::setTouchingGround(const bool touching_ground)
{
	this->touching_ground = touching_ground;
}
void Player::setLeftKeyPressed(const bool left_key_pressed)
{
	this->left_key_pressed = left_key_pressed;
}
void Player::setRightKeyPressed(const bool right_key_pressed)
{
	this->right_key_pressed = right_key_pressed;
}
void Player::setJumping(const bool jumping)
{
	this->jumping = jumping;
}

Player& Player::operator=(const Player& pl)
{
	if (&pl != this)
	{
		this->acceleration = pl.acceleration;
		this->velocity = pl.velocity;
		this->jumping = pl.jumping;
		this->position = pl.position;
		this->left_key_pressed = pl.left_key_pressed;
		this->right_key_pressed = pl.right_key_pressed;
		this->player_image = pl.player_image;
	}

	return *this;
}

sf::Sprite& Player::getSprite()
{
	return *this->player_image;
}

void Player::changeAnimation()
{
	Animation::UpdateTexture(*this, this->actual_box_position , this->img_box_size, this->numberOfSpriteRow, this->numberOfSpriteColum);
	this->player_image->setTextureRect(sf::IntRect(this->actual_box_position, img_box_size));
}