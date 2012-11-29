#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <fstream>
#include <QString>
#include <string>

using std::string;
#define LOG_FILE "e.log"

typedef unsigned int G_IDENTIFIER;

class GameObject{
protected:
    static G_IDENTIFIER G_OBJ_COUNT;	//Sum of all objects
    static G_IDENTIFIER G_OBJ_N_COUNT;	//Sum of current objects
    const G_IDENTIFIER GID;

public:
    GameObject();
	virtual ~GameObject();
	static std::ofstream log;

    bool is_same(GameObject o);

};

QString s2q(const string &s);
string q2s(const QString &s);

#endif
