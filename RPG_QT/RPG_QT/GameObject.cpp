#include "GameObject.h"

#include <cstdio>

G_IDENTIFIER GameObject::G_OBJ_COUNT(0);
G_IDENTIFIER GameObject::G_OBJ_N_COUNT(0);
std::ofstream GameObject::log(LOG_FILE);

GameObject::GameObject()
    :GID(++GameObject::G_OBJ_COUNT){
	if(GameObject::G_OBJ_N_COUNT == 0)
		GameObject::log.open(LOG_FILE, std::ios_base::app);
    ++GameObject::G_OBJ_N_COUNT;
    if(this->GID == 0)
		fprintf(stderr, "Error creating game object:\n\t\
						Objects ever been created: %u\n\t\
						Objects currently existing: %u\n",
						GameObject::G_OBJ_COUNT, GameObject::G_OBJ_N_COUNT);
}

GameObject::~GameObject(){
	if(--GameObject::G_OBJ_N_COUNT == 0)
		GameObject::log.close();
    char buf[50];
    sprintf(buf, "GameObject(GID: %u) destroyed.\n", this->GID);
    GameObject::log << buf;
}

bool GameObject::is_same(GameObject o){
    return this->GID == o.GID;
}

QString s2q(const string &s){
	return QString(QString::fromLocal8Bit(s.c_str()));  
}  

string q2s(const QString &s){
	return string((const char *)s.toLocal8Bit());  
}  
