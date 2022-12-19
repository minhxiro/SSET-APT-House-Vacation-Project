#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "class.h"
#include <regex>

using std:: string;
using std:: cin;
using std:: cout;
using std:: vector;
using std:: fstream;
using std::regex;
// Data File Path
const string DATA_PATH = "data/";
const string member_file = "members.dat";
const string house_file = "house.dat";
const string rating_file = "rating.dat";
const string ratingTenant_file = "ratingTenant.dat";
const string request_file = "request.dat";

string getFilePath(const string& fileName) {
    return DATA_PATH + fileName;
}


// System
    string  trimString(string str) {
    string finalStr = "";
    for (char ch: str) {
        if (ch == ' ') {
            continue;
        } else {
            finalStr += ch;
        }
    }
    return finalStr;
}


bool inputUsernameAuthentication(string username) {
    //false: Username should only contain 8 to 15 character and no white spaces!!!
    //true: continue
    regex reg("\\s");
    if (std::regex_match(username, reg)) {
        return false;
    } else {
        if (8 > username.length() || username.length() > 16) {
            return false;
        } else {
            return true;
        }
    }
}

bool inputNameAuthentication(string &name) {
    //false: Name must contain 8 to 20 characters and no digits, no special characters, and no white spaces
    //true: continue
    regex reg("^[a-zA-Z]*{8,20}$");
    name = trimString(name);
    if (std::regex_match(name, reg)) {
        return true;
    } else {
        return false;
    }
}

bool inputPasswordAuthenticate(string &password) {
    //false: Minimum 8 and maximum 10 characters, at least one uppercase letter, one lowercase letter, one number and one special character:
    //true: continue
    regex reg("^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[@$!%*?&])[A-Za-z0-9@$!%*?&]{8,10}$");
    password = trimString(password);
    if (std::regex_match(password, reg)) {
        return true;
    } else {
        return false;
    }

}

bool inputPhoneAuthenticate(string &phoneNum) {
    //false: phone number must have 11 numbers and start with 0
    //true: continue
    regex reg("^(?=0)[0-9]{10}$");
    phoneNum = trimString(phoneNum);
    if (std::regex_match(phoneNum, reg)) {
        return true;
    } else {
        return false;
    }
}


bool inputNumAuthenticate(string &num) {
    //false: The input must be a number
    //true: continue
    regex reg("^[0-9]$");
    num = trimString(num);
    if (std::regex_match(num, reg)) {
        return true;
    } else {
        return false;
    }
}


bool inputRangeAuthenticate(string &range) {
    //false: Range must be in this format number - number
    //true: continue
    regex reg("^[0-9]+[-][0-9]+$");
    range = trimString(range);
    if (std::regex_match(range, reg)) {
        return true;
    } else {
        return false;
    }
}


bool creditAuth(int credits);

bool scoreAuth(int scores);

void addData(string data, string dataFile) {
    std::fstream file;
    file.open(dataFile, std::ios::app);
    if (file.fail()) {
        cout << "Cannot reach the database \n";
    } else {
        file << "\n" + data;
        cout << "Your information has been successfully added! \n";
        file.close();
    }
}

vector<vector<string> > extractByRow(string dataFile) {
    std::fstream file;
    string dataLine;
    std::vector<vector<string> > dataTable;
    std::vector<string> dataRowsArray;
    string cell;
    file.open(dataFile, std::ios::in);
    if (file.fail()) {
        cout << "Cannot reach the database \n";
    } else {
        while (!file.eof()) {
            std::stringstream ss;
            dataRowsArray = {};
            std::getline(file, dataLine);
            ss << dataLine;
            while (!ss.eof()) {
                std::getline(ss, cell, ';');
                dataRowsArray.push_back(cell);
            }
            dataTable.push_back(dataRowsArray);
        }
        file.close();
    }
    return dataTable;
}

vector<string> extractByColumnIndex(int index, string dataFile) {
    std::fstream file;
    string dataLine;
    std::vector<string> dataColumnArray;
    std::vector<string> dataRowsArray;
    string cell;
    file.open(dataFile, std::ios::in);
    if (file.fail()) {
        cout << "Cannot reach the database \n";
    } else {
        while (!file.eof()) {
            std::stringstream ss;
            dataRowsArray = {};
            std::getline(file, dataLine);
            ss << dataLine;
            while (!ss.eof()) {
                std::getline(ss, cell, ';');
                dataRowsArray.push_back(cell);
            }
            dataColumnArray.push_back(dataRowsArray[index]);
        }
        file.close();
    }
    return dataColumnArray;
}

void updateRowAtIndex(int index, string data, string dataFile) {
    std::ifstream readFile;
    std::ofstream writeFile;
    int count = 0;
    string tempData;
    readFile.open(dataFile);
    if (readFile.fail()) {
        cout << "Cannot reach the database \n";
    } else {
        writeFile.open("./data/memberTemp.dat", std::ios::app);
        while (!readFile.eof()) {
            getline(readFile, tempData);
            count++;
            if (count == index) {
                writeFile << "\n" + data;
            } else {
                if (count == 1) {
                    writeFile << tempData;
                } else {
                    writeFile << "\n" + tempData;
                }
            }
        }
        readFile.close();
        writeFile.close();
    }
    remove("./data/members.dat");
    rename("./data/memberTemp.dat", "./data/members.dat");
}

string getCurrentDate() {
    string dateString;
    time_t t = time(NULL);
    tm *timePtr = localtime(&t);
    dateString = std::to_string(timePtr->tm_mday) + "/" + std::to_string((timePtr->tm_mon) + 1) + "/" +
                 std::to_string((timePtr->tm_year) + 1900);
    return dateString;
}

int idAutoIncrement(string dataFile) {
    std::fstream file;
    string dummy;
    int count = 0;
    file.open(dataFile, std::ios::in);
    if (file.fail()) {
        cout << "Cannot reach the database \n";
    } else {
        while (!file.eof()) {
            getline(file, dummy);
            count++;
        }
        file.close();
    }
    return count;
}
// Member
Member::Member() {};
void Member::showAllHouse() {

}
void Member :: showAccountInfo() {
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
    addData(this->name, getFilePath(member_file));
    cout << "Enter your pass word: "; // Prompt user enter password
    do {
        getline(cin , this->password);
    } while (this->password == "");
    addData(this->password, getFilePath(member_file));
    cout << "Enter your full name: "; // Prompt user enter full name
    getline(cin, this->full_name);
    addData(this->full_name, getFilePath(member_file));
    cout << "Enter your city: "; // Prompt user enter city
    cin >> cities;
    // Get enum input
    this->location = static_cast<city>(cities);
    //Save member data into file
    
}

Request Member ::declineRequest() {
    
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




int main() {
    std::vector<string> data;
    addData("1;23;wgsdfag;wertqwetwqet;qwetqwetqwet", "./data/members.dat");
    updateRowAtIndex(2, "1;trung2", "./data/members.dat");
    cout << getCurrentDate() << "\n";
    cout << idAutoIncrement("./data/members.dat") << "\n";
}
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