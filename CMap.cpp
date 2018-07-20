//
// Created by arcademiker on 20.07.18.
//

#include "CMap.h"




CMap::CMap() {
    unsigned int size = 8;
    this->unitCounter = 0;
    this->grid = std::vector<std::vector<int>>(size,std::vector<int>(size,0));
}

/// get unit id that occupated filed at position (x,y) or 0 if free
int CMap::get(int x, int y) {
    return this->grid[y][x];
}

CUnit* CMap::get_unit(int x, int y) {
    return this->unit_list.at(this->get(x,y));
}

CUnit* CMap::get_unit(int id) {
    return this->unit_list.at(id);
}

void CMap::set(int x, int y, int id) {
    this->grid[y][x] = id;
}

/// attention: replaces unit if space is occupied
void CMap::add_unit(int type, int x, int y) {
    this->unitCounter++;
    //CUnit* unit = new CUnit(type, x, y, *this);
    this->unit_list.insert({ this->unitCounter, new CUnit(type, x, y, *this) });
    this->grid[y][x] = unitCounter;
}

bool CMap::kill_unit(int id) {
    if (this->unit_list.count(id) != 0) {
        set(this->unit_list.at(id)->get_x(), this->unit_list.at(id)->get_y(), 0);
        this->unit_list.erase(id);
        return true;
    }
    return false;

}

//attention this function doesn't update the new location in the unit class
bool CMap::move(int x, int y, int to_x, int to_y) {
    int id = this->get(x, y);
    if(this->get(to_x, to_y)==0){
        this->set(x, y, 0);
        this->set(to_x, to_y, id);
        return true;
    }
    else {
        return false;
    }
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
    for ( auto& U: this->unit_list ) {
        std::cout << U.first << ": " << U.second->get_type() << " - (x, y): (" << U.second->get_x() << ", " << U.second->get_y() << ")" << std::endl;
    }
    std::cout << std::endl;
}




