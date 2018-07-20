#include <iostream>
#include "CMap.h"

int main() {
    CMap map;
    map.add_unit(1,2,3);
    map.add_unit(2,4,3);
    map.print();
    map.kill_unit(1);
    map.print();
    map.listAllUnits();
    map.add_unit(1,2,3);
    map.listAllUnits();
    map.print();
    map.add_unit(2,2,3);
    map.listAllUnits();
    map.print();
    return 0;
}