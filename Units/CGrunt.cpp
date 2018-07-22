//
// Created by arcademiker on 22.07.18.
//

#include "CGrunt.h"

CGrunt::CGrunt(int typ, int x, int y, CMap &map) : CUnit_Player(typ, x, y, map) {
    this->health = 2;
    this->damage = 1;
}

void CGrunt::do_turn() {

}
