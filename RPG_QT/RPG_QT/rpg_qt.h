#ifndef RPG_QT_H
#define RPG_QT_H

#include <QtGui/QMainWindow>
#include "ui_rpg_qt.h"

class RPG_QT : public QMainWindow
{
	Q_OBJECT

public:
	RPG_QT(QWidget *parent = 0, Qt::WFlags flags = 0);
	~RPG_QT();

private:
	Ui::RPG_QTClass ui;
};

#endif // RPG_QT_H
