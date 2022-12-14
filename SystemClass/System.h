
#ifndef _SYSTEM_CLASS_


#define _SYSTEM_CLASS_

#define cookieFile "data/currentUser.dat"
#define memberFile "data/members.dat"
#define houseFile "data/house.dat"
#define ratingFile "data/rating.dat"
#define ratingTenantFile "data/ratingTenant.dat"
#define requestFile "data/request.dat"
#define adminFile "data/admin.dat"
#define currentUserFile "data/currentUser.dat"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <map>
#include <cstdlib>
#include <ctime>
#include <regex>


using std:: string;
using std:: cin;
using std:: cout;
using std :: vector;
using std::regex;

class System {
public:
//    bool isInteger(string num);
    static string trimString(string str);

    static bool isLeapYear(int year);

    static int overloadDays(int day, int month, int year);

    static void getDatesAfter(int overload, int year, int *day, int *month);

    static string addDays(int period);

    static vector<int> getIndex(vector<string> lst, string K);

    static vector<string> splitStr(string str, char del);

    static bool inputUsernameAuthentication(string username);

    static bool inputNameAuthentication(string &name);

    static bool inputPasswordAuthenticate(string &password);

    static bool inputPhoneAuthenticate(string &phoneNum);

    static bool inputNumAuthenticate(string &num);

    bool inputRangeAuthenticate(string &range);

    static void deleteRowData(int index, string dataFile);

    void updateRowAtIndex(int index, string data, string dataFile, string newDataFile);

    static void addData(string data, string dataFile);

    static vector<vector<string> > extractByRow(string dataFile);

    static vector<string> extractByRowId(int index, string dataFile);


    static vector<string> extractByColumnIndex(int index, string dataFile);

    static string getCurrentDate();

    static int idAutoIncrement(string dataFile);

    static vector<vector<string> >  sortAscending(int index, string dataFile);

    static vector<vector<string> > sortByCategory(string type, string dataFile, int index);

    static vector<vector<string> > searchByDate(int mode, string day, string month, int index, string dataFile);

    static bool verifyLogin(string username, string password);

    static bool scoreAuth(int score, string houseId);

    static bool creditAuth(int score, string houseId);

    static string getDateAfter(int period);

    static bool verifyLogin(string username, string password);

    static bool verifyAdmin(string username, string password);
     static bool scoreAuth(int score, string houseId);

    static bool creditAuth(int score, string houseId);

    static string getDateAfter(int period);
    static int sendOTP();
};
#endif

