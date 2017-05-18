#ifndef GUIHYPEREDGE_H
#define GUIHYPEREDGE_H
#include <QApplication>
#include <QGraphicsRectItem>


class GUIHyperEdge : public QGraphicsRectItem
{
public:
    GUIHyperEdge (const QRectF& rect,QPen& pen,QBrush& brush);

    void addLine(QGraphicsLineItem *line);


    QVariant itemChange(GraphicsItemChange change, const QVariant &value);


    void moveLinesToCenter(QPointF newPos);

   inline QPointF centerPos(const QPointF newPos)
    {
        return QPointF(newPos.x() + rect().x() + rect().width()/2, newPos.y() + rect().y() + rect().height()/2);
    }

private:
    std::vector<QGraphicsLineItem*>lines;
};


#endif // GUIHYPEREDGE_H
