//
// Created by arcademiker on 22.07.18.
//

#include "CCommandUnit.h"

CCommandUnit::CCommandUnit(int typ, int x, int y, CMap &map) : CUnit_AI(typ, x, y, map) {
    this->health = 5;
    this->damage = 0;
}

void CCommandUnit::calc_move_area() {

}

void CCommandUnit::calc_attack_area() {

}


void CCommandUnit::do_turn() {
    // todo: heighlight all attackable fields (use this for other units too).
    // todo: add unit blocking evasion
}

