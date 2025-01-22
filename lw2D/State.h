#pragma once
class Toolbar;

class State {
public:
    virtual ~State() = default;

    virtual void DragAndDrop(Toolbar* toolbar) const = 0;
    virtual void FillShape(Toolbar* toolbar) const = 0;
    virtual void FillOutline(Toolbar* toolbar) const = 0;
};

