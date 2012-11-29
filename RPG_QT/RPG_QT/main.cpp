#include "rpg_qt.h"
#include <QtGui/QApplication>
#include <QtGui>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    RPG_QT w;
    w.show();
	return a.exec();
}
