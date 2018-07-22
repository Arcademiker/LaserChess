//
// Created by arcademiker on 22.07.18.
//

#ifndef LASERCHESS_CGRUNT_H
#define LASERCHESS_CGRUNT_H

#include "../CUnit_Player.h"

class CGrunt : public CUnit_Player {
public:
    CGrunt(int typ, int x, int y, CMap &map);
    void do_turn() override;
};


#endif //LASERCHESS_CGRUNT_H
