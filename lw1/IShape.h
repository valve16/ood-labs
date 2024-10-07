#ifndef ISHAPE_H  // Защита от повторного включения
#define ISHAPE_H

#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

class IShape {
public:
    virtual ~IShape() = default;
    virtual void Draw(sf::RenderWindow& window) const = 0;
};

#endif // ISHAPE_H