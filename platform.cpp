#include "platform.h"
#include "converter.h"
#include <box2d.h>
#include <SFML/Graphics.hpp>

Platform::Platform(sf::Vector2f position, sf::Vector2f size, b2World& world)
{
  //SFML setup
  platform.setFillColor(sf::Color::Black);
  platform.setPosition(position);
  platform.setSize(size);
  platform.setOrigin(size.x/2, size.y/2);

  //Box2D body setup
  b2BodyDef bodyDef{  };
  bodyDef.type = b2_staticBody;
  bodyDef.position.Set(position.x * Convert::pixelsToMeters,
                       position.y * Convert::pixelsToMeters);
  body = world.CreateBody(&bodyDef);

  //Box2D shape setup
  shape.SetAsBox(platform.getSize().x * Convert::pixelsToMeters * 0.5,
                 platform.getSize().y * Convert::pixelsToMeters * 0.5);


  //Box2D fixture setup
  fixtureDef.shape = &shape;
  fixtureDef.density = 1;
  fixtureDef.friction = 0.3;
  fixtureDef.restitution = 0.5;
  body->CreateFixture(&fixtureDef);
}

Platform::Platform(const Platform& platform)
  : shape{ platform.shape },
    fixtureDef{ platform.fixtureDef },
    platform{ platform.platform }
{
  body = platform.body;
}

void Platform::draw(sf::RenderWindow& targetWindow)
{
  targetWindow.draw(platform);
}

Platform& Platform::operator=(const Platform& platform)
{
  if(this != &platform)
  {
    body = platform.body;
    shape = platform.shape;
    fixtureDef = platform.fixtureDef;
    this->platform = platform.platform;
  }

  return *this;
}
