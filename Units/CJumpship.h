//
// Created by arcademiker on 22.07.18.
//

#ifndef LASERCHESS_CJUMPSHIP_H
#define LASERCHESS_CJUMPSHIP_H

#include "../CUnit_Player.h"

class CJumpship : public CUnit_Player {
public:
    CJumpship(int typ, int x, int y, CMap &map);
    void do_turn() override;
};


#endif //LASERCHESS_CJUMPSHIP_H
