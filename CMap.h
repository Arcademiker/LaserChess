//
// Created by arcademiker on 20.07.18.
//

#ifndef LASERCHESS_CMAP_H
#define LASERCHESS_CMAP_H

#include <vector>
#include <iostream>
#include <unordered_map>

#include "CUnit.h"


class CUnit;
class CMap {
private:
    std::vector<std::vector<int>> grid;
    std::unordered_map<int,CUnit*> unit_list;
    unsigned int unitCounter;

public:
    CMap();
    void set(int x, int y, int id);
    int get(int x, int y);
    CUnit* get_unit(int x, int y);
    CUnit* get_unit(int id);
    void add_unit(int type, int x, int y);
    bool kill_unit(int id);
    bool move(int x, int y, int to_x, int to_y);
    void print();
    void listAllUnits();
};


#endif //LASERCHESS_CMAP_H
