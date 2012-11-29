#include "G_Common.h"
#include <cstdio>

GCreature::GCreature()
    :property(DEFAULT::default_property), max_hp(DEFAULT::default_max_hp) {
    char buf[50];
    sprintf(buf, "GCreature(GID: %u) constructed by default.\n", this->GID);
    GameObject::log << buf;
}

GCreature::GCreature(GProperty prop){
	this->property = prop;
	this->max_hp = CALC_MAX_HP(prop.agility, prop.strenth, prop.intelli);
}

GCreature::~GCreature(){
    char buf[50];
    sprintf(buf, "GCreature(GID: %u) destroyed.\n", this->GID);
    GameObject::log << buf;
}
