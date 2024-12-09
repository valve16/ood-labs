#pragma once

#include "CFiguresHandler.h"

class Button;
class State;


class Toolbar {

public:
    Toolbar(State* state, sf::RenderWindow& window, CFiguresHandler* figureHandler);

    void SetCursorPosition(const sf::Vector2i& position);
    

    void AddOutlineThickness();

    void ReduceOutlineThickness();

    void DragAndDrop();

    void FillShape();

    void FillOutline();

    void SetColor(const sf::Color& newColor) ;

    //void SetOutlineColor(const sf::Color& newColor);

    void CreateRectangle();
    void CreateTriangle();
    void CreateCircle();
    void SetState(State* state);

    State* GetState() const;

    sf::Color GetColor() const;
    float GetOutlineThickness() const;

    bool PressToolButton() const;


    void Draw();

    CFiguresHandler* figureHandler;
private:
    std::vector<Button*> m_buttons;
    sf::RenderWindow& window;

    State* m_state;
    sf::Vector2i cursorPosition;

    float outlineThickness = 0.0f;
    sf::Color color = sf::Color::Red;
};
