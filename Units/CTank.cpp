//
// Created by arcademiker on 22.07.18.
//

#include "CTank.h"

CTank::CTank(int typ, int x, int y, CMap &map) : CUnit_Player(typ, x, y, map) {
    this->health = 4;
    this->damage = 2;
}

void CTank::calc_move_area() {
    this->player_options.clear();
    unsigned int size = this->map->get_size();
    this->player_options = std::vector<std::vector<bool>>(size, std::vector<bool>(size, false));
    /// generate move options:
    /// 1 0 0 1 0 0 1
    /// 0 1 0 1 0 1 0
    /// 0 0 1 1 1 0 0
    /// 1 1 1 1 1 1 1
    /// 0 0 1 1 1 0 0
    /// 0 1 0 1 0 1 0
    /// 1 0 0 1 0 0 1
    this->player_options[this->y][this->x] = true;
    std::vector<std::pair<int,int>> dir;
    dir.push_back(std::make_pair( 0,-1));
    dir.push_back(std::make_pair(-1,-1));
    dir.push_back(std::make_pair(-1, 0));
    dir.push_back(std::make_pair(-1, 1));
    dir.push_back(std::make_pair( 0, 1));
    dir.push_back(std::make_pair( 1, 1));
    dir.push_back(std::make_pair( 1, 0));
    dir.push_back(std::make_pair( 1,-1));
    for(auto d: dir) {
        int d_x = d.first;
        int d_y = d.second;
        int range = 1;
        while(range < 3 && this->map->is_inbound(this->x+d_x,this->y+d_y) && this->map->get(this->x+d_x,this->y+d_y) == 0) {
            this->player_options[this->y+d_y][this->x+d_x] = true;
            d_x = d_x + d.first;
            d_y = d_y + d.second;
            range++;
        }
    }
}

void CTank::calc_attack_area() {
    /// genrate attack options:
    /// 0 0 0  7  0 0 0
    /// 0 0 0  7  0 0 0
    /// 0 0 0  7  0 0 0
    ///
    /// 7 7 7 49  7 7 7
    ///
    /// 0 0 0  7  0 0 0
    /// 0 0 0  7  0 0 0
    /// 0 0 0  7  0 0 0
}


void CTank::do_turn() {
    this->calc_move_area();

    std::pair<int,int> do_point;
    do {
        do_point = this->user_input();
    } while (!this->player_options[do_point.second][do_point.first]);

    this->move(do_point.first,do_point.second);

    /// attack
    /// reset player options
    this->player_options.clear();
    unsigned int size = this->map->get_size();
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

