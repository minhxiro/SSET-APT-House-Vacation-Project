//
// Created by Vo Nguyen Kien on 19/12/2022.
//

#include "Class.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "class.h"
using std:: string;
using std:: cin;
using std:: cout;
using std:: vector;
using std:: fstream;

// Data File Path
const string member_file = "members.dat";
const string house_file = "house.dat";
const string rating_file = "rating.dat";
const string ratingTenant_file = "ratingTenant.dat";
const string request_file = "request.dat";
// Member
Member::Member() {};
void Member::showAllHouse(HouseList& allHouse) {

}

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
User::User() {}
void User:: login() {
    cout << "Enter the user name: ";
    cin >> this->name;
    cout << "Enter password: ";
    cin >> this->password;


}

void User::checkLogin() {
    // Read data of member:
    string *informationData = new string[1000];
    fstream file;
    file.open(member_file, std::ios::in);
    if(!file) {
        std::cerr << "Fail to open file\n";
    }
    int index = 0;
    while(!file.eof()) {
        file >> informationData[index];
        index++;
    }

    file.close();
    // Check password
    for(int i = 0; i < index; i++) {
        if((informationData[i].find(this->name) != std::string::npos) && (informationData[i].find(this->password) != std::string::npos)) {
            cout << "You have logined as " << this->name << "\n";
        }
        else cout <<"Wrong username or password\n";
    }
}

void User ::showAccountInfo() {
    cout << "Your full name is: " << this->full_name << "\n";
    cout << "Your phone number is: " << this->phonenum << "\n";
}

void User:: registre() {
    cout << "Enter your user name: ";
    cin >> this->name;
    cout << "Enter your pass word: ";
    do {
        getline(cin , this->password);
    } while (this->password == "");

    cout << "Enter your full name: ";
    getline(cin, this->full_name);

}

