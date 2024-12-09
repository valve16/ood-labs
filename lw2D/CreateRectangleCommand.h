#pragma once
#include "Command.h"
#include "Toolbar.h"

class CreateRectangleCommand : public Command {
private:
    Toolbar* m_toolbar;

public:
    CreateRectangleCommand(Toolbar* toolbar) : m_toolbar(toolbar) {}

    void Execute() const override {
        m_toolbar->CreateRectangle();
    }
};