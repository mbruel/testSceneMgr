#ifndef DELETEELEMENTACTION_H
#define DELETEELEMENTACTION_H

#include <QObject>

class GraphicItem;

class DeleteElementAction : public QObject
{
    Q_OBJECT

public:
    DeleteElementAction(GraphicItem *item);

public slots:
    void remove();

private:
    GraphicItem *_item;
};

#endif // DELETEELEMENTACTION_H
