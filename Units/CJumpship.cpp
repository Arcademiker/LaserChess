//
// Created by arcademiker on 22.07.18.
//

#include "CJumpship.h"

CJumpship::CJumpship(int typ, int x, int y, CMap &map) : CUnit_Player(typ, x, y, map) {
    this->health = 2;
    this->damage = 2;
}

void CJumpship::do_turn() {

}
