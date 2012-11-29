#ifndef GCHARA_H
#define GCHARA_H

#include "G_Common.h"
#include <QObject>

class GChara: public IBattle, GCreature {
    Q_OBJECT
public:
    GChara(GProperty property, GStatus status, QObject *parent = 0);
    GChara(QObject *parent = 0);
    ~GChara();

    GStatus status;

private:
    void init_log();
};

#endif // GCHARA_H
