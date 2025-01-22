#pragma once
#include "Command.h"
#include "Toolbar.h"
class CreateTriangleCommand : public Command {
private:
    Toolbar* m_toolbar;

public:
    CreateTriangleCommand(Toolbar* toolbar) : m_toolbar(toolbar) {}

    void Execute() const override {
        m_toolbar->CreateTriangle();
    }
};