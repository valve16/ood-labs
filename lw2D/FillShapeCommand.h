#pragma once
#include "Command.h"
#include "Toolbar.h"

class FillShapeCommand : public Command {
private:
    Toolbar* m_toolbar;

public:
    FillShapeCommand(Toolbar* toolbar) : m_toolbar(toolbar) {}

    void Execute() const override {
        m_toolbar->FillShape();
    }
};