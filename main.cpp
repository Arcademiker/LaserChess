#include <iostream>
#include "CMap.h"

CMap* generate_map(int level);
void gameloop(CMap* map);
void print_options(CUnit* unit, CMap* map);

int main() {
    for(int Level = 1; Level <= 3; ++Level) {
        CMap* map = generate_map(Level);
        std::cout << std::endl << "++++++++++++++++++  LEVEL " << Level << "  ++++++++++++++++++" << std::endl;
        gameloop(map);
        delete map;
    }
    return 0;
}

void gameloop(CMap* map) {
    int round = 0;
    while (true) { //todo: escape key
        map->listAllUnits();
        std::cout << std::endl << "******************  ROUND " << round << "  ******************" << std::endl << std::endl;
        for(auto& U: *map->get_unit_list()) {
            map->print();
            U.second->calc_move_area();
            print_options(U.second,map);
            U.second->do_move();
            if(U.second->calc_attack_options()) {
                print_options(U.second,map);
                U.second->do_attack();
            }
        }
        map->print();
        if(map->get_enemys_list()->empty() || map->get_commandU_counter() <= 0) {
            map->listAllUnits();
            std::cout << std::endl << "!PLAYER WINS!" << std::endl;
            break;
        }
        for(auto& E: *map->get_enemys_list()) {
            E.second->do_move();
            E.second->do_attack();
        }
        map->print();
        if(map->get_unit_list()->empty()) {
            map->listAllUnits();
            std::cout << std::endl << "!AI WINS!" << std::endl;
            break;
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

            map->add_unit(1,6,0);
            map->add_unit(1,6,1);
            map->add_unit(1,6,2);
            map->add_unit(1,6,4);
            map->add_unit(1,6,5);
            map->add_unit(1,6,6);
            map->add_unit(1,6,7);
            map->add_unit(2,6,3);
            map->add_unit(3,5,3);
            map->add_unit(3,7,2);
            map->add_unit(3,7,4);
            map->add_unit(3,7,0);
            map->add_unit(3,7,6);

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

