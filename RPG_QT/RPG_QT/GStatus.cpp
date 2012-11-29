#include "GStatus.h"
#include "G_Common.h"

GStatus::GStatus(int max_hp){
    this->current_hp = max_hp;
}

bool GStatus::hp_damage_by(int points){
    this->current_hp -= points;
    return this->current_hp <= 0;
}

GStatus::GStatus(GProperty p){
    this->current_hp = CALC_MAX_HP(p.agility, p.strenth, p.intelli);
}

void GStatus::operator =(const GStatus &e){
    this->current_hp = e.current_hp;
}
