#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Admin.h"
#include "User.h"

using std:: string;
using std:: cin;
using std:: cout;
using std:: vector;
using std:: fstream;

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
    file.open("members.dat", std::ios::in);
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