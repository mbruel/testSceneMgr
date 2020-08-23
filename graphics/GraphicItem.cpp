#include "GraphicItem.h"
#include "DeleteElementAction.h"
#include <QMenu>
#include <QGraphicsSceneContextMenuEvent>

GraphicItem::GraphicItem(const QPointF &pos, const QSize &size) :
    QGraphicsItem(), _scenePos(pos), _size(size), _color(Qt::black)
{
    setFlag(QGraphicsItem::ItemIsMovable,    true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

void GraphicItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QMenu menu;
    QAction *qAction = menu.addAction("Delete");
    qAction->setEnabled(true);
    DeleteElementAction *delAction = new DeleteElementAction(this);
    QObject::connect(qAction, SIGNAL(triggered()), delAction, SLOT(remove()));

    menu.exec(QCursor::pos());
    event->accept();
}
