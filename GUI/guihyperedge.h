#ifndef GUIHYPEREDGE_H
#define GUIHYPEREDGE_H
#include <QApplication>
#include <QGraphicsRectItem>
/**
 * @author   Adam Szczepanski
 * @date 27.12.2017
 * @brief Graphic representation of Hyperedge for drawing component
*/


class GUIHyperEdge : public QGraphicsRectItem
{
public:
    GUIHyperEdge(const QRectF& rect,const QPen& pen,const QBrush& brush);

    void addLine( QGraphicsLineItem *line);

    QVariant itemChange(const GraphicsItemChange change, const QVariant &value);

    void moveLinesToCenter(const QPointF newPos);

    const QPointF centerPos(const QPointF newPos)const;
private:
    std::vector<QGraphicsLineItem*>lines;
};


#endif // GUIHYPEREDGE_H
