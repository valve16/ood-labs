#include "CShapeDecorator.h"
#include "CCircle.h"
#include "CConvex.h"
#include "CRectangle.h"
#define _USE_MATH_DEFINES
#include <math.h>

CShapeDecorator::CShapeDecorator(std::shared_ptr<IShape> shape)
	: m_shape(std::move(shape)) 
{
}

void CShapeDecorator::Draw(sf::RenderWindow& window) const 
{
    m_shape->Draw(window);
}

float CShapeDecorator::GetArea() const
{
    return m_area;
}

float CShapeDecorator::GetPerimeter() const
{
    return m_perimetr;
}

std::string CShapeDecorator::ToString() const
{
    std::ostringstream iss;
    iss << m_shape->ToString() << ": P=" << GetPerimeter() << "; S=" << GetArea();
    return iss.str();
}

void CShapeDecorator::SetPerimeter()
{
    m_perimetr = CalculatePerimeter();
}

void CShapeDecorator::SetArea()
{
    m_area = CalculateArea();
}