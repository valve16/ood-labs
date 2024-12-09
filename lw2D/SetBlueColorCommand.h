#pragma once
#include "Command.h"
#include "Toolbar.h"

class SetBlueColorCommand : public Command {
private:
    Toolbar* m_toolbar;

public:
    SetBlueColorCommand(Toolbar* toolbar) : m_toolbar(toolbar) {}

    void Execute() const override {
        m_toolbar->SetColor(sf::Color::Blue);
    }
};