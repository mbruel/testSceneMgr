#include "DeleteElementAction.h"
#include "mainwindow.h"

DeleteElementAction::DeleteElementAction(GraphicItem *item):_item(item){}

void DeleteElementAction::remove()
{
    MainWindow::getInstance()->removeElement(_item);
    deleteLater();
}
