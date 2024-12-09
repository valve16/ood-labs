#pragma once
#include "Command.h"
#include "Toolbar.h"

class SetGreenColorCommand : public Command {
private:
    Toolbar* m_toolbar;

public:
    SetGreenColorCommand(Toolbar* toolbar) : m_toolbar(toolbar) {}

    void Execute() const override {
        m_toolbar->SetColor(sf::Color::Green);
    }
};