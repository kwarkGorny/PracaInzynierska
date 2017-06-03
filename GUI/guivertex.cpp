#include "guivertex.h"
#include <QGraphicsEllipseItem>

GUIVertex::GUIVertex (const QRectF& rect, const QPen &pen, const QBrush &brush) : QGraphicsEllipseItem(rect)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
    setPen(pen);
    setBrush(brush);
}
void GUIVertex::addLine(QGraphicsLineItem *line)
{
    line->setLine(QLineF(centerPos(this->pos()), line->line().p2() ));
    lines.push_back(line);

}
QVariant GUIVertex::itemChange(const GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionChange && scene())
    {
        moveLinesToCenter(value.toPointF());

    }
    return QGraphicsItem::itemChange(change, value);
}
void GUIVertex::moveLinesToCenter(const QPointF newPos)
{
    // Converts the elipse position (top-left)
    // to its center position
    QPointF newCenterPos = centerPos(newPos);
    for(auto&line :lines)
    {
        // Move the required point of the line to the center of the elipse
        line->setLine(QLineF(newCenterPos, line->line().p2() ));
    }
}
