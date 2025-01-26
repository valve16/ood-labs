#include "FillOutlineVisitor.h"

FillOutlineVisitor::FillOutlineVisitor(sf::Color color) :m_color(color) {}

void FillOutlineVisitor::VisitFigure(std::shared_ptr<IShape> shape)
{
	shape->SetOutlineColor(m_color);
}