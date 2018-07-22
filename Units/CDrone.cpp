//
// Created by arcademiker on 22.07.18.
//

#include "CDrone.h"

CDrone::CDrone(int typ, int x, int y, CMap &map) : CUnit_AI(typ, x, y, map) {

}

void CDrone::do_turn() {
    ///move:
    this->move(this->x-1, this->y);
    ///attack:
    //todo:
}
