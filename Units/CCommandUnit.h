//
// Created by arcademiker on 22.07.18.
//

#ifndef LASERCHESS_CCOMMANDUNIT_H
#define LASERCHESS_CCOMMANDUNIT_H

#include "../CUnit_AI.h"

class CCommandUnit : public CUnit_AI {
public:
    CCommandUnit(int typ, int x, int y, CMap &map);
    void do_turn() override;
};


#endif //LASERCHESS_CCOMMANDUNIT_H
