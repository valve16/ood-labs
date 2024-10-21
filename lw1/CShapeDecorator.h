#pragma once
#include "IShape.h"
#include "string"
#define _USE_MATH_DEFINES
#include <math.h>

class CShapeDecorator : public IShape 
{
public:
    CShapeDecorator(std::shared_ptr<IShape> shape);
    CShapeDecorator() {};
    virtual void Draw(sf::RenderWindow& window) const override;

    float GetArea() const;
    float GetPerimeter() const;

    virtual std::string ToString() const;

    virtual ~CShapeDecorator() = default;

protected:
    std::shared_ptr<IShape> m_shape;
    virtual float CalculatePerimeter() const = 0;
    virtual float CalculateArea() const = 0;
    void SetPerimeter();
    void SetArea();

private:
    float m_perimetr = 0.0f, m_area = 0.0f;
};