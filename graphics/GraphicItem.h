#ifndef GRAPHICITEM_H
#define GRAPHICITEM_H

#include <QGraphicsItem>

class GraphicItem : public QGraphicsItem
{
public:
    GraphicItem(const QPointF & pos = QPointF(0,0), const QSize & size = QSize(50,50));
    virtual ~GraphicItem() = default;

protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);

protected:
    static const int sPenSize = 2;

    QPointF _scenePos;
    QSize   _size;
    QColor  _color;
};

#endif // GRAPHICITEM_H
