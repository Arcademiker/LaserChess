#include <iostream>
#include <map>

#include "CMap.h"

CMap* generate_map(int level);
bool gameloop(CMap* map);
void print_options(CUnit* unit, CMap* map);
int user_input(std::map<int,CUnit*>* UMap);

int main() {
    for(int Level = 2; Level <= 3; ++Level) {
        CMap* map = generate_map(Level);
        std::cout << std::endl << "++++++++++++++++++  LEVEL " << Level << "  ++++++++++++++++++" << std::endl;
        if(!gameloop(map)) {
            Level--;
        }
        delete map;
    }
    return 0;
}

bool gameloop(CMap* map) {
    int round = 0;
    while (true) { //todo: escape key
        map->listAllUnits();
        std::cout << std::endl << "******************  ROUND " << round << "  ******************" << std::endl << std::endl;
        auto* UMap = new std::map<int,CUnit*>;
        for(auto& U: *map->get_unit_list()) {
            UMap->insert(U);
        }
        int id;
        CUnit* U;
        while(!UMap->empty()) {
            map->print(UMap);
            id = user_input(UMap);
            if(id == 0) {
                id = UMap->begin()->first;
                U = UMap->begin()->second;
            } else {
                U = UMap->at(id);
            }
            U->calc_move_area();
            print_options(U,map);
            U->do_move();
            if(U->calc_attack_options()) {
                print_options(U,map);
                U->do_attack();
            }
            UMap->erase(id);
        }
        delete UMap;
        map->print();
        if(map->get_enemys_list()->empty() || map->get_commandU_counter() <= 0) {
            map->listAllUnits();
            std::cout << std::endl << "!PLAYER WINS!" << std::endl;
            return true;
        }
        auto* EMap = new std::multimap<int,CUnit*>;
        for(auto& E: *map->get_enemys_list()) {
            EMap->insert({E.second->get_type(),E.second});
        }
        for(auto& E: *EMap) {
            E.second->do_move();
            E.second->do_attack();
        }
        delete EMap;
        map->print();
        if(map->get_unit_list()->empty()) {
            map->listAllUnits();
            std::cout << std::endl << "!AI WINS!" << std::endl;
            return false;
        }
        round++;
    }
}

CMap* generate_map(int level) {
    auto map = new CMap();
    switch(level){
        case 1:
            map->add_unit(4,1,2);
            map->add_unit(4,1,3);
            map->add_unit(4,1,4);
            map->add_unit(4,1,5);
            map->add_unit(5,0,3);
            map->add_unit(5,0,4);
            map->add_unit(6,0,2);
            map->add_unit(6,0,5);

            map->add_unit(1,7,0);
            map->add_unit(1,7,7);
            map->add_unit(1,6,1);
            map->add_unit(1,6,6);
            map->add_unit(1,5,2);
            map->add_unit(1,5,5);
            map->add_unit(1,4,3);
            map->add_unit(1,4,4);
            map->add_unit(2,7,4);
            map->add_unit(3,7,3);

            break;
        case 2:
            map->add_unit(4,1,1);
            map->add_unit(4,1,3);
            map->add_unit(4,1,5);
            map->add_unit(4,1,7);
            map->add_unit(6,0,0);
            map->add_unit(6,0,2);
            map->add_unit(6,0,4);
            map->add_unit(6,0,6);

            map->add_unit(1,5,0);
            map->add_unit(1,5,1);
            map->add_unit(1,5,2);
            map->add_unit(1,5,4);
            map->add_unit(1,5,5);
            map->add_unit(1,5,6);
            map->add_unit(1,5,7);
            map->add_unit(3,5,3);
            map->add_unit(2,4,3);
            map->add_unit(2,7,0);
            map->add_unit(2,7,1);
            map->add_unit(2,7,2);
            map->add_unit(2,7,3);
            map->add_unit(2,7,4);
            map->add_unit(2,7,5);
            map->add_unit(2,7,6);
            map->add_unit(2,7,7);

            break;
        case 3:
            map->add_unit(4,1,0);
            map->add_unit(4,1,1);
            map->add_unit(4,1,2);
            map->add_unit(4,1,3);
            map->add_unit(4,1,4);
            map->add_unit(4,1,5);
            map->add_unit(4,1,6);
            map->add_unit(4,1,7);
            map->add_unit(6,0,0);
            map->add_unit(5,0,1);
            map->add_unit(5,0,2);
            map->add_unit(6,0,3);
            map->add_unit(6,0,4);
            map->add_unit(5,0,5);
            map->add_unit(5,0,6);
            map->add_unit(6,0,7);

            map->add_unit(1,6,0);
            map->add_unit(1,6,1);
            map->add_unit(1,6,2);
            map->add_unit(1,6,3);
            map->add_unit(1,6,4);
            map->add_unit(1,6,5);
            map->add_unit(1,6,6);
            map->add_unit(1,6,7);
            map->add_unit(1,4,2);
            map->add_unit(1,4,3);
            map->add_unit(1,4,4);
            map->add_unit(1,4,5);
            map->add_unit(1,2,5);
            map->add_unit(1,5,5);
            map->add_unit(2,3,5);
            map->add_unit(2,4,5);
            map->add_unit(3,7,0);
            map->add_unit(2,7,1);
            map->add_unit(2,7,2);
            map->add_unit(2,7,3);
            map->add_unit(2,7,4);
            map->add_unit(2,7,5);
            map->add_unit(2,7,6);
            map->add_unit(3,7,7);

            break;
        default:
            return nullptr;
    }
    return map;
}

void print_options(CUnit* unit, CMap* map) {
    std::cout << "   0 1 2 3 4 5 6 7" << std::endl << std::endl;
    for(int y = 0; y < 8 ; ++y) {
        std::cout << y << " ";
        for(int x = 0; x < 8 ; ++x) {
            if(unit->get_player_optons()->at(y).at(x)) {
                std::cout << " " << map->get(x,y);
            }
            else {
                std::cout << " X";
            }
        }
        std::cout << std::endl;
    }
}

int user_input(std::map<int,CUnit*>* UMap) {
    ///replace with mouse input
    int id = -1;
    while (id != 0 ) {
        std::cin >> id;
        for(auto& U: *UMap) {
            if(id == U.first) {
                return id;
            }
        }
    }
    return id;
}







/*
     CMap map;
    //map.add_unit(6,2,3);
    map.add_unit(4,3,5);
    //map.add_unit(1,2,7);
    //map.add_unit(5,0,3);
    map.add_unit(3,3,3);
    //map.add_unit(4,0,5);
    map.print();
    map.listAllUnits();
    map.get_unit(1)->do_move();
    map.get_unit(-1)->do_move();
    map.print();
    map.listAllUnits();
    map.get_unit(1)->do_move();
    map.get_unit(-1)->do_move();
    for(int y = 0; y < 8 ; ++y) {
        for(int x = 0; x < 8 ; ++x) {
            if(map.get_unit(1)->get_attack_range()->at(y).at(x)) {
                std::cout << "1" << " ";
            }
            else {
                std::cout << "0" << " ";
            }
        }
        std::cout << std::endl;
    }
    map.print();
    map.listAllUnits();
    map.get_unit(1)->do_move();
    map.get_unit(-1)->do_move();
    map.print();
    map.listAllUnits();
    map.get_unit(1)->do_move();
    map.get_unit(-1)->do_move();
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
*/

