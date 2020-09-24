#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include "mobility/car.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QPointF mapToCanvas(const Vector3d &_pos);

protected:
    void paintEvent(QPaintEvent *_event);

    void keyReleaseEvent(QKeyEvent *_event);
    void keyPressEvent(QKeyEvent *_event);

private slots:
    void onKeyTimeout();

private:
    Ui::MainWindow *ui;

    Car *p_car;
    QList<int> m_keys;

    QTimer m_keyTimer;
};
#endif // MAINWINDOW_H
