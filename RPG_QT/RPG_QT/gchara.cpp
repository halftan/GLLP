#include "G_Common.h"
#include "gchara.h"

GChara::GChara(QObject *parent)
    :IBattle(parent), GCreature(DEFAULT::default_property), status(DEFAULT::default_max_hp) {
    this->init_log();
}

GChara::GChara(GProperty property, GStatus status, QObject *parent)
    :IBattle(parent), GCreature(property), status(property) {
    this->status = status;
    this->init_log();
}

GChara::~GChara(){
    char buf[50];
    sprintf(buf, "GChara(GID: %u) destroyed.\n", this->GID);
    GameObject::log << buf;
}

void GChara::init_log(){
    char buf[50];
    sprintf(buf, "GChara(GID: %u) constructed.\n", this->GID);
    GameObject::log << buf;
}
