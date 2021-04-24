#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main() {
    
    RenderWindow window(VideoMode(600, 400), "Vector Paint Init", Style::Close | Style::Titlebar | Style::Resize);
    sf::RectangleShape rect(sf::Vector2f(30.0f, 30.0f));
    rect.setFillColor(sf::Color::Green);
    rect.setOrigin(15.0f, 15.0f);

    while (window.isOpen())
    {
        sf::Event evnt;
        while(window.pollEvent(evnt)) {
            
            switch (evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                cout<<"Width: "<<evnt.size.width<<" Height: "<<evnt.size.height<<endl;
                // printf("New Width: %i New Height: %i\n", evnt.size.width, evnt.size.height);
                break;

            case sf::Event::TextEntered:
                if (evnt.text.unicode < 128) {
                    printf("%c", evnt.text.unicode);
                }
            default:
                break;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
            rect.move(-0.1f, 0.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
            rect.move(0.1f, 0.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
            rect.move(0.0f, -0.1f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
            rect.move(0.0f, 0.1f);
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mouseP = ::Mouse::getPosition(window);
            rect.setPosition((float)mouseP.x, static_cast<float>(mouseP.y));
            printf("x: %i y: %i", mouseP.x, mouseP.y);

        }   
        window.draw(rect);
        window.display();
        // window.clear();

    }
    return 0;
}
