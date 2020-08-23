#ifndef COMPLEXITEM_H
#define COMPLEXITEM_H

#include "GraphicItem.h"

class ComplexItem : public GraphicItem
{
public:
    ComplexItem(const QPointF & pos = QPointF(0,0), const QSize & size = QSize(50,50));

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // COMPLEXITEM_H
