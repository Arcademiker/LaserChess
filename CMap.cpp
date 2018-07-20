//
// Created by arcademiker on 20.07.18.
//

#include "CMap.h"

CMap::CMap() {
    unsigned int size = 8;
    this->unitCounter = 0;
    this->grid = std::vector<std::vector<int>>(size,std::vector<int>(size,0));
}

int CMap::get(int x, int y) {
    return this->grid[y][x];
}

void CMap::set(int x, int y, int type) {
    this->grid[y][x] = type;
}

// replaces unit if space is occupied
void CMap::add_unit(int type, int x, int y) {
    this->unitCounter++;
    this->unit_list.insert({ this->unitCounter, CUnit(type, x, y) });
    this->grid[y][x] = type;
}

bool CMap::kill_unit(int id) {
    if (this->unit_list.count(id) != 0) {
        set(this->unit_list.at(id).get_x(), this->unit_list.at(id).get_y(), 0);
        this->unit_list.erase(id);
        return true;
    }
    return false;

}


void CMap::print() {
    for(int y = 0; y < this->grid.size(); ++y) {
        for(int x = 0; x < this->grid[0].size(); ++x) {
            std::cout << this->get(x,y) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void CMap::listAllUnits() {
    for ( auto& x: this->unit_list ) {
        std::cout << x.first << ": " << x.second.get_type() << std::endl;
    }
    std::cout << std::endl;
}



