#include "SaveFileStrategy.h"
#include "Constants.h"

void SaveFileStrategy::WriteFiguresInfo(std::ostream& output, std::vector<std::shared_ptr<IShape>> figures) {
	for (auto& figure : figures) {
		if (typeid(*figure) == typeid(CCircle)) {
			output << GetCircleInfo(std::static_pointer_cast<CCircle>(figure));
		}
		else if (typeid(*figure) == typeid(CRectangle)) {
			output << GetRectangleInfo(std::static_pointer_cast<CRectangle>(figure));
		}
		else if (typeid(*figure) == typeid(CConvex)) {
			output << GetTriangleInfo(std::static_pointer_cast<CConvex>(figure));
		}
		else if (typeid(*figure) == typeid(CCompositeShape)) {
			output << GROUPED_TYPE << std::endl;
			WriteFiguresInfo(output, std::static_pointer_cast<CCompositeShape>(figure)->GetShapes());
			output << END_GROUP_TYPE << std::endl;
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

	stream << CIRCLE_TYPE << " " << center.x << " "
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

	stream << RECTANGLE_TYPE << " " << pointLT.x << " "
		<< pointLT.y << " " << pointRB.x << " " << pointRB.y << " "
		<< fillColor.toInteger() << " " << outlineColor.toInteger()
		<< " " << static_cast<int>(outlineThickness) << std::endl;

	return stream.str();
}

std::string SaveFileStrategy::GetTriangleInfo(std::shared_ptr<CConvex> triangle) {
	auto triangleShape = triangle->GetConvex();

	auto point0 = triangleShape.getPoint(FIRST_POINT);
	auto point1 = triangleShape.getPoint(SECOND_POINT);
	auto point2 = triangleShape.getPoint(THIRD_POINT);

	auto position = triangleShape.getPosition();
	auto fillColor = triangleShape.getFillColor();
	auto outlineColor = triangleShape.getOutlineColor();
	auto outlineThickness = triangleShape.getOutlineThickness();

	std::stringstream stream;

	stream << TRIANGLE_TYPE_H << " "
		<< point0.x << " " << point0.y << " "
		<< point1.x << " " << point1.y << " "
		<< point2.x << " " << point2.y << " "
		<< position.x << " " << position.y << " "
		<< fillColor.toInteger() << " " << outlineColor.toInteger()
		<< " " << static_cast<int>(outlineThickness) << std::endl;

	return stream.str();
}
