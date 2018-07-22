//
// Created by arcademiker on 20.07.18.
//

#include "CUnit_AI.h"



CUnit_AI::CUnit_AI(int typ, int x, int y, CMap &map) : CUnit(typ, x, y, map) {

}

bool CUnit_AI::attack(int to_x, int to_y) {
    int id = this->map->get(to_x,to_y);
    CUnit* target_unit = this->map->get_unit(id);
    if(target_unit && target_unit->get_type() < 4) {
        if(target_unit->loose_health(this->damage)){
            this->map->kill_unit(id);
        }
        return true; /// attack hits target
    }

    return false; /// attack don't hits target
}

