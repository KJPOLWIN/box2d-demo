#ifndef CONVERTER_H
#define CONVERTER_H

  #include <box2d.h>
  #include <SFML/Graphics.hpp>
  #include <cmath>

  namespace Convert
  {
    //++ consts; see .cpp file
    extern const double pixelsToMeters;
    extern const double metersToPixels;
    extern const double radiansToDegrees;

    sf::Vector2f Vec2ToVector2f(b2Vec2 vec2);
    b2Vec2 Vector2fToVec2(sf::Vector2f vector2f);
  }

#endif
