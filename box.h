#ifndef BOX_H
#define BOX_H
  
  #include <box2d.h>
  #include <SFML/Graphics.hpp>

  class Box
  {
    public:
      Box(sf::Vector2f position, b2World& world);
      Box(const Box& box);

      void update();
      void draw(sf::RenderWindow& targetWindow);
      
      Box& operator=(const Box& box);

      b2Body* body{ nullptr };
      b2PolygonShape shape{  };
      b2FixtureDef fixtureDef{  };

      sf::Vector2f position{  };
      sf::Vector2f size{  };
      sf::RectangleShape box{  };
  };

#endif
