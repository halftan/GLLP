#ifndef GCREATURE_H
#define GCREATURE_H

#include "GameObject.h"
#include "GProperty.h"

class GCreature: protected GameObject {
public:
	GCreature();
    GCreature(GProperty prop);
    virtual ~GCreature();

	GProperty property;
	
private:
	unsigned int max_hp;

};

#endif
