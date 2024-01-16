#pragma once
#include <SFML/Graphics.hpp>

template<typename T>
class Movement
{
    public:

        void movementController(const sf::Event& e);
        void movement();
        Movement(T& target);
        ~Movement();
        const T& getTarget();
        

    private:

        T target;
        sf::Vector2f position;
        sf::Vector2f velocity;
        sf::Vector2f acceleration;

        float x_left_constrains = 0;
        float x_right_constrains = 0;
        float y_botton_constrains = 0;
        float y_up_constrains = 0;


        bool touching_ground = true; 
        bool left_key_pressed = false;
        bool right_key_pressed = false;
        bool jumping = false;

        void isJumping();

};


template<typename T>
void Movement<T>::isJumping()
{
    if (this->jumping)
    {
        this->velocity.y = this->velocity.y - 4;
        this->position.y = this->position.y - this->velocity.y;
    }

    if (!this->touching_ground && !this->jumping)
    {
        this->velocity.y = this->velocity.y - 4;
        this->position.y = this->position.y - this->velocity.y;
    }

    if (this->position.y == this->y_botton_constrains)
    {
        this->velocity.y = 40;
        touching_ground = true;
    }

}


template<typename T>
void Movement<T>::movementController(const sf::Event& e)
{

    // CHECK If keyboard button is pressed
    if (e.type == sf::Event::KeyPressed)
    {
        if (e.key.code == sf::Keyboard::Left)
        {
            this->left_key_pressed = true;
        }
        
        if (e.key.code == sf::Keyboard::Right)
        {
            this->right_key_pressed = true;
        }
        
        if (e.key.code == sf::Keyboard::Space && touching_ground)
        {
            this->touching_ground = false;
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
        
        if (e.key.code == sf::Keyboard::Right)
        {
            this->right_key_pressed = false;
        }
         
        if (e.key.code == sf::Keyboard::Space)
        {
            this->jumping = false;
        }
    }
}

template<typename T>
void Movement<T>::movement()
{
    // MOVEMENTS
    if (this->left_key_pressed && ( this->position.x - (this->velocity.x) >= this->x_left_constrains))
    {
        this->position.x = this->position.x - (this->velocity.x);
    }

    if (this->right_key_pressed && (this->position.x + (this->velocity.x) <= this->x_right_constrains))
    {
        this->position.x = this->position.x + (this->velocity.x);
    }

    this->isJumping();

    this->target.setPosition(this->position);
}


template<typename T>
Movement<T>::Movement(T& target)
{
    this->y_up_constrains = 700;
    this->y_botton_constrains = 560;
    this->x_left_constrains = 0;
    this->x_right_constrains = 1180;


    this->position = sf::Vector2f(640.f, 560.f);
    this->target = target;
    //this->target.setSize(sf::Vector2f(100.f, 100.f));
    this->target.setPosition(this->position);

    this->velocity = sf::Vector2f(10.0f, 40.0f);
    this->acceleration = sf::Vector2f(0, 9.8f);
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



