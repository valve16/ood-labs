#ifndef ISHAPE_H  // Защита от повторного включения
#define ISHAPE_H

#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

class IShape 
{
public:
    virtual std::string ToString() const = 0;
    virtual void Draw(sf::RenderWindow& window) const = 0;
    virtual bool Contains(const sf::Vector2f& point) const = 0;

    virtual ~IShape() = default;
    virtual void Select() = 0;
    virtual void Deselect() = 0;

    bool IsSelected() { return m_isSelected; };

    virtual void DrawSelection(sf::RenderWindow& window) const = 0;

    virtual void Move(const sf::Vector2f& offset) = 0;

protected:
    bool m_isSelected = false;
};


#endif // ISHAPE_H