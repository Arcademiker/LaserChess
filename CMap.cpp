//
// Created by arcademiker on 20.07.18.
//

#include "CMap.h"



void CMap::set(int x, int y, int id) {
    this->grid[y][x] = id;
}

CMap::CMap() {
    unsigned int size = 8;
    this->unitCounter = 0;
    this->enemyCounter = 0;
    this->grid = std::vector<std::vector<int>>(size,std::vector<int>(size,0));
}

/// get unit id that occupated filed at position (x,y) or 0 if free
int CMap::get(int x, int y) {
    return this->grid[y][x];
}

CUnit* CMap::get_unit(int x, int y) {
    if(this->get(x,y) < 0) {
        return this->enemy_list.at(this->get(x,y));
    }
    else {
        return this->unit_list.at(this->get(x,y));
    }

}

CUnit* CMap::get_unit(int id) {
    if(id < 0) {
        return this->enemy_list.at(id);
    }
    else {
        return this->unit_list.at(id);
    }
}

/// attention: replaces unit if space is occupied
void CMap::add_unit(int type, int x, int y) {
    if(type < 4) {
        this->unitCounter++;
        //CUnit* unit = new CUnit(type, x, y, *this);
        this->unit_list.insert({ this->unitCounter, new CUnit(type, x, y, *this)});
        this->grid[y][x] = unitCounter;
    }
    else {
        this->enemyCounter++;
        //CUnit* unit = new CUnit(type, x, y, *this);
        this->enemy_list.insert({ -this->enemyCounter, new CUnit(type, x, y, *this)});
        this->grid[y][x] = -enemyCounter;
    }
}

bool CMap::kill_unit(int id) {
    std::unordered_map<int,CUnit*>* pList;
    if(id<0) {
        pList = &enemy_list;
    }
    else {
        pList = &unit_list;
    }
    if (pList->count(id) != 0) {
        set(pList->at(id)->get_x(), pList->at(id)->get_y(), 0);
        pList->erase(id);
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

int CMap::distance(int x, int y, int to_x, int to_y) {
    return std::abs(x-to_x)+std::abs(y-to_y);
}
std::unordered_map<int,CUnit*>* CMap::get_enemys_list() {
    return &this->enemy_list;
}
std::unordered_map<int,CUnit*>* CMap::get_unit_list() {
    return &this->unit_list;
}

void CMap::print() {
    for(int y = 0; y < this->grid.size(); ++y) {
        for(int x = 0; x < this->grid[0].size(); ++x) {
            if(this->get(x,y) < 0) {
                std::cout << this->get(x,y);
            }
            else if(this->get(x,y) > 0) {
                std::cout << "+" << this->get(x,y);
            }
            else {
                std::cout << " 0";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void CMap::listAllUnits() {
    for ( auto& U: this->unit_list ) {
        std::cout << "+" << U.first << ": " << U.second->get_type()
                  << " - (x, y): (" << U.second->get_x() << ", " << U.second->get_y() << ")" << std::endl;
    }
    std::cout << std::endl;
    for ( auto& U: this->enemy_list ) {
        std::cout << U.first << ": " << U.second->get_type()
                  << " - (x, y): (" << U.second->get_x() << ", " << U.second->get_y() << ")" << std::endl;
    }
    std::cout << std::endl;
}






