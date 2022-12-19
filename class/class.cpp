#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "class.h"
using std:: string;
using std:: cin;
using std:: cout;
using std:: vector;

// Member

// House

// Admin
 Admin::Admin() {}
 void Admin::showAllMember(){
     cout << "All the member of the system: " << "\n";
    for(auto *member:members) {
        cout << std::setw(10) << member->memberID << " ";
    }
 }
 void Admin::showAllHouse() {
    cout << "All house of the system: " << "\n";
    for(auto &house:houseList){
        cout << std::setw(10) << house->houseID << " ";
    }
 }

 void Admin::viewHouseDetail(int id) {

 }
//Request

// HouseList

//Rating

// Rating Tenant

// System

// User
