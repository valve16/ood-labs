#pragma once

#include "CFiguresHandler.h"

class Button;
class State;


class Toolbar {

public:
    Toolbar(State* state, sf::RenderWindow& window, CFiguresHandler* figureHandler);

    void SetCursorPosition(const sf::Vector2i& position);
    bool PressToolButton() const;
    

    void AddOutlineThickness();
    void ReduceOutlineThickness();
    float GetOutlineThickness() const;

    void DragAndDrop();
    void FillShape();
    void FillOutline();

    void SetState(State* state);
    State* GetState() const;

    void SetColor(const sf::Color& newColor) ;
    sf::Color GetColor() const;

    //void SetOutlineColor(const sf::Color& newColor);

    void CreateRectangle();
    void CreateTriangle();
    void CreateCircle();

    void Draw();

    CFiguresHandler* figureHandler;
private:
    std::vector<Button*> m_buttons;
    sf::RenderWindow& window;

    State* m_state;
    sf::Vector2i cursorPosition;

    float outlineThickness = 0.0f;
    sf::Color m_color = sf::Color::Red;
};
