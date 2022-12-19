#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Admin.h"


using std:: string;
using std:: cin;
using std:: cout;
using std:: vector;
using std:: fstream;

Admin :: Admin() {}
void Admin :: showAllMember() {
    string *informationData = new string[1000];
    fstream file;
    file.open("members.dat", std::ios::in);
    if(!file) {
        std::cerr << "Fail to open file\n"; 
    }
    int index = 0;
    while(!file.eof()) {
        file >> informationData[index]; // Save data in a string
        index++;
    }

    file.close();
}