//
// Created by arcademiker on 22.07.18.
//

#ifndef LASERCHESS_CTANK_H
#define LASERCHESS_CTANK_H

#include "../CUnit_Player.h"

class CTank : public CUnit_Player {
public:
    CTank(int typ, int x, int y, CMap &map);
    void do_turn() override;
};


#endif //LASERCHESS_CTANK_H
