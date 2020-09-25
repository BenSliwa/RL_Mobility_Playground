#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    World *world = World::getInstance();
    Vector3d size = world->getSize();

    this->setFixedSize(size.x, size.y);

    m_keys << 0 << 0 << 0 << 0;

    p_car = new Car("c0", Vector3d(100, 100, 0));

    connect(&m_keyTimer, SIGNAL(timeout()), this, SLOT(onKeyTimeout()));
    m_keyTimer.start(16);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QPointF MainWindow::mapToCanvas(const Vector3d &_pos)
{
    return QPointF(_pos.x, this->height()-_pos.y);
}

void MainWindow::paintEvent(QPaintEvent *_event)
{
    QPainter painter(this);

    p_car->updatePerception();
    Vector3d pos = p_car->getPosition();
    Vector3d orientation = p_car->getOrientation();

    double w = p_car->getWidth();
    double l = p_car->getLength();

    Vector3d left = Vector3d::fromSphere(90, 90 + p_car->getOrientation().z, w/2);
    Vector3d back = left.rotateLeft().normed() * l;

    QVector<QPointF> v;
    v << mapToCanvas(pos+left);
    v << mapToCanvas(pos-left);
    v << mapToCanvas(pos-left+back);
    v << mapToCanvas(pos+left+back);
    painter.drawPolygon(v);




    std::vector<PerceptionVector> perception = p_car->getPerception();
    for(auto p : perception)
        painter.drawLine(mapToCanvas(pos), mapToCanvas(pos+p.dir*p.length));
}

void MainWindow::keyReleaseEvent(QKeyEvent *_event)
{
    switch(_event->key())
    {
        case Qt::Key_W: m_keys[0]=0; break;
        case Qt::Key_A: m_keys[1]=0; break;
        case Qt::Key_S: m_keys[2]=0; break;
        case Qt::Key_D: m_keys[3]=0; break;
    }


}

void MainWindow::keyPressEvent(QKeyEvent *_event)
{

    switch(_event->key())
    {
        case Qt::Key_W: m_keys[0]=1; break;
        case Qt::Key_A: m_keys[1]=1; break;
        case Qt::Key_S: m_keys[2]=1; break;
        case Qt::Key_D: m_keys[3]=1; break;
    }


}

void MainWindow::onKeyTimeout()
{
    //qDebug() << m_keys;
    int inc = 2;
    Vector3d orientation = p_car->getOrientation();

    if(m_keys[0])
        p_car->move(5);
    if(m_keys[1])
        orientation.z+=inc;
    if(m_keys[2])
        p_car->move(-5);
    if(m_keys[3])
        orientation.z-=inc;

    p_car->setOrientation(orientation);
    this->repaint();
}
