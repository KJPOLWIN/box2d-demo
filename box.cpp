#include "box.h"
#include <SFML/Graphics.hpp>
#include <cmath>

constexpr double pixelsToMeters{ 0.1 };
constexpr double metersToPixels{ 10 };
constexpr double radiansToDegrees{ 180 / M_PI };


sf::Vector2f Vec2ToVector2f(b2Vec2 vec2)
{
  return sf::Vector2f(vec2.x, vec2.y);
}

b2Vec2 Vector2fToVec2(sf::Vector2f vector2f)
{
  return b2Vec2(vector2f.x, vector2f.y);
}

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
  bodyDef.position.Set(position.x * pixelsToMeters, position.y * pixelsToMeters);
  body = world.CreateBody(&bodyDef);

  //Box2D shape setup
  shape.SetAsBox(0.8, 0.8);
  
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
  position = sf::Vector2f(body->GetPosition().x * metersToPixels,
                          body->GetPosition().y * metersToPixels);
  box.setPosition(position);
  box.setRotation(body->GetAngle() * radiansToDegrees);
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
