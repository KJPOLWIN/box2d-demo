#include "box.h"
#include <SFML/Graphics.hpp>
#include <box2d.h>
#include <vector>

int main()
{
  sf::RenderWindow window{ sf::VideoMode(800, 600), "Box2D demo" };
  window.setFramerateLimit(60);
  
  b2Vec2 gravity{ 0.0, 15.0 };
  b2World world{ gravity };

  std::vector<Box> boxes{  };

  sf::Event event;
  while(window.isOpen())
  {
    while(window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
      {
        window.close();
      }
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
      boxes.push_back( Box(sf::Vector2f(sf::Mouse::getPosition(window)), world) );
    } 

    world.Step(1.0 / 60.0, 8, 3);

    for(std::vector<Box>::iterator it{ boxes.begin() }; it < boxes.end(); ++it)
    {
      it->update();

      if(it->position.y > 600)
      {
        boxes.erase(it);
      }
    }

    window.clear(sf::Color::White);
    for(auto& box : boxes)
    {
      box.draw(window);
    }
    window.display();
  }


  return 0;
}
