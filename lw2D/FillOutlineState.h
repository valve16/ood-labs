#pragma once
#include "State.h"

class FillOutlineState : public State {
public:
    void DragAndDrop(Toolbar* toolbar) const override;

    void FillShape(Toolbar* toolbar) const override;

    void FillOutline(Toolbar* toolbar) const override;
};