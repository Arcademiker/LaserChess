//
// Created by arcademiker on 22.07.18.
//

#include "CTank.h"

CTank::CTank(int typ, int x, int y, CMap &map) : CUnit_Player(typ, x, y, map) {
    this->health = 4;
    this->damage = 2;
}

void CTank::do_turn() {

}
