
#include "System.h"

using std::string;
using std::cin;
using std::cout;
using std::vector;
using std::regex;

// System

//bool System::isInteger(string num) {
//    for (char ch: num) {
//        if (ch == '.') {
//            return false;
//        }
//    }
//    return true;
//}




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

bool System::isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    } else {
        return false;
    }
}

int System::overloadDays(int day, int month, int year) {
    int overload = day;

    switch (month - 1) {
        case 11:
            overload += 30;
        case 10:
            overload += 31;
        case 9:
            overload += 30;
        case 8:
            overload += 31;
        case 7:
            overload += 31;
        case 6:
            overload += 30;
        case 5:
            overload += 31;
        case 4:
            overload += 30;
        case 3:
            overload += 31;
        case 2:
            overload += 28;
        case 1:
            overload += 31;
    }

    if (System::isLeapYear(year) && month > 2)
        overload += 1;

    return overload;
}

// Given a year and days elapsed in it, finds
// date by storing results in d and m.
void System::getDatesAfter(int overload, int year, int *day, int *month) {
    int monthLst[13] = {0, 31, 28, 31, 30, 31, 30,
                        31, 31, 30, 31, 30, 31};

    if (System::isLeapYear(year))
        monthLst[2] = 29;

    int i;
    for (i = 1; i <= 12; i++) {
        if (overload <= monthLst[i])
            break;
        overload = overload - monthLst[i];
    }

    *day = overload;
    *month = i;
}

// Add x days to the given date.
string System::addDays(int period) {
    int targetDay, targetMonth, targetYear;
    targetDay = std::stoi(System::splitStr(System::getCurrentDate(), '/')[0]);
    targetMonth = std::stoi(System::splitStr(System::getCurrentDate(), '/')[1]);
    targetYear = std::stoi(System::splitStr(System::getCurrentDate(), '/')[2]);

    int overload = System::overloadDays(targetDay, targetMonth, targetYear);
    int remainDays = System::isLeapYear(targetYear) ? (366 - overload) : (365 - overload);


    int yearTemp, overloadTemp;
    if (period <= remainDays) {
        yearTemp = targetYear;
        overloadTemp = overload + period;
    } else {

        period -= remainDays;
        yearTemp = targetYear + 1;
        int yearTempDays = System::isLeapYear(yearTemp) ? 366 : 365;
        while (period >= yearTempDays) {
            period -= yearTempDays;
            yearTemp++;
            yearTempDays = System::isLeapYear(yearTemp) ? 366 : 365;
        }
        overloadTemp = period;
    }

    int monthTemp, dayTemp;
    System::getDatesAfter(overloadTemp, yearTemp, &dayTemp, &monthTemp);

    string finalDate;
    finalDate = std::to_string(dayTemp) + "/" + std::to_string(monthTemp) + "/" + std::to_string(yearTemp);
    return finalDate;
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
    regex reg("^[a-zA-Z]{8,20}$");
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

void System::addData(string data, string dataFile) {
    std::fstream file;
    file.open(dataFile, std::ios::app);
    if (file.fail()) {
        cout << "Cannot reach the database \n";
    } else {
        file << "\n"+data;
        cout << "Your information has been successfully added! \n";
        file.close();
    }
}

vector<string> System::extractByRowId(int index, string dataFile){
    std::fstream file;
    string dataLine;
    std::vector<string> dataRowsArray;
    int count = 0;
    file.open(dataFile, std::ios::in);
    if (file.fail()) {
        cout << "Cannot reach the database \n";
    } else {
        while (!file.eof()) {
            std::stringstream ss;
            std::getline(file, dataLine);
            if (count == index){
                dataRowsArray = splitStr(dataLine, ';');
                break;
            }
            count ++;
        }
        file.close();
    }
    return dataRowsArray;
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
            std::getline(file, dataLine);
            dataRowsArray = splitStr(dataLine, ';');
            dataTable.push_back(dataRowsArray);
        }
        file.close();
    }
    return dataTable;
}

vector<string> System::extractByRowId(int index, string dataFile) {
    std::fstream file;
    string dataLine;
    std::vector<string> dataRowsArray;
    int count = 0;
    file.open(dataFile, std::ios::in);
    if (file.fail()) {
        cout << "Cannot reach the database \n";
    } else {
        while (!file.eof()) {
            std::stringstream ss;
            std::getline(file, dataLine);
            if (count == index) {
                dataRowsArray = splitStr(dataLine, ';');
                break;
            }
            count++;
        }
        file.close();
    }
    return dataRowsArray;
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
                if ((count) == 1) {
                    writeFile << tempData;
                } else {
                    writeFile << "\n"+tempData;
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
            vector<string> dataString;
            if (std::stof(data[i][index]) > std::stof(data[j][index])) {
                std::iter_swap(data.begin() + i, data.begin() + j);
            }
        }
    }
    //return sorted vector
    return data;
}


