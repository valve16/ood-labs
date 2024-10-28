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
   
    //virtual bool IsSelected() const { return m_isSelected; }
    //virtual void SetSelected(bool selected) { m_isSelected = selected; }
    virtual bool IsPointInside(const sf::Vector2f& point) const = 0;
    virtual sf::FloatRect getBounds() const = 0;
    virtual void Move(const sf::Vector2f& offset) = 0;

    virtual ~IShape() = default;
//protected:
    //bool m_isSelected = false;
};


#endif // ISHAPE_H