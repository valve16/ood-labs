#include "IShape.h"
#include "CCircle.h"
#include "CConvex.h"
#include "CRectangle.h"
#include "CCompositeShape.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <vector>
#pragma once
#include <string>
#include <iostream>
#include "CFiguresHandler.h"
#include "ToolBar.h"
#include "DnDState.h"


class ShapeOp
{

public:

	static ShapeOp& GetInstance(sf::RenderWindow& window);

	std::vector<std::shared_ptr<IShape>> ReadShapesFromFileToVector(const std::string& filename);
	void RenderShapesFromVector(std::vector<std::shared_ptr<IShape>>& shapes);

	// add branch
private:
    void DrawApplication();
    ShapeOp(sf::RenderWindow& window);
    ~ShapeOp();
    ShapeOp(const ShapeOp&) = delete;
    ShapeOp& operator=(const ShapeOp&) = delete;

    sf::RenderWindow& m_window;
    std::string m_filename;
    Toolbar* m_toolbar;
    CFiguresHandler* m_figuresHandler;

};