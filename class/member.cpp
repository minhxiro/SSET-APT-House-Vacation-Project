#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Member.h"


using std:: string;
using std:: cin;
using std:: cout;
using std:: vector;
using std:: fstream;
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
