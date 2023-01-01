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
//    bool isInteger(string num);

    string trimString(string str);

    vector<int> getIndex(vector<string> lst, string K);

    static vector<string> splitStr(string str, char del);

    bool inputUsernameAuthentication(string username);

    bool inputNameAuthentication(string &name);

    bool inputPasswordAuthenticate(string &password);

    bool inputPhoneAuthenticate(string &phoneNum);

    bool inputNumAuthenticate(string &num);

    bool inputRangeAuthenticate(string &range);

    bool creditAuth(int credits);

    bool scoreAuth(int scores);

    void deleteRowData(int index, string dataFile);

    void updateRowAtIndex(int index, string data, string dataFile, string newDataFile);

    void addData(string data, string dataFile);

    static vector<vector<string> > extractByRow(string dataFile);

    vector<string> extractByColumnIndex(int index, string dataFile);

    string getCurrentDate();

    int idAutoIncrement(string dataFile);

    static vector<vector<string> >  sortAscending(int index, string dataFile);

    void sortByCategory(string type, string dataFile, int index);

    void searchByDate(int mode, string day, string month, int index, string dataFile);


};