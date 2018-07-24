//
// Created by arcademiker on 22.07.18.
//

#include "CTank.h"

CTank::CTank(int typ, int x, int y, CMap &map) : CUnit_Player(typ, x, y, map) {
    this->health = 4;
    this->damage = 2;
}

void CTank::do_turn() {
    this->player_options.clear();
    unsigned int size = this->map->get_size();
    this->player_options = std::vector<std::vector<bool>>(size, std::vector<bool>(size, false));
    this->player_options[this->y][this->x] = true;
    this->player_options[std::min(this->y+1,7)][this->x] = true;
    this->player_options[std::min(this->y+2,7)][this->x] = true;
    this->player_options[std::min(this->y+3,7)][this->x] = true;
    this->player_options[std::min(this->y+1,7)][std::min(this->x+1,7)] = true;
    this->player_options[std::min(this->y+2,7)][std::min(this->x+2,7)] = true;
    this->player_options[std::min(this->y+3,7)][std::min(this->x+3,7)] = true;
    this->player_options[this->y][std::min(this->x+1,7)] = true;
    this->player_options[this->y][std::min(this->x+3,7)] = true;
    this->player_options[this->y][std::min(this->x+4,7)] = true;
    this->player_options[std::max(this->y-1,0)][std::min(this->x+1,7)] = true;
    this->player_options[std::max(this->y-2,0)][std::min(this->x+2,7)] = true;
    this->player_options[std::max(this->y-3,0)][std::min(this->x+3,7)] = true;
    this->player_options[std::max(this->y-1,0)][this->x] = true;
    this->player_options[std::max(this->y-2,0)][this->x] = true;
    this->player_options[std::max(this->y-3,0)][this->x] = true;
    this->player_options[std::max(this->y-1,0)][std::max(this->x-1,0)] = true;
    this->player_options[std::max(this->y-2,0)][std::max(this->x-2,0)] = true;
    this->player_options[std::max(this->y-3,0)][std::max(this->x-3,0)] = true;
    this->player_options[this->y][std::max(this->x-1,0)] = true;
    this->player_options[this->y][std::max(this->x-2,0)] = true;
    this->player_options[this->y][std::max(this->x-3,0)] = true;
    this->player_options[std::min(this->y+1,7)][std::max(this->x-1,0)] = true;
    this->player_options[std::min(this->y+2,7)][std::max(this->x-2,0)] = true;
    this->player_options[std::min(this->y+3,7)][std::max(this->x-3,0)] = true;
    // todo: highlight();
    std::pair<int,int> do_point;
    do {
        do_point = this->user_input();
    } while (!this->player_options[do_point.second][do_point.first]);

    this->move(do_point.first,do_point.second);

    /// attack
    /// reset player options
    this->player_options.clear();
    this->player_options = std::vector<std::vector<bool>>(size, std::vector<bool>(size, false));
    CUnit* target1_unit=this->map->get_unit(this->shot(-1,0));
    CUnit* target2_unit=this->map->get_unit(this->shot(0,-1));
    CUnit* target3_unit=this->map->get_unit(this->shot(+1,0));
    CUnit* target4_unit=this->map->get_unit(this->shot(0,+1));
    if(target1_unit || target2_unit || target3_unit || target4_unit) {
        if (target1_unit) { this->player_options[target1_unit->get_y()][target1_unit->get_x()] = true; }
        if (target2_unit) { this->player_options[target2_unit->get_y()][target2_unit->get_x()] = true; }
        if (target3_unit) { this->player_options[target3_unit->get_y()][target3_unit->get_x()] = true; }
        if (target4_unit) { this->player_options[target4_unit->get_y()][target4_unit->get_x()] = true; }

        do {
            do_point = this->user_input();
        } while (!this->player_options[do_point.second][do_point.first] && !(do_point.first == this->x && do_point.second == this->y));

        this->attack(do_point.first, do_point.second);
    }
}
