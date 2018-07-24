#include <iostream>
#include "CMap.h"

int main() {
    CMap map;
    map.add_unit(6,2,3);
    map.add_unit(5,2,6);
    map.add_unit(1,2,7);
    map.add_unit(5,0,3);
    map.add_unit(2,3,3);
    map.add_unit(4,0,5);
    map.print();
    map.listAllUnits();
    map.get_unit(2,3)->move(5,6);
    map.print();
    map.listAllUnits();
    map.get_unit(2)->do_turn();
    map.get_unit(2,7)->do_turn();
    map.get_unit(3,3)->do_turn();
    map.print();
    map.listAllUnits();
    map.get_unit(2)->do_turn();
    //map.get_unit(-1)->do_turn();
    map.get_unit(-2)->do_turn();
    map.print();
    map.listAllUnits();
    map.get_unit(2)->do_turn();
    map.get_unit(-2)->do_turn();
    map.print();
    map.listAllUnits();
    map.get_unit(2)->do_turn();
    map.get_unit(-2)->do_turn();
    map.print();
    map.listAllUnits();
    map.get_unit(2)->do_turn();
    map.get_unit(-2)->do_turn();
    map.print();
    map.listAllUnits();
    map.get_unit(2)->do_turn();
    map.get_unit(-2)->do_turn();
    map.print();
    map.listAllUnits();
    map.get_unit(2)->do_turn();
    map.get_unit(-2)->do_turn();
    map.print();
    map.listAllUnits();
    map.get_unit(2)->do_turn();
    map.get_unit(-2)->do_turn();
    map.print();
    map.listAllUnits();
    return 0;
}