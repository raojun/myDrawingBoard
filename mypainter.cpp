#include "mypainter.h"
#include <QString>
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QMessageBox>

MyPainter::MyPainter()
{
    setMinimumSize(300,400);
    setMaximumSize(500,700);
    this->setMouseTracking(true);
    this->isPressed=false;
}

void MyPainter::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);//开启抗锯齿
    QPen pen;//创建一个画笔
    pen.setColor(Qt::darkCyan);
    pen.setWidth(5);
    painter.setPen(pen);

    for(int i=0;i<lines.size();i++)
    {
        myLine *line=lines[i];
        painter.drawLine(line->startPoint,line->endPoint);
    }
}

void MyPainter::mousePressEvent(QMouseEvent *event)
{
    setCursor(Qt::PointingHandCursor);
    startPoint=event->pos();
    endPoint=event->pos();
    this->isPressed=true;
}

void MyPainter::mouseMoveEvent(QMouseEvent *event)
{
    if(this->isPressed)
    {
        endPoint=event->pos();

        myLine *line=new myLine;//把新线段放入vector中
        line->startPoint=startPoint;
        line->endPoint=endPoint;
        this->lines.push_back(line);

        update();
        startPoint=endPoint;
    }
}

void MyPainter::mouseReleaseEvent(QMouseEvent *event)
{
    setCursor(Qt::ArrowCursor);
    this->isPressed=false;
}
