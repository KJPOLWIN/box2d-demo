#ifndef PLATFORM_H
#define PLATFORM_H

  #include <box2d.h>
  #include <SFML/Graphics.hpp>

  class Platform
  { 
    public:
      Platform(sf::Vector2f position, sf::Vector2f size, b2World& world);
      Platform(const Platform& platform);

      void draw(sf::RenderWindow& targetWindow);

      Platform& operator=(const Platform& platform); 

      b2Body* body{ nullptr };
      b2PolygonShape shape{  };
      b2FixtureDef fixtureDef{  };

      sf::RectangleShape platform{  };
  };

#endif
