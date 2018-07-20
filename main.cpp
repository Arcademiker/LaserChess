#include <iostream>
#include "CMap.h"

int main() {
    CMap map;
    map.add_unit(1,2,3);
    map.add_unit(5,4,3);
    map.print();
    map.kill_unit(1);
    map.print();
    map.listAllUnits();
    map.add_unit(1,2,3);
    map.add_unit(1,0,3);
    map.listAllUnits();
    map.print();
    map.add_unit(4,2,3); //replace unit (buggy but user doesn't add units manually. cannot occur ingame if level is createtd properly)
    map.listAllUnits();
    map.print();
    map.get_unit(2,3)->move(5,6);
    map.print();
    map.listAllUnits();
    return 0;
}