#pragma once
#include <SFML/Graphics.hpp>

template<typename T>
class Movement
{
    public:
        void movement(const sf::Event& e);
        Movement(T& target);
        ~Movement();
        const T& getTarget();
        void updatePlayer();

    private:
        T target;
        sf::Vector2f position;
        sf::Vector2f velocity;
        sf::Vector2f gravity;
        bool left_key_pressed = false;
        bool right_key_pressed = false;
        bool down_key_pressed = false;
        bool up_key_pressed = false;
        bool jumping = false;

};

template<typename T>
void Movement<T>::updatePlayer()
{
    // if the player is jumping i get him back to the ground
    if (this->position.y < 360)
    {
        this->position.y += this->gravity.y;
    }

    this->target.setPosition(this->position);

}

template<typename T>
void Movement<T>::movement(const sf::Event& e)
{
    
    // CHECK If keyboard button is pressed
    if (e.type == sf::Event::KeyPressed)
    {
        if (e.key.code == sf::Keyboard::Left)
        {
            this->left_key_pressed = true;
        }
        else if (e.key.code == sf::Keyboard::Right)
        {
            this->right_key_pressed = true;
        }
        else if (e.key.code == sf::Keyboard::Up)
        {
            this->up_key_pressed = true;
        }
        else if (e.key.code == sf::Keyboard::Down)
        {
            this->down_key_pressed = true;
        }
        else if(e.key.code == sf::Keyboard::Space)
        {
            this->jumping = true;
        }
    }

    // CHECK if keyboard button is released
    if (e.type == sf::Event::KeyReleased)
    {
        if (e.key.code == sf::Keyboard::Left)
        {
            this->left_key_pressed = false;
        }
        else if (e.key.code == sf::Keyboard::Right)
        {
            this->right_key_pressed = false;
        }
        else if (e.key.code == sf::Keyboard::Up)
        {
            this->up_key_pressed = false;
        }
        else if (e.key.code == sf::Keyboard::Down)
        {
            this->down_key_pressed = false;
        }
        else if(e.key.code == sf::Keyboard::Space)
        {
            this->jumping = false;
        }
    }

    // MOVEMENTS
    if (this->left_key_pressed)
    {
        this->position.x = this->position.x - (this->velocity.x);
    }

    if (this->right_key_pressed)
    {
        this->position.x = this->position.x + (this->velocity.x);
    }

    if (this->up_key_pressed)
    {
        this->position.y = this->position.y - (this->velocity.y);
    }

    if (this->down_key_pressed)
    {
        this->position.y = this->position.y + (this->velocity.y);
    }
    
    // Handle jump physics
    if (jumping)
    {
        // aumento la mia y
        this->position.y = this->position.y - this->velocity.y;
    }

    this->target.setPosition(this->position);
}

template<typename T>
Movement<T>::Movement(T& target)
{
    this->position = sf::Vector2f(640.f, 360.f);
    this->target = target;
    this->target.setSize(sf::Vector2f(100.f, 100.f));
    this->target.setPosition(this->position);

    this->velocity = sf::Vector2f(2.0f, 50.0f);
    this->gravity = sf::Vector2f(2.0f, 2.0f);
}

template<typename T>
Movement<T>::~Movement()
{
    // ... Implementation ...
}


template<typename T>
const T& Movement<T>::getTarget()
{
    return this->target;
}

