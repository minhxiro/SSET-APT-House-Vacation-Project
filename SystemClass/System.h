
#ifndef _SYSTEM_CLASS_


#define _SYSTEM_CLASS_

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <map>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <regex>

using std:: string;
using std:: cin;
using std:: cout;
using std :: vector;
using std::regex;

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

    static void deleteRowData(int index, string dataFile);

    void updateRowAtIndex(int index, string data, string dataFile, string newDataFile);

    static void addData(string data, string dataFile);

    static vector<vector<string> > extractByRow(string dataFile);

    static vector<string> extractByColumnIndex(int index, string dataFile);

    string getCurrentDate();

    int idAutoIncrement(string dataFile);

    static vector<vector<string> >  sortAscending(int index, string dataFile);

    void sortByCategory(string type, string dataFile, int index);

    void searchByDate(int mode, string day, string month, int index, string dataFile);

    // void showMenuOption(User &client, Member &obj);

    static int sendOTP();
};
#endif

