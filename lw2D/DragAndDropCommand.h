#pragma once
#include "Command.h"
#include "Toolbar.h"
class DragAndDropCommand : public Command {
private:
    Toolbar* m_toolbar;

public:
    DragAndDropCommand(Toolbar* toolbar) : m_toolbar(toolbar) {}

    void Execute() const override {
        m_toolbar->DragAndDrop();
    }
};