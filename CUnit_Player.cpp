//
// Created by arcademiker on 22.07.18.
//

#include "CUnit_Player.h"

CUnit_Player::CUnit_Player(int typ, int x, int y, CMap &map) : CUnit(typ, x, y, map) {

}

bool CUnit_Player::attack(int to_x, int to_y) {
    CUnit* target_unit = this->map->get_unit(to_x,to_y);
    if(target_unit && target_unit->get_type() > 3) {
        target_unit->loose_health(this->damage);
        return true;
    }

    return false;
}
