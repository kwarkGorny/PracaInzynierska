#ifndef GUIVERTEX_H
#define GUIVERTEX_H
#include <QApplication>
#include <QGraphicsEllipseItem>
#include<parallel/for_each.h>

/**
 * @author   Adam Szczepanski
 * @date 27.12.2017
 * @brief Graphic representation of Vertex for drawing component
*/


class GUIVertex : public QGraphicsEllipseItem
{
public:
    GUIVertex(const QRectF& rect,const QPen& pen,const QBrush& brush);

    void AddLine(QGraphicsLineItem *line) ;

    QVariant itemChange(const GraphicsItemChange change, const QVariant &value);

    void moveLinesToCenter(const QPointF newPos);

    const QPointF centerPos(const QPointF newPos)const;

private:
    std::vector<QGraphicsLineItem*>lines;
};
#endif // GUIVERTEX_H
