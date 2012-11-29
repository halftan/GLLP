#ifndef G_COMMON_H
#define G_COMMON_H

#include "GCreature.h"
#include "IBattle.h"
#include "GameObject.h"
#include "GProperty.h"
#include "GStatus.h"

#include <cstdio>

#define DEFAULT_VAL 80

/*  MAX hp formula
 *  max_hp = agility * 0.2 + strenth * 0.7 + intelli * 0.1
 *
 *  HP damage formula
 *  damage = floor of: enemy's: ( agi * 0.3 + str * 0.6 )
 *           - my: (agi * 0.6 * agi/rand(0, (agi+int) * 1.2)
 *           + str * 0.1 + int * 0.2)
 */

#define CALC_MAX_HP(A,S,I) A*0.2 + S*0.7 + I*0.1

int __calc_max_hp__(GProperty peny, GProperty pmy);

#define CALC_DAMAGE(PENY,PMY) __calc_max_hp__(PENY,PMY)

namespace DEFAULT{

    static GProperty default_property("NoName",
                                      DEFAULT_VAL,
                                      DEFAULT_VAL,
                                      DEFAULT_VAL);
    static unsigned int default_max_hp(DEFAULT_VAL);

}

#endif // G_COMMON_H
