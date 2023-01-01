#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <map>
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
 

//bool System::isInteger(string num) {
//    for (char ch: num) {
//        if (ch == '.') {
//            return false;
//        }
//    }
//    return true;
//}

    string System ::trimString(string str) {
    string finalStr;
    for (char ch: str) {
        if (ch == ' ') {
            continue;
        } else {
            finalStr += ch;
        }
    }
    return finalStr;
}

vector<int> System::getIndex(vector<string> lst, string K) {
    vector<int> indices;
    for (int i = 0; i < lst.size(); i++) {
        if (lst[i] == K) {
            indices.push_back(i);
        }
    }
    return indices;
}

vector<string> System::splitStr(string str, char del) {
    vector<string> dataLst;
    std::stringstream ss;
    ss << str;
    string cell;
    while (!ss.eof()) {
        std::getline(ss, cell, del);
        dataLst.push_back(cell);
    }
    return dataLst;
}


bool System::inputUsernameAuthentication(string username) {
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

bool System::inputNameAuthentication(string &name) {
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

bool System::inputPasswordAuthenticate(string &password) {
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

bool System::inputPhoneAuthenticate(string &phoneNum) {
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


bool System::inputNumAuthenticate(string &num) {
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


bool System::inputRangeAuthenticate(string &range) {
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


bool System::creditAuth(int credits) {

}

bool System::scoreAuth(int scores) {

}

void System::addData(string data, string dataFile) {
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

vector<vector<string> > System::extractByRow(string dataFile) {
    std::fstream file;
    string dataLine;
    std::vector<vector<string> > dataTable;
    std::vector<string> dataRowsArray;
    file.open(dataFile, std::ios::in);
    if (file.fail()) {
        cout << "Cannot reach the database \n";
    } else {
        while (!file.eof()) {
            dataRowsArray = {};
            std::getline(file, dataLine);
            dataRowsArray = splitStr(dataLine, ';');
            dataTable.push_back(dataRowsArray);
        }
        file.close();
    }
    return dataTable;
}

 vector<string> System::extractByColumnIndex(int index, string dataFile) {
    std::fstream file;
    string dataLine;
    std::vector<string> dataColumnArray;
    std::vector<string> dataRowsArray;
    file.open(dataFile, std::ios::in);
    if (file.fail()) {
        cout << "Cannot reach the database \n";
    } else {
        while (!file.eof()) {
            std::stringstream ss;
            dataRowsArray = {};
            std::getline(file, dataLine);
            dataRowsArray = splitStr(dataLine, ';');
            dataColumnArray.push_back(dataRowsArray[index]);
        }
        file.close();
    }
    return dataColumnArray;
}

void System::updateRowAtIndex(int index, string data, string dataFile, string newDataFile) {
    std::ifstream readFile;
    std::ofstream writeFile;
    int count = 0;
    string tempData;
    readFile.open(dataFile);
    if (readFile.fail()) {
        cout << "Cannot reach the database \n";
    } else {
        writeFile.open(newDataFile, std::ios::app);
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
    remove(dataFile.c_str());
    rename(newDataFile.c_str(), dataFile.c_str());
}

void System::deleteRowData(int index, string dataFile) {
    std::ifstream readFile;
    std::ofstream writeFile;
    int count = 0;
    string tempData;
    readFile.open(dataFile);
    if (readFile.fail()) {
        cout << "Cannot reach the database \n";
    } else {
        writeFile.open("./data/dataTemp.dat", std::ios::app);
        while (!readFile.eof()) {
            getline(readFile, tempData);
            count++;
            if (count == index) {
                continue;
            } else {
                if ((count - 1) == 1) {
                    writeFile << tempData;
                } else {
                    writeFile << "\n" + tempData;
                }
            }
        }
        readFile.close();
        writeFile.close();
    }
    remove(dataFile.c_str());
    rename("./data/dataTemp.dat", dataFile.c_str());
}

string System::getCurrentDate() {
    string dateString;
    time_t t = time(NULL);
    tm *timePtr = localtime(&t);
    dateString = std::to_string(timePtr->tm_mday) + "/" + std::to_string((timePtr->tm_mon) + 1) + "/" +
                 std::to_string((timePtr->tm_year) + 1900);
    return dateString;
}

int System::idAutoIncrement(string dataFile) {
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

vector<vector<string> > System::sortAscending(int index, string dataFile) {
    //extract the data from the dataFile
    vector<vector<string> > data = extractByRow(dataFile);
    for (int i = 0; i < data.size(); i++) {
        if (i == data.size() - 1) {
            break;
        }
        for (int j = 1; j < data.size(); j++) {
            vector<string> dataString = {};
            if (std::stof(data[i][index]) > std::stof(data[j][index])) {
                std::iter_swap(data.begin() + i, data.begin() + j);
            }
        }
    }
    //return sorted vector
    return data;
}


//This function require the index of column that need to be compare to the type, a type (ex: Hue, Sg, Hn) and then cout all the row of the same type 
void System::sortByCategory(string type, string dataFile, int index) {
    std::fstream file;
    std::vector<vector<string> > data;
    int count = 0;
    type = trimString(type);
    transform(type.begin(), type.end(), type.begin(), ::tolower);

    data = extractByRow(dataFile);
    for (vector<string> dataStr: data) {
        if (dataStr[index] == type) {
            count ++;
            for (int j = 0; j < dataStr.size(); j++) {
                cout << dataStr[j] << "\t";
            }
            cout << "\n";
        }
    }
    if(count == 0){
        cout << "Your input cannot be found in the database \n";
    }
}

void System::searchByDate(int mode, string day, string month, int index, string dataFile) {
    //mode 1: search by day of the request (searchByDate(1,<the day>,0) let month = 0)
    //mode 2: search by month of the request (searchByDate(2,0,<the month>) let day = 0)
    vector<vector<string> > data = extractByRow(dataFile);
    vector<int> indexLst;
    if (mode == 1) {
        vector<string> days;
        //get the date column
        for (string date: extractByColumnIndex(index, dataFile)) {
            //split the date by / and get the day add to the day vector
            days.push_back(splitStr(date, '/')[0]);
        }
        indexLst = getIndex(days, day);
        if(indexLst.size() == 0){
            cout << "Your input day cannot be found in the database \n";
        }else{
            for (int i: indexLst) {
                for (int j = 0; j < data[i].size(); j++) {
                    cout << data[i][j] << "\t";
                }
                cout << "\n";
            }
        }
    }
    if (mode == 2) {
        vector<string> months;
        //get the date column
        for (string date: extractByColumnIndex(index, dataFile)) {
            //split the date by / and get the day add to the day vector
            months.push_back(splitStr(date, '/')[1]);
        }
        indexLst = getIndex(months, month);
        if(indexLst.size() == 0){
            cout << "Your input month cannot be found in the database \n";
        }else{

            for (int i: indexLst) {
                for (int j = 0; j < data[i].size(); j++) {
                    cout << data[i][j] << "\t";
                }
                cout << "\n";
            }
        }
    }
}




// Member
Member::Member() {

}
void Member::showAllHouse() {
    cout << "List of available houses is being showed below:\n";
    vector <string> listofHouse;
    listofHouse = System:: extractByColumnIndex(0, house_file);

    cout << "House name: \n";
    for(string &obj : listofHouse) {
        cout <<obj << " ";
    }
}
void Member :: showAccountInfo() {
    cout << "Your full name is: " << this->full_name << "\n";
    cout << "Your phone number is: " << this->phonenum << "\n";
    cout << "Your ID is: " << this->memberID << "\n";
    cout << "Your credit is: " << this->credit << "\n";
    cout <<"Your rating score is: " << this->rating_score << "\n";
}
Request Member ::requestHouse() {
    int n;
    string houseID;
    // Get house ID in a vector
    vector <string> listHouse = System::extractByColumnIndex(1, house_file); // Note
    cout << "How many houses you want to request? ";
    cin >> n;
    // Enter house ID to find house
    for(int i = 0; i < n; i++) {
        cout << "Enter the house ID: ";
        getline(cin, houseID);
        for(string &tmp : listHouse) {
            while(houseID != tmp) {
                cout <<"Your house is not added in the list\n";
            }
            if(houseID == tmp) {
                cout << "Successful to request house";
                System::addData(houseID,getFilePath(request_file));
                Request obj;
                obj.houseId = std:: stoi(houseID);
                this->allRequest.push_back(obj);
            }
        }
    }
}

void Member ::rateHouse() {
    std :: stringstream convert;
    int houseID;
    cout << "Enter ID of the house you want to rate: ";
    cin >> houseID;
    for(House *obj : this->houseList) {
        if(houseID == obj->houseID) {
            cout << "Enter the score: "; // Prompt user to enter the score
            cin >> obj->rate->score;
            convert << obj->rate->score;
            System :: addData(convert.str(), rating_file);
            cout << "Enter the comment:\n"; // Prompt user to enter comment
            getline(cin, obj->rate->comment);
            System :: addData(obj->rate->comment, rating_file);
        }
        else continue;
    }
}

Request Member :: cancelRequest() {
    int houseID;
    int index = 0;
    int i = 0;
    vector <string> list_of_request = System::extractByColumnIndex(1, request_file);
    cout << "List of house you have requested: \n";
    for(Request &obj : this->allRequest) {
        cout << obj.houseId << " ";
    } 
    
    cout << "Enter the id of house that you want delete: ";
    cin >> houseID;
    for(Request &obj : this->allRequest) {
        if(obj.houseId == houseID) {
            index++;
        }
    } 

    // Delete the house in the vector
    this->allRequest.erase(this->allRequest.begin() + index);
    // Delete request in other request list:
    for(string &obj : list_of_request) {
        if(std:: stoi(obj) == houseID) {
            i++;
        }
    }
    System :: deleteRowData(i, request_file);
}
void Member:: registre() {
    House houses;

    int cities;
    cout << "Enter your user name: "; // Prompt user enter user name
    getline(cin, this->name);
    System::addData(this->name, getFilePath(member_file));
    cout << "Enter your pass word: "; // Prompt user enter password
    do {
        getline(cin , this->password);
    } while (this->password == "");
    System :: addData(this->password, getFilePath(member_file));
    cout << "Enter your full name: "; // Prompt user enter full name
    getline(cin, this->full_name);
    System:: addData(this->full_name, getFilePath(member_file));
    cout << "Enter your city: "; // Prompt user enter city
    cin >> cities;
    // Get enum input
    this->location = static_cast<city>(cities);
    //Save member data into file
    
}

void Member ::addHouseList() {
    cout << "Enter your house date: ";
    cin >> this->memberHouse->dateRange;
    System :: addData(this->memberHouse->dateRange, getFilePath(house_file));
    cout << "Enter house owner: ";
    getline(cin , this->full_name);
    System:: addData(this->full_name, getFilePath(house_file));
}

void Member :: reviewAllRequest() {
    vector <vector<string>> list_of_request = System::extractByRow(request_file); // Get data into a 2D vector
    
    cout << "Your request today is: \n";
    for(vector <string> &obj : list_of_request) {
        for(string &temp : obj) {
            cout << "temp ";
        }
    }
}
// Delete house 
void Member :: deleteHouseList() {
    int index = 0;
    
    vector <string> housid = System :: extractByColumnIndex(1, house_file);
    for(string &obj : housid) {
        if(this->memberHouse->houseID == std :: stoi(obj)) {
            index++;
        }
    }
    System :: deleteRowData(index, house_file);
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