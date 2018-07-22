#include <iostream>
#include "CMap.h"

int main() {
    CMap map;
    map.add_unit(3,2,3);
    map.add_unit(1,1,1);
    map.add_unit(4,2,6);
    map.add_unit(2,0,3);
    map.add_unit(5,3,3);
    map.print();
    map.listAllUnits();
    map.get_unit(2,3)->move(5,6);
    map.print();
    map.listAllUnits();
    map.get_unit(2,6)->do_turn();
    map.get_unit(3,3)->do_turn();
    map.print();
    map.listAllUnits();
    map.get_unit(-1)->do_turn();
    map.get_unit(-2)->do_turn();
    map.print();
    map.listAllUnits();
    map.get_unit(-2)->do_turn();
    map.print();
    map.listAllUnits();
    map.get_unit(-2)->do_turn();
    map.print();
    map.listAllUnits();
    map.get_unit(-2)->do_turn();
    map.print();
    map.listAllUnits();
    map.get_unit(-2)->do_turn();
    map.print();
    map.listAllUnits();
    return 0;
}