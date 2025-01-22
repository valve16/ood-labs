#include "IShape.h"
#include "CCircle.h"
#include "CConvex.h"
#include "CRectangle.h"
#include "CShapeDecorator.h"
#include "CCircleDecorator.h"
#include "CRectangleDecorator.h"
#include "CTriangleDecorator.h"
#include "CCompositeShape.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
<<<<<<< Updated upstream

=======
#include "CFiguresHandler.h"
#include "ToolBar.h"
#include "DnDState.h"
#include "FillOutlineState.h"
#include "FillShapeState.h"
#include "FillVisitor.h"
#include "FillOutlineVisitor.h"
#include "ChangeOutlineThicknessVisitor.h"
>>>>>>> Stashed changes

class ShapeOp
{
public:
	ShapeOp(const std::string& filename, sf::RenderWindow& window);
	std::vector<std::shared_ptr<IShape>> ReadShapesFromFileToVector(const std::string& filename);
	void RenderShapesFromVector(std::vector<std::shared_ptr<IShape>>& shapes);
	void WriteShapesToFile(std::vector<std::shared_ptr<IShape>>& shapes, const std::string& filename);
private:
	sf::RenderWindow& m_window;
	std::string m_filename;
};