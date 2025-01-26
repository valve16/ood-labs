#pragma once
#include "IShape.h"
#include "CCircle.h"
#include "CRectangle.h"
#include "CConvex.h"
#include "CCompositeShape.h"
#include <sstream>
#include <fstream>


class SaveFileStrategy {
public:
	virtual void Save(std::string filename, std::vector<std::shared_ptr<IShape>> figures) = 0;
protected:
	void WriteFiguresInfo(std::ostream& output, std::vector <std::shared_ptr<IShape>> figures);
	std::string GetCircleInfo(std::shared_ptr<CCircle> circleDecorator);
	std::string GetRectangleInfo(std::shared_ptr<CRectangle> rectangle);
	std::string GetTriangleInfo(std::shared_ptr<CConvex> triangle);
};