#pragma once
#include "Command.h"
#include "Toolbar.h"

class SetRedColorCommand : public Command {
private:
    Toolbar* m_toolbar;

public:
    SetRedColorCommand(Toolbar* toolbar) : m_toolbar(toolbar) {}

    void Execute() const override {
        m_toolbar->SetColor(sf::Color::Red);
    }
};