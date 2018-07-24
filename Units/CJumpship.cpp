//
// Created by arcademiker on 22.07.18.
//

#include "CJumpship.h"

CJumpship::CJumpship(int typ, int x, int y, CMap &map) : CUnit_Player(typ, x, y, map) {
    this->health = 2;
    this->damage = 2;
}

void CJumpship::do_turn() {
    /// move
    this->player_options.clear();
    unsigned int size = this->map->get_size();
    this->player_options = std::vector<std::vector<bool>>(size, std::vector<bool>(size, false));
    this->player_options[this->y][this->x] = true;
    this->player_options[std::min(this->y+2,7)][std::min(this->x+1,7)] = true;
    this->player_options[std::min(this->y+1,7)][std::min(this->x+2,7)] = true;
    this->player_options[std::min(this->y+2,7)][std::max(this->x-1,0)] = true;
    this->player_options[std::min(this->y+1,7)][std::max(this->x-2,0)] = true;
    this->player_options[std::max(this->y-2,0)][std::max(this->x-1,0)] = true;
    this->player_options[std::max(this->y-1,0)][std::max(this->x-2,0)] = true;
    this->player_options[std::max(this->y-2,0)][std::min(this->x+1,7)] = true;
    this->player_options[std::max(this->y-1,0)][std::min(this->x+2,7)] = true;
    // todo: highlight();
    std::pair<int,int> do_point;
    do {
        do_point = this->user_input();
    } while (!this->player_options[do_point.second][do_point.first]);

    this->move(do_point.first,do_point.second);

    /// attack
    this->attack(this->x+1,this->y);
    this->attack(this->x,this->y+1);
    this->attack(this->x-1,this->y);
    this->attack(this->x,this->y-1);

}
