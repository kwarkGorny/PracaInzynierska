#ifndef GUIHYPEREDGE_H
#define GUIHYPEREDGE_H
#include <QApplication>
#include <QGraphicsRectItem>


class GUIHyperEdge : public QGraphicsRectItem
{
public:
    GUIHyperEdge (const QRectF& rect,const QPen& pen,const QBrush& brush);

    void addLine( QGraphicsLineItem *line);


    QVariant itemChange(const GraphicsItemChange change, const QVariant &value);

    void moveLinesToCenter(const QPointF newPos);

   inline const QPointF centerPos(const QPointF newPos)const
    {
        return QPointF(newPos.x() + rect().x() + rect().width()/2, newPos.y() + rect().y() + rect().height()/2);
    }

private:
    std::vector<QGraphicsLineItem*>lines;
};


#endif // GUIHYPEREDGE_H
