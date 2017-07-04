#include "guihyperedge.h"

GUIHyperEdge::GUIHyperEdge(const QRectF &rect, const QPen &pen,
                           const QBrush &brush)
    : QGraphicsRectItem(rect) {
  setFlag(QGraphicsItem::ItemIsMovable);
  setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
  setPen(pen);
  setBrush(brush);
}

void GUIHyperEdge::addLine(QGraphicsLineItem *line) {
  line->setLine(QLineF(line->line().p1(), centerPos(this->pos())));
  lines.push_back(line);
}

QVariant GUIHyperEdge::itemChange(const GraphicsItemChange change,
                                  const QVariant &value) {
  if (change == ItemPositionChange && scene()) {
    // value is the new position.
    QPointF newPos = value.toPointF();
    moveLinesToCenter(newPos);
  }
  return QGraphicsItem::itemChange(change, value);
}

void GUIHyperEdge::moveLinesToCenter(const QPointF newPos) {
  // Converts the elipse position (top-left)
  // to its center position
  QPointF newCenterPos = centerPos(newPos);
  for (auto &line : lines) {
    // Move the required point of the line to the center of the elipse
    line->setLine(QLineF(line->line().p1(), newCenterPos));
  }
}
