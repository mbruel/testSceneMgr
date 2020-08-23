#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSet>

namespace Ui {
class MainWindow;
}

class QGraphicsScene;
class GraphicItem;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ~MainWindow();

    void addElement(const QPointF & pos=QPointF(0,0), const QSize &size = QSize(50,50));
    void removeElement(GraphicItem *item);

    static MainWindow *getInstance();

private:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    static MainWindow *_mainWin;

    Ui::MainWindow *ui;

    QGraphicsScene *_scene;

    QSet<GraphicItem *> _elements;
    QSet<GraphicItem *> _links;
};

#endif // MAINWINDOW_H