//This function require the index of column that need to be compare to the type, a type (ex: Hue, Sg, Hn) and then cout all the row of the same type 
vector<vector<string> > System::sortByCategory(string type, string dataFile, int index) {
    std::fstream file;
    vector<vector<string> > data;
    vector<vector<string> > filteredData;
    int count = 0;
    type = trimString(type);
    transform(type.begin(), type.end(), type.begin(), ::tolower);

    data = extractByRow(dataFile);
    for (vector<string> dataStr: data) {
        if (dataStr[index] == type) {
            count++;
            filteredData.push_back(dataStr);
        }
    }
    if (count == 0) {
        cout << "Your input cannot be found in the database \n";
    }
    return filteredData;

}

vector<vector<string> > System::searchByDate(int mode, string day, string month, int index, string dataFile) {
    //mode 1: search by day of the request (searchByDate(1,<the day>,0) let month = 0)
    //mode 2: search by month of the request (searchByDate(2,0,<the month>) let day = 0)
    vector<vector<string> > data = extractByRow(dataFile);
    vector<int> indexLst;
    vector<vector<string> > filteredDataDays;
    vector<vector<string> > filteredDataMonths;

    if (mode == 1) {
        vector<string> days;
        //get the date column
        for (string date: extractByColumnIndex(index, dataFile)) {
            //split the date by / and get the day add to the day vector
            days.push_back(splitStr(date, '/')[0]);
        }
        indexLst = getIndex(days, day);
        if (indexLst.size() == 0) {
            cout << "Your input day cannot be found in the database \n";
        } else {
            for (int i: indexLst) {
                filteredDataDays.push_back(data[i]);
            }
        }
        return filteredDataDays;
    }
    if (mode == 2) {
        vector<string> months;
        //get the date column
        for (string date: extractByColumnIndex(index, dataFile)) {
            //split the date by / and get the day add to the day vector
            months.push_back(splitStr(date, '/')[1]);
        }
        indexLst = getIndex(months, month);
        if (indexLst.size() == 0) {
            cout << "Your input month cannot be found in the database \n";
        } else {

            for (int i: indexLst) {
                filteredDataMonths.push_back(data[i]);
            }
        }
        return filteredDataMonths;
    }
}

bool System::verifyLogin(string userName, string password) {
    vector<string> userNames;
    vector<string> passwords;
    vector<string> userInfo;
    string userInfoData;

    userNames = System::extractByColumnIndex(3, memberFile);
    passwords = System::extractByColumnIndex(4, memberFile);

    for (int i = 0; i < userNames.size(); i++) {
        if (userName == userNames[i]) {
            if (password == passwords[i]) {
                userInfo = System::extractByRowId(i, memberFile);

                for(int j = 0; j < userInfo.size(); j++){
                    if(j == 0){
                        userInfoData += userInfo[j];
                    }else{

                        userInfoData += ";" + userInfo[j];
                    }
                }
                System::addData(userInfoData, currentUserFile);
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}


bool System:: verifyAdmin(string userName, string password) {
    vector<string> userNames;
    vector<string> passwords;

    userNames = System::extractByColumnIndex(0, adminFile);
    passwords = System::extractByColumnIndex(1, adminFile);

    for (int i = 0; i < userNames.size(); i++) {
        if (userName == userNames[i]) {
            if (password == passwords[i]) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}


bool System::scoreAuth(int score, string houseId) {
    vector<vector<string> > houseData = System::extractByRow(houseFile);
    for (vector<string> house: houseData) {
        if (house[0] == houseId) {
            if (score < std::stoi(house[6])) {
                return false;
            } else {
                return true;
            }
        }
    }
    return false;
}

bool System::creditAuth(int credit, string houseId) {
    vector<vector<string> > houseData = System::extractByRow(houseFile);
    for (vector<string> house: houseData) {
        if (house[0] == houseId) {
            if (credit < std::stoi(house[5])) {
                return false;
            } else {
                return true;
            }
        }
    }
    return false;

}


int System::sendOTP() {
    srand(time(NULL)); // User ran to get random number as OTP code
    int res = rand();
    return res;
}




