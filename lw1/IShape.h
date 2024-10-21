#ifndef ISHAPE_H  // ������ �� ���������� ���������
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
    virtual std::string ToString() const = 0;
    virtual void Draw(sf::RenderWindow& window) const = 0;
    virtual ~IShape() = default;
};

#endif // ISHAPE_H