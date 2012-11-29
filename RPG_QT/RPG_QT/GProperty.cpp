#include "GProperty.h"
#include "G_Common.h"
#define NOTAVAIL(S) S<0

GProperty::GProperty(){
	this->name = "NoName";
    this->agility = DEFAULT_VAL;
    this->strenth = DEFAULT_VAL;
    this->intelli = DEFAULT_VAL;
}

GProperty::GProperty(QString name){
	this->name = name;
    this->agility = DEFAULT_VAL;
    this->strenth = DEFAULT_VAL;
    this->intelli = DEFAULT_VAL;
}

GProperty::GProperty(QString name, int agility, int strenth, int intelligence){
	if(NOTAVAIL(agility) || NOTAVAIL(strenth) || NOTAVAIL(intelligence))
	this->agility = agility;
	this->strenth = strenth;
	this->intelli = intelligence;
    this->name = name;
}

GProperty::~GProperty(){
    char buf[50];
    sprintf(buf, "GProperty(GID: %u) destroyed.\n", this->GID);
    GameObject::log << buf;
}

QString GProperty::rank(int STAT){
	if(STAT <= E_LINE)
		return "E";
	if(STAT <= D_LINE)
		return "D";
	if(STAT <= C_LINE)
		return "C";
	if(STAT <= B_LINE)
		return "B";
	if(STAT <= A_LINE)
		return "A";
	if(STAT <= S_LINE)
		return "S";
	return "Ex";
}

QString GProperty::to_s(){
	QString result(QObject::tr("Your character's property:"));
	result.append(QString(QObject::tr("\n\tAgility: ")).append(rank(this->agility)));
	result.append(QString(QObject::tr("\n\tStrenth: ")).append(rank(this->agility)));
	result.append(QString(QObject::tr("\n\tIntelligence: ")).append(rank(this->agility)));
	result.append("\n");
	return result;
}

void GProperty::operator =(const GProperty &e){
    this->name = e.name;
    this->agility = e.agility;
    this->strenth = e.strenth;
    this->intelli = e.intelli;
}
