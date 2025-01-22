#pragma once

#include "IVisitor.h"

class ChangeOutlineThicknessVisitor : public IVisitor {
public:
	ChangeOutlineThicknessVisitor(float thickness);
	void VisitFigure(std::shared_ptr<IShape> decorator) override;
private:
	float m_thickness;
};