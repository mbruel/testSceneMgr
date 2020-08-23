#ifndef GRAPHICITEM_H
#define GRAPHICITEM_H

#include <QGraphicsItem>
class Element;

class GraphicItem : public QGraphicsItem
{
public:
    GraphicItem(Element *elem): QGraphicsItem(),_element(elem){}

protected:
    Element *_element;

    static const int sPenSize = 2;
};

#endif // GRAPHICITEM_H
