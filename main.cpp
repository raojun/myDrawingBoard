#include <QApplication>
#include "mypainter.h"

int main(int argc,char* argv[])
{
    QApplication app(argc,argv);

    MyPainter w;
    w.show();

    return app.exec();
}
