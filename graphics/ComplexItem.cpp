#include "ComplexItem.h"
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QRectF>

ComplexItem::ComplexItem(const QPointF &pos, const QSize &size):
    GraphicItem(pos, size)
{
    setPos(pos);
}

QRectF ComplexItem::boundingRect() const
{
    return QRectF(QPointF(0,0), _size).adjusted(-sPenSize, -sPenSize, sPenSize, sPenSize);
}

void ComplexItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setPen(QPen(Qt::green, sPenSize));
    painter->drawRect(boundingRect());
}

