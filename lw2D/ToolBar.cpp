#include "State.h"
#include "DragAndDropCommand.h"
#include "CreateRectangleCommand.h"
#include "CreateTriangleCommand.h"
#include "CreateCircleCommand.h"
#include "FillShapeCommand.h"
#include "FillOutlineCommand.h"
#include "ReduceThicknessCommand.h"
#include "AddOutlineThicknessCommand.h"
#include "SetRedColorCommand.h"
#include "SetGreenColorCommand.h"
#include "SetBlueColorCommand.h"
#include <memory>
#include "Button.h"
#include "DnDState.h"
#include "FillShapeState.h"
#include "FillOutlineState.h"

const int BTN_WIDTHS = 48;
const int BTN_HEIGHTS = 194;
const int BTN_WIDTH = 36;
const int BTN_HEIGHT = 90;

Toolbar::Toolbar(State* state, sf::RenderWindow& window, CFiguresHandler* figureHandler)
    : window(window), figureHandler(figureHandler), m_state(state) {

    m_buttons.push_back(new Button(Vector2f(643, 10), Vector2f(BTN_HEIGHTS, BTN_WIDTHS), Color::White, new DragAndDropCommand(this), "Drag&Drop", 20));
    m_buttons.push_back(new Button(Vector2f(851, 10), Vector2f(BTN_HEIGHTS, BTN_WIDTHS), Color::White, new FillShapeCommand(this), "Fill shape", 20));
    m_buttons.push_back(new Button(Vector2f(1064, 10), Vector2f(BTN_HEIGHTS, BTN_WIDTHS), Color::White, new FillOutlineCommand(this), "Fill outline", 20));
    //m_buttons.push_back(new Button(Vector2f(1287, 10), Vector2f(BTN_HEIGHTS, BTN_WIDTHS), Color::White, new ChangeOutlineThicknessCommand(this), "Change thickness", 20));

    m_buttons.push_back(new Button(Vector2f(19, 68), Vector2f(BTN_HEIGHT, BTN_WIDTH), Color::Red, new SetRedColorCommand(this)));
    m_buttons.push_back(new Button(Vector2f(143, 68), Vector2f(BTN_HEIGHT, BTN_WIDTH), Color::Green, new SetGreenColorCommand(this)));
    m_buttons.push_back(new Button(Vector2f(267, 68), Vector2f(BTN_HEIGHT, BTN_WIDTH), Color::Blue, new SetBlueColorCommand(this)));

    m_buttons.push_back(new Button(Vector2f(1053, 68), Vector2f(212, BTN_WIDTH), Color::White, new ReduceThicknessCommand(this)));
    m_buttons.push_back(new Button(Vector2f(1269, 68), Vector2f(212, BTN_WIDTH), Color::White, new AddOutlineThicknessCommand(this)));

    m_buttons.push_back(new Button(Vector2f(19, 10), Vector2f(BTN_HEIGHTS, BTN_WIDTHS), Color::White, new CreateCircleCommand(this), "Create Circle", 20));
    m_buttons.push_back(new Button(Vector2f(435, 10), Vector2f(BTN_HEIGHTS, BTN_WIDTHS), Color::White, new CreateRectangleCommand(this), "Create Rectangle", 20));
    m_buttons.push_back(new Button(Vector2f(227, 10), Vector2f(BTN_HEIGHTS, BTN_WIDTHS), Color::White, new CreateTriangleCommand(this), "Create Triangle", 20));
}

void Toolbar::SetCursorPosition(const sf::Vector2i& position) {
    cursorPosition = position;
}

//void Toolbar::SetFiguresCreateVisible() {
//    for (auto button : m_buttons) {
//        if (button.GetId() == 2) {
//            button.SetVisibleState();
//        }
//    }
//}

void Toolbar::AddOutlineThickness() {
    //if (outlineThickness < 5.0f) {
        outlineThickness++;
    //}
    figureHandler->SetThickness(outlineThickness);
}

void Toolbar::ReduceOutlineThickness() {
    if (outlineThickness > 0.0f) {
        outlineThickness--;
    };
    figureHandler->SetThickness(outlineThickness);
}

void Toolbar::DragAndDrop() {
    if (m_state) {
        m_state->DragAndDrop(this);
    }
}

void Toolbar::FillShape() {
    if (m_state) {
        m_state->FillShape(this);
    }
}

void Toolbar::FillOutline() {
    if (m_state) {
        m_state->FillOutline(this);
    }
}

void Toolbar::SetColor(const sf::Color& newColor) {
    if (typeid(*m_state) == typeid(FillShapeState))
    {
        color = newColor;
        figureHandler->SetFillColor(color);
        std::cout << "Color set to: " << color.toInteger() << std::endl;
    }
    else if (typeid(*m_state) == typeid(FillOutlineState))
    {
        color = newColor;
        figureHandler->SetOutlineColor(color);
    }
}

//void Toolbar::SetOutlineColor(const sf::Color& newColor) {
//    if (typeid(*m_state) == typeid(FillOutlineState))
//    {
//        color = newColor;
//        figureHandler->SetOutlineColor(color);
//    }
//}



void Toolbar::CreateRectangle() {
    figureHandler->CreateRectangleFigure();
}

void Toolbar::CreateTriangle() {
    figureHandler->CreateTriangleFigure();
}

void Toolbar::CreateCircle() {
    figureHandler->CreateCircleFigure();
}

void Toolbar::SetState(State* state) {
    m_state = state;

}

State* Toolbar::GetState() const {
    return m_state;
}

sf::Color Toolbar::GetColor() const {
    return color;
}

float Toolbar::GetOutlineThickness() const {
    return outlineThickness;
}

bool Toolbar::PressToolButton() const {
    for (auto button : m_buttons) {
        sf::Vector2f cursorPositionFloat(cursorPosition);
        if (button->CursorInButton(cursorPositionFloat)) {
            button->PressButton();
            return true;
        }
    }

    return false;
}

void Toolbar::Draw() {
    for (auto button : m_buttons) {
        button->Draw(window);
    }
}

//void Toolbar::SetChangeThicknessVisible() {
//    for (auto& button : m_buttons) {
//        if (button.GetId() == 6) {
//            button.SetVisibleState();
//        }
//    }
//}
//
