#ifndef GPROPERTY_H
#define GPROPERTY_H

#include "GameObject.h"
#include <QString>
#include <QApplication>

#define S_LINE 120
#define A_LINE 100
#define B_LINE 80
#define C_LINE 60
#define D_LINE 40
#define E_LINE 10

class GProperty: protected GameObject {
public:
	GProperty();
	GProperty(QString name, int agility, int strenth, int intelligence);
	GProperty(QString name);
    virtual ~GProperty();
    void operator =(const GProperty &e);

	QString rank(int STAT);
	QString to_s();

	QString name;
	int agility;
	int strenth;
	int intelli;

private:
};

#endif
