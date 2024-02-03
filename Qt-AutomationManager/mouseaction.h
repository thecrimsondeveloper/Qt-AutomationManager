#ifndef MOUSEACTION_H
#define MOUSEACTION_H

#include "useraction.h"
#include <QPoint> // Include the header file for QPoint

// Forward declaration of MouseActionData struct
struct MouseActionData;

class MouseAction : public UserAction<MouseActionData>
{
public:
    MouseAction();
protected:
    virtual void OnInvoke(MouseActionData data);
private:
    static void Click(QPoint point);
    static void ClickAndDrag(QPoint startPoint, QPoint endPoint, int delay, int steps);
};

struct MouseActionData
{
    MouseActionData();
    MouseActionData(int id);
    virtual ~MouseActionData() {} // Add a virtual destructor
    int ID;
};

struct MouseClickData : MouseActionData
{
    MouseClickData();
    MouseClickData(QPoint point);
    QPoint Point;
};

struct MouseClickAndDragData : MouseActionData
{
    MouseClickAndDragData();
    MouseClickAndDragData(MouseAction* action, int id, QPoint startPoint, QPoint endPoint, int delay, int steps);
    QPoint StartPoint;
    QPoint EndPoint;
    int Delay;
    int Steps;
};



#endif // MOUSEACTION_H

