#include "FillOutlineState.h"
#include "ToolBar.h"
#include "DnDState.h"
#include "FillShapeState.h"

void FillOutlineState::DragAndDrop(Toolbar* toolbar) const {
    toolbar->SetState(new DragAndDropState());
}

void FillOutlineState::FillShape(Toolbar* toolbar) const {
    toolbar->SetState(new FillShapeState());
}

void FillOutlineState::FillOutline(Toolbar* toolbar) const {

}
