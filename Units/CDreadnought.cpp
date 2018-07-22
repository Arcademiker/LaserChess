//
// Created by arcademiker on 21.07.18.
//

#include "CDreadnought.h"

void CDreadnought::scanSurrounding() {
    for(auto U: *this->map->get_unit_list()) {
        this->surrounding.insert( {this->map->distance(this->x, this->y, U.second->get_x(), U.second->get_y()), U.first});
    }
}

CDreadnought::CDreadnought(int typ, int x, int y, CMap &map) : CUnit_AI(typ, x, y, map) {

}

void CDreadnought::do_turn() {

}


void CDreadnought::get_nearest() {
    //todo: get nearest surrounding
}


