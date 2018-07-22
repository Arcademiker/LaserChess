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
    //void get_nearest();
    //void do_turn() override;
};


#endif //LASERCHESS_CUNIT_AI_H
