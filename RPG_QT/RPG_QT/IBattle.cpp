#include "IBattle.h"
#include <vector>

const ACT_TYPE IBattle::ATTACK(ATTACK_V);
const ACT_TYPE IBattle::BREAK(BREAK_V);
const ACT_TYPE IBattle::DEFENCE(DEFENCE_V);

IBattle::IBattle(QObject *parent)
    :QObject(parent), action_list(ACTS_PER_TURN) {
    this->is_ready_for_battle = false;
}

IBattle::~IBattle() {
    this->action_list.~vector();
}

void IBattle::add_action(ACT_TYPE act){
    if(this->is_ready_for_battle)
        return;
    this->action_list.push_back(act);
    if(action_list.size() == ACTS_PER_TURN)
        this->is_ready_for_battle = true;
}

void IBattle::delete_action(){
    if(this->is_ready_for_battle)
        this->is_ready_for_battle = false;
    this->action_list.pop_back();
}

const std::vector<ACT_TYPE> & IBattle::start_battle() const{
    return this->action_list;
}
