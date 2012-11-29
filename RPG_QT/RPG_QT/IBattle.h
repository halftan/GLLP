#ifndef IBATTLE_H
#define IBATTLE_H

#define ATTACK_V 0
#define BREAK_V 1
#define DEFENCE_V 2

#define ACTS_PER_TURN 6

#include <vector>

#include <QObject>
#include <QString>
#include "GameObject.h"

typedef int ACT_TYPE;

class IBattle: public QObject {
    Q_OBJECT
public:
    static const ACT_TYPE ATTACK;
    static const ACT_TYPE BREAK;
    static const ACT_TYPE DEFENCE;

    bool is_ready_for_battle;

    GameObject owner;

    IBattle(QObject *parent = 0);
    virtual ~IBattle();

    const std::vector<ACT_TYPE>& start_battle() const;

public slots:
    void add_action(ACT_TYPE act);
    void delete_action();

    //virtual bool use_item() = 0;

private:
    std::vector <ACT_TYPE> action_list;

signals:
    void i_am_ready_for_battle();

};

#endif
