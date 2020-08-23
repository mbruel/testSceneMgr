#include "LinkNMItem.h"
#include "Element.h"

#include <QPainter>
#include <QRectF>
#include <QGraphicsSceneMouseEvent>

LinkNMItem::LinkNMItem(Element *link, const QPointF &movePoint, const QSet<QGraphicsItem *> &items):
    QGraphicsItem(), GraphicItem(link),
    _items(items),
    _movablePoint(movePoint),
    _movableRect(_movablePoint, QSize(0,0)),
    _isMoving(false)
{
    _movableRect.adjust(-5,-5, 5, 5);
}

void LinkNMItem::removeItem(QGraphicsItem *item)
{
    if (_items.remove(item))
        prepareGeometryChange();
}

QRectF LinkNMItem::boundingRect() const
{
    QPolygonF polygon;
    polygon << _movablePoint;
    for (QGraphicsItem * item : _items)
        polygon << item->sceneBoundingRect().center();

    return polygon.boundingRect().adjusted(-5, -5, 5, 5);
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
        painter->drawLine(_movablePoint, item->sceneBoundingRect().center());

//    painter->setPen(QPen(Qt::blue, sPenSize));
//    painter->drawRect(boundingRect());
}


void LinkNMItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    QPointF pos = event->scenePos();
    if (_movableRect.contains(pos))
        _isMoving = true;
}

void LinkNMItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (_isMoving)
    {
        _movablePoint = event->scenePos();
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
        _movablePoint = event->scenePos();
        _isMoving = false;
        _element->setPos(_movablePoint);
        prepareGeometryChange();
    }
}

void LinkNMItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    if (_element)
    {
        _element->showMenu();
    }
    event->accept();
}
