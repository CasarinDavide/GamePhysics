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

        T* target;
        float x_left_constrains = 0;
        float x_right_constrains = 0;
        float y_botton_constrains = 0;
        float y_up_constrains = 0;

        void isJumping();

};


template<typename T>
void Movement<T>::isJumping()
{
    if (this->target->isJumping() || (!this->target->isTouchingGround() && !this->target->isJumping()))
    {
        this->target->setVelocity(std::move(this->target->getVelocity() - sf::Vector2f(0,4.f)));
        this->target->setPosition(std::move(this->target->getPosition()- sf::Vector2f(0, this->target->getVelocity().y)));
    }


    if (this->target->getPosition().y == this->y_botton_constrains)
    {
        this->target->setVelocity(std::move(sf::Vector2f(3, 40)));
        this->target->setTouchingGround(true);
        this->target->setJumping(false);
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
            this->target->setLeftKeyPressed(true);
        }
        
        if (e.key.code == sf::Keyboard::Right)
        {
            this->target->setRightKeyPressed(true);
        }
        
        if (e.key.code == sf::Keyboard::Space && this->target->isTouchingGround())
        {
            this->target->setTouchingGround(false);
            this->target->setJumping(true);
        }
    }

    // CHECK if keyboard button is released
    if (e.type == sf::Event::KeyReleased)
    {
        if (e.key.code == sf::Keyboard::Left)
        {
            this->target->setLeftKeyPressed(false);
        }
        
        if (e.key.code == sf::Keyboard::Right)
        {
            this->target->setRightKeyPressed(false);
        }
         
        if (e.key.code == sf::Keyboard::Space )
        {
            this->target->setJumping(false);
        }
    }
}

template<typename T>
void Movement<T>::movement()
{
    // MOVEMENTS
    if (this->target->isLeftKeyPressed() && (this->target->getPosition().x - (this->target->getVelocity().x) >= this->x_left_constrains))
    {
        this->target->setPosition(std::move(this->target->getPosition() - sf::Vector2f(this->target->getVelocity().x, 0) ));
    }

    if (this->target->isRightKeyPressed() && (this->target->getPosition().x + (this->target->getVelocity().x) <= this->x_right_constrains))
    {
        this->target->setPosition(std::move(this->target->getPosition() + sf::Vector2f(this->target->getVelocity().x,0)));
    }

    this->isJumping();

}


template<typename T>
Movement<T>::Movement(T& target)
{
    this->y_up_constrains = 700;
    this->y_botton_constrains = 560;
    this->x_left_constrains = 0;
    this->x_right_constrains = 1180;
    this->target = &target;
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



