#include <iostream>
#include <string>
#include <vector>
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


void Member ::showAccountInfo() {
    cout << "Your full name is: " << this->full_name << "\n";
    cout << "Your phone number is: " << this->phonenum << "\n";
    cout << "Your ID is: " << this->memberID << "\n";
    cout << "Your credit is: " << this->credit << "\n";
    cout <<"Your rating score is: " << this->rating_score << "\n";
}

void Member:: registre() {
    House houses;
    int cities;
    cout << "Enter your user name: "; // Prompt user enter user name
    cin >> this->name;
    cout << "Enter your pass word: "; // Prompt user enter password
    do {
        getline(cin , this->password);
    } while (this->password == "");

    cout << "Enter your full name: "; // Prompt user enter full name
    getline(cin, this->full_name);
    cout << "Enter your city: "; // Prompt user enter city
    cin >> cities;
    // Get enum input
    this->location = static_cast<city>(cities);
    //Save member data into file
    std:: ofstream file;
     file.open("members.dat", std::ios_base::app);
    if(!file) {
        std::cerr << "error to open file";
    }
    file << this->name << ":" << this->password << ":" << this->full_name << ":" << this->location <<"\n";
}


// House

// Admin
Admin :: Admin() {}
void Admin :: showAllMember() {
    string *informationData = new string[1000];
    fstream file;
    file.open(member_file, std::ios::in);
    if(!file) {
        std::cerr << "Fail to open file\n"; 
    }
    int index = 0;
    while(!file.eof()) {
        file >> informationData[index]; // Save data in a string
        index++;
    }

    file.close();

    // Shouw the information
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
    // Check password and prompt user enter again if password is incorrect
    while (1) {
        for(int i = 0; i < index; i++) {
        if((informationData[i].find(this->name) != std::string::npos) && (informationData[i].find(this->password) != std::string::npos)) {
            cout << "You have logined as " << this->name << "\n";
            break;
        }
        else {
            cout <<"Wrong username or password\n";
            this->login();
        } 
    }
    
}
}



    