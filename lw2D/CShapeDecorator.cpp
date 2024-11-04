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

bool CShapeDecorator::Contains(const sf::Vector2f& point) const {
    return m_shape->Contains(point);
}

void CShapeDecorator::Select() {
    m_shape->Select();
}

void CShapeDecorator::Deselect() {
    m_shape->Deselect();
}

void CShapeDecorator::DrawSelection(sf::RenderWindow& window) const {
    m_shape->DrawSelection(window);
}

void CShapeDecorator::Move(const sf::Vector2f& offset) 
{
    m_shape->Move(offset);
}