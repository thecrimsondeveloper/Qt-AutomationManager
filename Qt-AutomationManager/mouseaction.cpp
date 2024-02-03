#include "mouseaction.h"
#include <iostream> // Include for testing purposes

MouseAction::MouseAction() {
    // Constructor implementation
}

//use polymorphism to handle different types of mouse actions
void MouseAction::OnInvoke(MouseActionData data) {
    // Check the type of MouseActionData
    if (dynamic_cast<MouseClickData*>(&data) != nullptr) {
        // If it's MouseClickData, call Click method
        MouseClickData* clickData = dynamic_cast<MouseClickData*>(&data);
        if (clickData) {
            Click(clickData->Point);
        }
    } else if (dynamic_cast<MouseClickAndDragData*>(&data) != nullptr) {
        // If it's MouseClickAndDragData, call ClickAndDrag method
        MouseClickAndDragData* dragData = dynamic_cast<MouseClickAndDragData*>(&data);
        if (dragData) {
            ClickAndDrag(dragData->StartPoint, dragData->EndPoint, dragData->Delay, dragData->Steps);
        }
    } else {
        // Unknown type
        std::cerr << "Unknown MouseActionData type!" << std::endl;
    }
}

void MouseAction::Click(QPoint point) {
    // Click method implementation
    std::cout << "Clicking at point: (" << point.x() << ", " << point.y() << ")" << std::endl;
}

void MouseAction::ClickAndDrag(QPoint startPoint, QPoint endPoint, int delay, int steps) {
    // ClickAndDrag method implementation
    std::cout << "Dragging from point: (" << startPoint.x() << ", " << startPoint.y() << ") to point: ("
              << endPoint.x() << ", " << endPoint.y() << "), with delay: " << delay << " and steps: " << steps << std::endl;
}
