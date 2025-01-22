#include "SaveFileStrategy.h"

void SaveFileStrategy::WriteFiguresInfo(std::ostream& output, std::vector<std::shared_ptr<IShape>> figures) {
	for (auto& figure : figures) {
		if (typeid(*figure) == typeid(CCircle)) {
			std::cout << "cir";
			output << GetCircleInfo(std::static_pointer_cast<CCircle>(figure));
		}
		else if (typeid(*figure) == typeid(CRectangle)) {
			std::cout << "rec";
			output << GetRectangleInfo(std::static_pointer_cast<CRectangle>(figure));
		}
		else if (typeid(*figure) == typeid(CConvex)) {
			std::cout << "con";
			output << GetTriangleInfo(std::static_pointer_cast<CConvex>(figure));
		}
		else if (typeid(*figure) == typeid(CCompositeShape)) {
			output << "grouped" << std::endl;
			WriteFiguresInfo(output, std::static_pointer_cast<CCompositeShape>(figure)->GetShapes());
			output << "endGrouped" << std::endl;
		}
	}
}

std::string SaveFileStrategy::GetCircleInfo(std::shared_ptr<CCircle> circle) {
	auto circleShape = circle->GetCircle();

	auto position = circleShape.getPosition();
	auto radius = circleShape.getRadius();
	sf::Vector2f center = { position.x + radius, position.y + radius };
	auto outlineThickness = circleShape.getOutlineThickness();
	auto fillColor = circleShape.getFillColor();
	auto outlineColor = circleShape.getOutlineColor();

	std::stringstream stream;

	stream << "circle" << " " << center.x << " "
		<< center.y << " " << static_cast<int>(radius) << " "
		<< fillColor.toInteger() << " " << outlineColor.toInteger()
		<< " " << static_cast<int>(outlineThickness) << std::endl;

	return stream.str();
}

std::string SaveFileStrategy::GetRectangleInfo(std::shared_ptr<CRectangle> rectangle) {
	auto rectangleShape = rectangle->GetRectangle();

	//auto rectangleBounds = rectangleShape.GetGlobalBounds();

	auto pointLT = rectangleShape.getPosition();
	auto outlineThickness = rectangleShape.getOutlineThickness();
	sf::Vector2f pointRB = {
		(pointLT.x + rectangleShape.getSize().x - 2 * outlineThickness),
		(pointLT.y + rectangleShape.getSize().y - 2 * outlineThickness) };
	auto fillColor = rectangleShape.getFillColor();
	auto outlineColor = rectangleShape.getOutlineColor();

	std::stringstream stream;

	stream << "rectangle" << " " << pointLT.x << " "
		<< pointLT.y << " " << pointRB.x << " " << pointRB.y << " "
		<< fillColor.toInteger() << " " << outlineColor.toInteger()
		<< " " << static_cast<int>(outlineThickness) << std::endl;

	return stream.str();
}

std::string SaveFileStrategy::GetTriangleInfo(std::shared_ptr<CConvex> triangle) {
	auto triangleShape = triangle->GetConvex();

	auto point0 = triangleShape.getPoint(0);
	auto point1 = triangleShape.getPoint(1);
	auto point2 = triangleShape.getPoint(2);

	auto position = triangleShape.getPosition();
	auto fillColor = triangleShape.getFillColor();
	auto outlineColor = triangleShape.getOutlineColor();
	auto outlineThickness = triangleShape.getOutlineThickness();

	std::stringstream stream;

	stream << "triangle" << " "
		<< point0.x << " " << point0.y << " "
		<< point1.x << " " << point1.y << " "
		<< point2.x << " " << point2.y << " "
		<< position.x << " " << position.y << " "
		<< fillColor.toInteger() << " " << outlineColor.toInteger()
		<< " " << static_cast<int>(outlineThickness) << std::endl;

	return stream.str();
}
