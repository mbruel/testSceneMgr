#include "LinkNMItem.h"

#include <QPainter>
#include <QRectF>
#include <QGraphicsSceneMouseEvent>

LinkNMItem::LinkNMItem(const QSet<GraphicItem *> &items):
    GraphicItem(),
    _items(items),
    _movablePoint(),
    _movableRect(_movablePoint, QSize(0,0)),
    _isMoving(false)
{
    _movableRect.adjust(-5,-5, 5, 5);
}

void LinkNMItem::removeItem(GraphicItem *item)
{
    if (_items.remove(item))
        prepareGeometryChange();
}

QRectF LinkNMItem::boundingRect() const
{
    QPolygonF polygon;
    polygon << _movablePoint;
    for (QGraphicsItem * item : _items)
    {
        polygon << mapFromItem(item, item->boundingRect().center());
//        polygon << item->sceneBoundingRect().center();
    }

    return polygon.boundingRect().adjusted(-10, -10, 10, 10);

//    QRectF result(_movablePoint, QSize(0, 0));
//    result.adjust(-5, -5, 5, 5); // or whatever to draw _movableRect

//    for (QGraphicsItem * item : _items) {
//        result = result.united(mapFromItem(item, item->boundingRect()).boundingRect()); // also need to take the pen into account, etc.
//    }

//    return result;
}

void LinkNMItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    _movableRect = QRectF(_movablePoint, QSize(0,0));
    _movableRect.adjust(-5, -5, 5, 5);
    painter->setPen(QPen(Qt::red, sPenSize));
    painter->drawEllipse(_movableRect);

    painter->setPen(QPen(Qt::black, sPenSize));
    for (QGraphicsItem * item : _items)
        painter->drawLine(_movablePoint, mapFromItem(item, item->boundingRect().center()));

    painter->setPen(QPen(Qt::blue, sPenSize));
    painter->drawRect(boundingRect());
}


void LinkNMItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    QPointF pos = event->pos();
    if (_movableRect.contains(pos))
        _isMoving = true;
}

void LinkNMItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (_isMoving)
    {
        _movablePoint = event->pos();
        update();
        event->accept();
    }
    else
        event->ignore();
}

void LinkNMItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    if (_isMoving)
    {
        _movablePoint = event->pos();
        _isMoving = false;
        prepareGeometryChange();
    }
}

