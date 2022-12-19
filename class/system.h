//
// Created by Trung Ngo on 17/12/2022.
//

#ifndef SSET_APT_HOUSE_VACATION_PROJECT_SYSTEM_H
#define SSET_APT_HOUSE_VACATION_PROJECT_SYSTEM_H

#endif //SSET_APT_HOUSE_VACATION_PROJECT_SYSTEM_H

#include <iostream>
#include <vector>
using std::string;
using std::vector;

class System{
    friend string trimString(string str);
    friend bool inputUsernameAuthentication(string username);
    friend bool inputNameAuthentication(string &name);
    friend bool inputPasswordAuthenticate(string &password);
    friend bool inputPhoneAuthenticate(string &phoneNum);
    friend bool inputNumAuthenticate(string &num);
    friend bool inputRangeAuthenticate(string &range);
    friend bool creditAuth(int credits);
    friend bool scoreAuth(int scores);
    friend void deleteRowData(int index, string dataFile);
    friend void updateCellAtId(int id, string data, string dataFile);
    friend void updateRowAtIndex(int index, string data, string dataFile);
    friend void addData(string data, string dataFile);
    friend vector<vector<string> > extractByRow(string dataFile);
    friend vector<string> extractByColumnIndex(int index, string dataFile);
    friend string getCurrentDate();
    friend int idAutoIncrement(string dataFile);
    friend void searchByCredits();
    friend void searchById();
    friend void searchByDate();


};