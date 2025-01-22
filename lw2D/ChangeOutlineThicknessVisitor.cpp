#include "ChangeOutlineThicknessVisitor.h"

ChangeOutlineThicknessVisitor::ChangeOutlineThicknessVisitor(float thickness) :m_thickness(thickness) {}

void ChangeOutlineThicknessVisitor::VisitFigure(std::shared_ptr<IShape> decorator) 
{	
	std::cout << (m_thickness);
	decorator->SetOutlineThickness(m_thickness);
}