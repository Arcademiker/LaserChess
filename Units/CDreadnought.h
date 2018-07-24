//
// Created by arcademiker on 21.07.18.
//

#ifndef LASERCHESS_CDREADNOUGHT_H
#define LASERCHESS_CDREADNOUGHT_H

#include <map>

#include "../CUnit_AI.h"


class CDreadnought : public CUnit_AI {
private:
    std::multimap<int,int> surrounding;

    void scanSurrounding();

public:
    CDreadnought(int typ, int x, int y, CMap &map);
    void calc_move_area() override;
    void calc_attack_area() override;
    void do_turn() override;
    int get_nearest();
};


#endif //LASERCHESS_CDREADNOUGHT_H
