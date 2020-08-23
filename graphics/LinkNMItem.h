#ifndef LINKNMITEM_H
#define LINKNMITEM_H

#include "GraphicItem.h"
#include <QSet>


class LinkNMItem : public GraphicItem
{
public:
    LinkNMItem(const QSet<GraphicItem*> &items);

    void removeItem(GraphicItem *item);


    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    // QGraphicsItem interface
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);


private:
    QSet<GraphicItem*> _items;

    QPointF _movablePoint;
    QRectF  _movableRect;
    bool    _isMoving;

    static const ushort SHAPE_MOVABLE_RECT = 10;
};

#endif // LINKNMITEM_H
