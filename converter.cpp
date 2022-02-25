#include "converter.h"
#include <box2d.h>
#include <SFML/Graphics.hpp>
#include <cmath>

namespace Convert
{
  extern const double pixelsToMeters{ 0.1 };
  extern const double metersToPixels{ 1 / pixelsToMeters };
  extern const double radiansToDegrees{ 180 / M_PI };

  sf::Vector2f Vec2ToVector2f(b2Vec2 vec2)
  {
    return sf::Vector2f(vec2.x, vec2.y);
  }

  b2Vec2 Vector2fToVec2(sf::Vector2f vector2f)
  {
    return b2Vec2(vector2f.x, vector2f.y);
  }
}
