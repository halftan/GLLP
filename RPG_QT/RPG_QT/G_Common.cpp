#include "G_Common.h"

int __calc_max_hp__(GProperty peny, GProperty pmy){
    float e_atk, m_def;
    srand(pmy.intelli);
    e_atk = peny.agility * 0.3 + peny.strenth * 0.6;
    m_def = pmy.agility * 0.6 * pmy.agility /\
            (static_cast<double>(rand() % \
            (pmy.agility + pmy.intelli)) * 1.2)\
            + pmy.strenth * 0.1 + pmy.intelli * 0.2;
    return static_cast<int>(e_atk - m_def);
}
