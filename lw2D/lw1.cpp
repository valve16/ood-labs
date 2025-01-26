
#include "IShape.h"
#include "ShapeOp.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include "SaveTextFileStrategy.h"
#include "SaveBinStrategy.h"
#include "Constants.h"
using namespace sf;


int main()
{
    RenderWindow window(VideoMode(WIDTH_WINDOW, HEIGHT_WINDOW), PROJECT_NAME, Style::Default);
    window.setVerticalSyncEnabled(true);

    ShapeOp& operations = ShapeOp::GetInstance(window);

    std::vector<std::shared_ptr<IShape>> shapes;
    shapes = operations.ReadShapesFromFileToVector(INPUT_FILE);
    operations.RenderShapesFromVector(shapes);

    CSaveTextFileStrategy textSaver;
    std::cout << shapes.size();
    textSaver.Save(OUT_TXT_FILE, shapes);

    CSaveBinStrategy binSaver;
    binSaver.Save(OUT_BIN_FILE, shapes);

    return 0;
}