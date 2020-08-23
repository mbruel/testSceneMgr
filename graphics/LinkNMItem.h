#ifndef LINKNMITEM_H
#define LINKNMITEM_H

#include "GraphicItem.h"
#include <QGraphicsItem>

#include <QSet>



class LinkNMItem : public QGraphicsItem, public GraphicItem
{
public:
    LinkNMItem(Element *link, const QPointF &movePoint, const QSet<QGraphicsItem*> &items);

    void removeItem(QGraphicsItem *item);



    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    // QGraphicsItem interface
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);


private:
    QSet<QGraphicsItem*> _items;

    QPointF _movablePoint;
    QRectF  _movableRect;
    bool    _isMoving;

    static const ushort SHAPE_MOVABLE_RECT = 10;
};

#endif // LINKNMITEM_H
