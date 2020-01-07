#include <QApplication>
#include "Sprite.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);

    Sprite _sprite;
    _sprite.showMaximized();

    return a.exec();
}