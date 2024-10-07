#include "IShape.h"
#include "CCircle.h"
#include "CConvex.h"
#include "CRectangle.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
class ShapeOp
{
public:
	ShapeOp(const std::string& filename, sf::RenderWindow& window);
	std::vector<IShape*> ReadShapesFromFileToVector(const std::string& filename);
	void RenderShapesFromVector(std::vector<IShape*>& shapes);
private:
	sf::RenderWindow& m_window;
	std::string m_filename;
};