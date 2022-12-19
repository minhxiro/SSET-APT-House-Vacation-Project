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

class System {
public:
    string trimString(string str);

    bool inputUsernameAuthentication(string username);

    bool inputNameAuthentication(string &name);

    bool inputPasswordAuthenticate(string &password);

    bool inputPhoneAuthenticate(string &phoneNum);

    bool inputNumAuthenticate(string &num);

    bool inputRangeAuthenticate(string &range);

    bool creditAuth(int credits);

    bool scoreAuth(int scores);

    void deleteRowData(int index, string dataFile, string newDataFile);

    void updateRowAtIndex(int index, string data, string dataFile, string newDataFile);

    void addData(string data, string dataFile);

    vector<vector<string> > extractByRow(string dataFile);

    vector<string> extractByColumnIndex(int index, string dataFile);

    string getCurrentDate();

    int idAutoIncrement(string dataFile);

    void sortByCreditsPerDay();

    void sortByRegion();

    void sortByRequestStatus();

    void searchByCredits();

    void searchById();

    void searchByDate();


};