#ifndef GRAPHICITEM_H
#define GRAPHICITEM_H


class Element;

class GraphicItem
{
public:
    GraphicItem(Element *elem):_element(elem){}

protected:
    Element *_element;

    static const int sPenSize = 2;
};

#endif // GRAPHICITEM_H
