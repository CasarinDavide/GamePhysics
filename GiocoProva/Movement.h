#pragma once
#include <SFML/Graphics.hpp>



class Movement
{

    public:
        template<typename T>
        static void movementController(const sf::Event& e, T& target);
        template<typename T>
        static void movement(T& target,float deltatime);
        template<typename T>
        static void makeEnemyFall(T& target);

    private:
        static const int x_left_constrains = 0;
        static const int x_right_constrains = 1180;
        static const int y_botton_constrains   = 560;
        static const int y_up_constrains = 700;

        

};


template<typename T>
static void Movement::makeEnemyFall(T& target)
{
    if (target.isJumping() || (!target.isTouchingGround() && !target.isJumping()))
    {
        target.setVelocity(std::move(target.getVelocity() - sf::Vector2f(0,4.f)));
        target.setPosition(std::move(target.getPosition()- sf::Vector2f(0, target.getVelocity().y)));
    }


    if (target.getPosition().y == Movement::y_botton_constrains)
    {
        target.setVelocity(std::move(sf::Vector2f(3, 40)));
        target.setTouchingGround(true);
        target.setJumping(false);
    }

}


template<typename T>
static void Movement::movementController(const sf::Event& e,T& target)
{

    // CHECK If keyboard button is pressed
    if (e.type == sf::Event::KeyPressed)
    {
        if (e.key.code == sf::Keyboard::Left)
        {
            if (!target.isLeftKeyPressed())
            {
                target.setLeftKeyPressed(true);
            }
        }
        
        if (e.key.code == sf::Keyboard::Right)
        {
            if (!target.isRightKeyPressed())
            {
                target.setRightKeyPressed(true);
            }
            
        }
        
        if (e.key.code == sf::Keyboard::Space && target.isTouchingGround())
        {
            target.setTouchingGround(false);
            target.setJumping(true);
        }
    }

    // CHECK if keyboard button is released
    if (e.type == sf::Event::KeyReleased)
    {
        if (e.key.code == sf::Keyboard::Left)
        {
            target.setLeftKeyPressed(false);
        }
        
        if (e.key.code == sf::Keyboard::Right)
        {
            target.setRightKeyPressed(false);
        }
         
        if (e.key.code == sf::Keyboard::Space )
        {
            target.setJumping(false);
        }
    }
}

template<typename T>
static void Movement::movement(T& target, float deltatime)
{
    // MOVEMENTS
    if (target.isLeftKeyPressed() && (target.getPosition().x - (target.getVelocity().x) >= Movement::x_left_constrains))
    {
        target.setPosition(std::move(target.getPosition() - sf::Vector2f(target.getVelocity().x * deltatime * target.getPlayerSpeed(), 0)));
    }

    if (target.isRightKeyPressed() && (target.getPosition().x + (target.getVelocity().x) <= Movement::x_right_constrains))
    {
        target.setPosition(std::move(target.getPosition() + sf::Vector2f(target.getVelocity().x * deltatime * target.getPlayerSpeed(),0)));
    }

    Movement::makeEnemyFall(target);

}

