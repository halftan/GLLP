#ifndef QSTATUS_H
#define QSTATUS_H

#include "GameObject.h"
#include "G_Common.h"

class GStatus : public GameObject {
public:
    GStatus(int max_hp);
    GStatus(GProperty p);
    int current_hp;
    bool hp_damage_by(int points);
    void operator=(const GStatus &);

};

#endif // QSTATUS_H
