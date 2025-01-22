#pragma once
#include <optional>
#include "Command.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace sf;

class Button {

public:
    Button(
        Vector2f position, Vector2f sizeRectangle,
        Color buttonColor, Command* command, std::string text = "",
        int fontSize = 0,
        Shape* shape = new CircleShape,
        Color textColor = Color::Black
    );

    void Draw(RenderWindow& window);
    void SetCommand(Command* command);
    bool CursorInButton(Vector2f cursorPos) const;
    void PressButton();
private:
    RectangleShape m_rectangle;
    Text m_text;
    Font m_font;
    Shape* m_shape;
    Command* m_command;

};