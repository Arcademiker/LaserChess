//
// Created by arcademiker on 20.07.18.
//

#include "CUnit_AI.h"

void CUnit_AI::get_nearest() {
    for(auto U: *this->map->get_unit_list()) {
        this->map->distance(this->x, this->y, U.second->get_x() , U.second->get_y() );
    }
    //todo..
}

CUnit_AI::CUnit_AI(int typ, int x, int y, CMap &map) : CUnit(typ, x, y, map) {
    this->type = type;
    this-> x = x;
    this-> y = y;
    this->map = &map;
}

