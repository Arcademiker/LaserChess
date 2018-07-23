//
// Created by arcademiker on 22.07.18.
//

#include "CGrunt.h"

CGrunt::CGrunt(int typ, int x, int y, CMap &map) : CUnit_Player(typ, x, y, map) {
    this->health = 2;
    this->damage = 1;
}

void CGrunt::do_turn() {
    /// move
    this->player_options.clear();
    unsigned int size = this->map->get_size();
    this->player_options = std::vector<std::vector<bool>>(size, std::vector<bool>(size, false));
    this->player_options[this->y][this->x] = true;
    this->player_options[std::min(this->y+1,7)][this->x] = true;
    this->player_options[this->y][std::min(this->x+1,7)] = true;
    this->player_options[std::max(this->y-1,0)][this->x] = true;
    this->player_options[this->y][std::max(this->x-1,0)] = true;
    // highlight();
    std::pair<int,int> do_point = this->user_input();
    while (!this->player_options[do_point.second][do_point.first]) {
        do_point = this->user_input();
    }
    this->move(do_point.first,do_point.second);
    /// attack

}
