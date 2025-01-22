#include "Button.h"


Button::Button(
    Vector2f position, Vector2f sizeRectangle,
    Color buttonColor, Command* command, std::string text,
    int fontSize, Shape* shape, Color textColor
) :m_command(command), m_shape(shape) {
    m_rectangle.setPosition(position);
    m_rectangle.setSize(sizeRectangle);
    m_rectangle.setFillColor(buttonColor);

    if (m_font.loadFromFile("arialmt.ttf")) {
        m_text.setFont(m_font);
        m_text.setString(text);
        m_text.setFillColor(textColor);
        m_text.setCharacterSize(fontSize);
        m_text.setPosition(position);
    }
}

void Button::Draw(RenderWindow& window) {
    window.draw(m_rectangle);
    window.draw(m_text);
    window.draw(*m_shape);
}

void Button::SetCommand(Command* command) {
    m_command = command;
}

bool Button::CursorInButton(Vector2f cursorPos) const 
{
    return m_rectangle.getGlobalBounds().contains(cursorPos);
}

void Button::PressButton() {
    m_command->Execute();
}