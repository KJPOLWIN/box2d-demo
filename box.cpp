#include "box.h"
#include "converter.h"
#include <SFML/Graphics.hpp>

Box::Box(sf::Vector2f position, b2World& world)
  : position{ position },
    size{ 16, 16 },
    box{ size }
{
  //SFML rectangle setup
  box.setFillColor(sf::Color(100, 100, 100));
  box.setOutlineColor(sf::Color::Black);
  box.setOutlineThickness(2);
  box.setOrigin(sf::Vector2f(box.getSize().x * 0.5,
                             box.getSize().y * 0.5));
  box.setPosition(position);

  //Box2D body setup
  b2BodyDef bodyDef{  };
  bodyDef.type = b2_dynamicBody;
  //bodyDef.position.Set(1.0, 1.0);
  bodyDef.position.Set(position.x * Convert::pixelsToMeters, 
                       position.y * Convert::pixelsToMeters);
  body = world.CreateBody(&bodyDef);

  //Box2D shape setup
  shape.SetAsBox(box.getSize().x * Convert::pixelsToMeters * 0.5, 
                 box.getSize().y * Convert::pixelsToMeters * 0.5);
  
  //Box2D fixture setup
  fixtureDef.shape = &shape;
  fixtureDef.density = 1;
  fixtureDef.friction = 0.3;
  fixtureDef.restitution = 0.5;
  body->CreateFixture(&fixtureDef);
}

Box::Box(const Box& box)
  : shape{ box.shape },
    fixtureDef{ box.fixtureDef },
    position{ box.position },
    size{ box.size },
    box{ box.box }
{
  //body = new b2Body(*box.body);
  body = box.body;
}

void Box::update()
{
  position = sf::Vector2f(body->GetPosition().x * Convert::metersToPixels,
                          body->GetPosition().y * Convert::metersToPixels);
  box.setPosition(position);
  box.setRotation(body->GetAngle() * Convert::radiansToDegrees);
}

void Box::draw(sf::RenderWindow& targetWindow)
{
  targetWindow.draw(box);
}

Box& Box::operator=(const Box& box)
{
  if(this != &box)
  {
    body = box.body;
    shape = box.shape;
    fixtureDef = box.fixtureDef;
    position = box.position;
    size = box.size;
    this->box = box.box;
  }

  return *this;
}
