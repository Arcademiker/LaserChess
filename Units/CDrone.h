//
// Created by arcademiker on 22.07.18.
//

#ifndef LASERCHESS_CDRONE_H
#define LASERCHESS_CDRONE_H

#include "../CUnit_AI.h"

class CDrone : public CUnit_AI {
public:
    CDrone(int typ, int x, int y, CMap &map);
    void do_turn() override;
};


#endif //LASERCHESS_CDRONE_H
