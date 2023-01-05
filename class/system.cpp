#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <algorithm>
#include "System.h"
#include <regex>

using std::string;
using std::cout;
using std::regex;




 string System::trimString(string str) {
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
