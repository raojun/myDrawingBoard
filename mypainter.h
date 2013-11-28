#ifndef MYPAINTER_H
#define MYPAINTER_H

#include <QWidget>
#include <QPoint>
#include <QVector>

typedef struct myLine{
    QPoint startPoint;
    QPoint endPoint;
}myLine;

class MyPainter : public QWidget
{
public:
    MyPainter();

    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    QPoint startPoint;//起点
    QPoint endPoint;//终点

    bool isPressed;//鼠标是否按下

    QVector<myLine*> lines;//存放所有线段
};

#endif // MYPAINTER_H
