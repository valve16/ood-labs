#pragma once

#include "IShape.h"

class IVisitor {
public:
	virtual void VisitFigure(std::shared_ptr<IShape> decorator) = 0;
};