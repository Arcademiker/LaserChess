//
// Created by arcademiker on 22.07.18.
//

#ifndef LASERCHESS_CUNIT_PLAYER_H
#define LASERCHESS_CUNIT_PLAYER_H

#include "CUnit.h"

class CUnit_Player : public CUnit{
public:
    CUnit_Player(int typ, int x, int y, CMap &map);
    bool attack(int to_x, int to_y) override;
    //void do_turn() override; /// pure virtual
};


#endif //LASERCHESS_CUNIT_PLAYER_H
