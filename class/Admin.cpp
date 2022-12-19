//
// Created by Vo Nguyen Kien on 18/12/2022.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include "System.h"
#include "Admin.h"
#include <regex>
using std::cin;
using std::cout;
using std::vector;
using std::string;
void showAllMember(){
    cout << "All the member of the system: " << "\n";
    for(auto *member:members) {
        cout << std::setw(10) << member->memberID << " ";
    }
}
void showAllHouse() {
    cout << "All house of the system: " << "\n";
    for(auto &house:houseList){
        cout << std::setw(10) << house->houseID << " ";
    }
}
