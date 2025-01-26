#include "ChangeOutlineThicknessVisitor.h"

ChangeOutlineThicknessVisitor::ChangeOutlineThicknessVisitor(float thickness) :m_thickness(thickness) {}

void ChangeOutlineThicknessVisitor::VisitFigure(std::shared_ptr<IShape> shape) 
{	
	//std::cout << (m_thickness);
	shape->SetOutlineThickness(m_thickness);
}