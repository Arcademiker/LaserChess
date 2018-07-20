//
// Created by arcademiker on 20.07.18.
//

#include "CUnit.h"

CUnit::CUnit(int type, int x, int y) {
    this->type = type;
    this-> x = x;
    this-> y = y;
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

