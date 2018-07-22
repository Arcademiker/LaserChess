//
// Created by arcademiker on 20.07.18.
//

#include "CUnit.h"

CUnit::CUnit(int type, int x, int y, CMap& map) {
    this->type = type;
    this-> x = x;
    this-> y = y;
    this->map = &map;
}

int CUnit::get_type() {
    return this->type;
}

int CUnit::get_x() {
    return this->x;
}

int CUnit::get_y() {
    return this->y;
}

int CUnit::get_health() {
    return this->health;
}

bool CUnit::move(int to_x, int to_y) {
    if( this->map->move(this->x, this->y, to_x, to_y) ) {
        this->x = to_x;
        this->y = to_y;
        return true;
    }

    return false;
}

bool CUnit::attack(int to_x, int to_y) {
    CUnit* target_unit = this->map->get_unit(to_x,to_y);
    if(target_unit) {
        target_unit->health = target_unit->health - this->damage;
        return true;
    }
    return false;
}




