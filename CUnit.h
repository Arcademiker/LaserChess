//
// Created by arcademiker on 20.07.18.
//

#ifndef LASERCHESS_CUNIT_H
#define LASERCHESS_CUNIT_H


class CUnit {
private:
    int type;
    int health;
    int x; //todo: necessary? 
    int y;
public:
    CUnit(int typ, int x, int y);
    int get_type();
    int get_x();
    int get_y();
};


#endif //LASERCHESS_CUNIT_H
