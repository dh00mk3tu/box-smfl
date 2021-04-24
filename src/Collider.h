#pragma once //
#include <SFML/Graphics.hpp>


class Collider {
    public: 
        Collider();
        ~Collider();

    private: 
        sf::RectangleShape& body;
        
};