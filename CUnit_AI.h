//
// Created by arcademiker on 20.07.18.
//

#ifndef LASERCHESS_CUNIT_AI_H
#define LASERCHESS_CUNIT_AI_H


#include "CUnit.h"

class CUnit_AI : public CUnit {
private:

public:
    CUnit_AI(int typ, int x, int y, CMap &map);
    bool attack(int to_x, int to_y) override;
    bool attack(int target_id) override ;
    //void do_turn() override;
};


#endif //LASERCHESS_CUNIT_AI_H
