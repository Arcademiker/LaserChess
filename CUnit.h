//
// Created by arcademiker on 20.07.18.
//


#ifndef LASERCHESS_CUNIT_H
#define LASERCHESS_CUNIT_H

#include "CMap.h"

class CMap;

class CUnit {
protected:
    CMap* map;
    int type;
    int health;
    int damage;
    int x;
    int y;
public:
    CUnit(int typ, int x, int y, CMap& map);
    int get_type();
    int get_x();
    int get_y();
    int get_health();
    bool move(int to_x, int to_y);
    bool attack(int to_x, int to_y);
    virtual void do_turn() = 0;
};


#endif //LASERCHESS_CUNIT_H
