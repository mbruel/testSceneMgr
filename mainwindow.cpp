#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphics/ComplexItem.h"
#include "graphics/LinkNMItem.h"

MainWindow *MainWindow::_mainWin = Q_NULLPTR;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), _scene(Q_NULLPTR)
{
    ui->setupUi(this);
    ui->graphicsView->setOptimizationFlag(QGraphicsView::DontSavePainterState);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing, true);
    ui->graphicsView->setInteractive(true);
    ui->graphicsView->setMouseTracking(false);
    ui->graphicsView->setFrameStyle(QFrame::NoFrame);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorViewCenter);


    _scene = new QGraphicsScene();
    ui->graphicsView->setScene(_scene);


    addElement();
    addElement(QPointF(100,0));
    addElement(QPoint(50,100));

    LinkNMItem *link = new LinkNMItem(_elements);
    _links.insert(link);
    _scene->addItem(link);
    _scene->update();
}

MainWindow::~MainWindow()
{     
    delete _scene;
    delete ui;
}

void MainWindow::addElement(const QPointF &pos, const QSize &size)
{
    ComplexItem *item = new ComplexItem(pos, size);
    _scene->addItem(item);
    _elements.insert(item);
}

void MainWindow::removeElement(GraphicItem *item)
{

    if (_elements.remove(item) || _links.remove(item))
    {
        _scene->removeItem(item);
        _scene->update();
        delete item;
    }
}

MainWindow *MainWindow::getInstance()
{
    if (!MainWindow::_mainWin)
        _mainWin = new MainWindow();
    return _mainWin;
}
