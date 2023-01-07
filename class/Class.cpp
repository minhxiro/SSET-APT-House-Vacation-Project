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
#include "Class.h"
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





// Member

void Member::acceptReQuest(int acceptID) {
    vector<vector<string> > allRequest = System::extractByRow(request_file);
    int id = this->memberHouse->houseID;
    if(allRequest.size() == 0){
        std::cerr << "There are no requests to accept" << "\n";
        
    }
    for(int i = 0; i<allRequest.size();i++){
        //if the requestID is not  equal to accepted requestID, the system will delete the request from data file
        if(std::stoi(allRequest[i][0]) != acceptID && std::stoi(allRequest[i][1]) == id){
            allRequest.erase(allRequest.begin()+i);
            System::deleteRowData(i,request_file);
            
        }

    }
    cout << "Request " << acceptID << " have been accepted" << "\n";

}
void Member::declineRequest(int declineID) {
    vector<vector<string> > allRequest = System::extractByRow(request_file);
    int id = this->memberHouse->houseID;
    if(allRequest.size() == 1){
        std::cerr << "The request have been accepted, can not be declined" << "\n";
        
    }
    else {
        for(int i = 0;i<allRequest.size();i++){
            if(std::stoi(allRequest[i][0]) == declineID && std::stoi(allRequest[i][1]) == id){
                allRequest.erase(allRequest.begin()+i);
                System::deleteRowData(i,request_file);
                
            }
        }
    }

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
void Member ::requestHouse() {
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

// void Member ::rateHouse() {
//     std :: stringstream convert;
//     int houseID;
//     cout << "Enter ID of the house you want to rate: ";
//     cin >> houseID;
//     for(House *obj : this->houseList) {
//         if(houseID == obj->houseID) {
//             cout << "Enter the score: "; // Prompt user to enter the score
//             cin >> obj->rate->score;
//             convert << obj->rate->score;
//             System :: addData(convert.str(), rating_file);
//             cout << "Enter the comment:\n"; // Prompt user to enter comment
//             getline(cin, obj->rate->comment);
//             System :: addData(obj->rate->comment, rating_file);
//         }
//         else continue;
//     }
// }

void Member :: cancelRequest() {
    int houseID;
    int index = 0;
    int i = 0;
    vector <string> list_of_request = System::extractByColumnIndex(0, request_file);
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
    
    vector <string> housid = System :: extractByColumnIndex(0, house_file);
    for(string &obj : housid) {
        if(this->memberHouse->houseID == std :: stoi(obj)) {
            index++;
        }
    }
    System :: deleteRowData(index, house_file);
}

// House

// Admin
void Admin::showAllMember() {
    cout << "All the member of the system: " << "\n";
    cout
            << std::left
            << std::setw(8)
            << "MemberID"
            << std::left
            << std::setw(15)
            << "Full Name"
            << "\n";
    vector<vector<string> > memberList = System::extractByRow(getFilePath(member_file));
    for (int i = 0; i < memberList.size(); i++) {
        cout
                << std::left
                << std::setw(8)
                << memberList[i][0]
                << std::left
                << std::setw(15)
                << memberList[i][1]
                << "\n";
    }
}

void Admin::showAllHouse() {
    cout << "All house of the system: " << "\n";
    cout
            << std::left
            << std::setw(8)
            << "HouseID"
            << std::left
            << std::setw(15)
            << "OwnerID"
            << std::left
            << std::setw(15)
            << "Location"
            << std::left
            << std::setw(15)
            << "Status"
            << "\n";
    vector<vector<string> > houseList = System::extractByRow(house_file);
    for (int i = 0; i < houseList.size(); i++) {
        cout
                << std::left
                << std::setw(8)
                << houseList[i][0]
                << std::left
                << std::setw(15)
                << houseList[i][1]
                << std::left
                << std::setw(15)
                << houseList[i][6]
                << std::left
                << std::setw(15)
                << houseList[i][7]
                << "\n";
    }
}

void Admin::viewMemberDetail() {
    vector<vector<string> > memberList = System::extractByRow(member_file);
    cout << "\nAll members: " << "\n";
    cout
            << std::left
            << std::setw(15)
            << "Full Name"
            << std::left
            << std::setw(15)
            << "PhoneNum"
            << std::left
            << std::setw(8)
            << "MemberID"
            << std::left
            << std::setw(5)
            << "Credit"
            << std::left
            << std::setw(10)
            << "Rating Score"
            << std::endl;
    for (int i = 0; i < memberList.size(); i++) {
        cout
                << std::left
                << std::setw(15)
                << memberList[i][0]
                << std::left
                << std::setw(15)
                << memberList[i][1]
                << std::left
                << std::setw(8)
                << memberList[i][2]
                << std::left
                << std::setw(5)
                << memberList[i][3]
                << std::left
                << std::setw(10)
                << memberList[i][4]
                << std::endl;
    }
}

void Admin::viewHouseDetail(int id) {
    cout << "\nHouse with this ID will be displayed " << "\n";
    cout
            << std::left
            << std::setw(10)
            << "HouseID"
            << std::left
            << std::setw(10)
            << "OwnerID"
            << std::left
            << std::setw(20)
            << "CurrentDate"
            << std::left
            << std::setw(20)
            << "DateRange"
            << std::left
            << std::setw(10)
            << "Credit"
            << std::left
            << std::setw(10)
            << "minScore"
            << std::left
            << std::setw(15)
            << "Location"
            << std::left
            << std::setw(15)
            << "Status"
            << "\n";

    vector<vector<string> > houseList = System::extractByRow(house_file);
    for (int i = 0; i < houseList.size(); i++) {
        if (id == std::stoi(houseList[i][0])) {
            cout
                    << std::left
                    << std::setw(10)
                    << houseList[i][0]
                    << std::left
                    << std::setw(10)
                    << houseList[i][1]
                    << std::left
                    << std::setw(20)
                    << houseList[i][2]
                    << std::left
                    << std::setw(20)
                    << houseList[i][3]
                    << std::left
                    << std::setw(10)
                    << houseList[i][4]
                    << std::left
                    << std::setw(10)
                    << houseList[i][5]
                    << std::left
                    << std::setw(15)
                    << houseList[i][6]
                    << std::left
                    << std::setw(15)
                    << houseList[i][7]
                    << "\n";
        }
    }
}

void Admin::viewAllReQuest() {
    vector<vector<string> > requestList = System::extractByRow(request_file);
    cout << "\nAll requests will be displayed here: " << "\n";
    cout
            << std::left
            << std::setw(10)
            << "RequestID"
            << std::left
            << std::setw(10)
            << "houseID"
            << std::left
            << std::setw(10)
            << "TenatID"
            << std::left
            << std::setw(10)
            << "status"
            << "\n";
    for (int i = 0; i < requestList.size(); i++) {
        cout
                << std::left
                << std::setw(10)
                << requestList[i][0]
                << std::left
                << std::setw(10)
                << requestList[i][1]
                << std::left
                << std::setw(10)
                << requestList[i][2]
                << std::left
                << std::setw(10)
                << requestList[i][3]
                << "\n";
    }

}

void Admin::searchHouseByDateRange(string dateRange) {
    cout << "\nAll houses with this date range will be displayed: " << "\n";
    cout
            << std::left
            << std::setw(10)
            << "HouseID"
            << std::left
            << std::setw(10)
            << "OwnerID"
            << std::left
            << std::setw(20)
            << "CurrentDate"
            << std::left
            << std::setw(20)
            << "DateRange"
            << std::left
            << std::setw(10)
            << "Credit"
            << std::left
            << std::setw(10)
            << "minScore"
            << std::left
            << std::setw(15)
            << "Location"
            << std::left
            << std::setw(15)
            << "Status"
            << "\n";

    vector<vector<string> > houseList = System::extractByRow(house_file);
    for (int i = 0; i < houseList.size(); i++) {
        if (dateRange == houseList[i][3]) {
            cout
                    << std::left
                    << std::setw(10)
                    << houseList[i][0]
                    << std::left
                    << std::setw(10)
                    << houseList[i][1]
                    << std::left
                    << std::setw(20)
                    << houseList[i][2]
                    << std::left
                    << std::setw(20)
                    << houseList[i][3]
                    << std::left
                    << std::setw(10)
                    << houseList[i][4]
                    << std::left
                    << std::setw(10)
                    << houseList[i][5]
                    << std::left
                    << std::setw(15)
                    << houseList[i][6]
                    << std::left
                    << std::setw(15)
                    << houseList[i][7]
                    << "\n";
        }
    }

}

void Admin::searchHouseByCredit(int credit) {
    cout << "\nAll houses with this credit will be displayed: " << "\n";
    cout
            << std::left
            << std::setw(10)
            << "HouseID"
            << std::left
            << std::setw(10)
            << "OwnerID"
            << std::left
            << std::setw(20)
            << "CurrentDate"
            << std::left
            << std::setw(20)
            << "DateRange"
            << std::left
            << std::setw(10)
            << "Credit"
            << std::left
            << std::setw(10)
            << "minScore"
            << std::left
            << std::setw(15)
            << "Location"
            << std::left
            << std::setw(15)
            << "Status"
            << "\n";

    vector<vector<string> > houseList = System::extractByRow(house_file);
    for (int i = 0; i < houseList.size(); i++) {
        if (credit == std::stoi(houseList[i][4])) {
            cout
                    << std::left
                    << std::setw(10)
                    << houseList[i][0]
                    << std::left
                    << std::setw(10)
                    << houseList[i][1]
                    << std::left
                    << std::setw(20)
                    << houseList[i][2]
                    << std::left
                    << std::setw(20)
                    << houseList[i][3]
                    << std::left
                    << std::setw(10)
                    << houseList[i][4]
                    << std::left
                    << std::setw(10)
                    << houseList[i][5]
                    << std::left
                    << std::setw(15)
                    << houseList[i][6]
                    << std::left
                    << std::setw(15)
                    << houseList[i][7]
                    << "\n";
        }
    }
}

void Admin::sortByMemberScore() {
    vector<vector<string> > sortList = System::sortAscending(4, member_file);
    cout << "\nAll members after sorted will be displayed: " << "\n";
    cout
            << std::left
            << std::setw(15)
            << "Full Name"
            << std::left
            << std::setw(15)
            << "PhoneNum"
            << std::left
            << std::setw(8)
            << "MemberID"
            << std::left
            << std::setw(5)
            << "Credit"
            << std::left
            << std::setw(10)
            << "Rating Score"
            << std::endl;
    for (int i = 0; i < sortList.size(); i++) {
        cout
                << std::left
                << std::setw(15)
                << sortList[i][0]
                << std::left
                << std::setw(15)
                << sortList[i][1]
                << std::left
                << std::setw(8)
                << sortList[i][2]
                << std::left
                << std::setw(5)
                << sortList[i][3]
                << std::left
                << std::setw(10)
                << sortList[i][4]
                << std::endl;
    }

}
//Request

// HouseList

//Rating

// Rating Tenant





// User

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

void User::enterOtpCode() {
    // Get the otp from system:
    int code;
    this->otp = System::sendOTP();
    cout << "Your OTP Code is: " << this->otp;
    cout << "\nPlease enter the code sent to you to verify if you are robot or not: ";
    cin >> code;
    // Check OTP code
    while(code != this->otp) {
         this->otp = System::sendOTP();
        cout << "Your OTP Code is: " << this->otp;
        cout << "\nPlease enter the code sent to you to verify if you are robot or not: ";
        cin >> code;
    }
    if(code == this->otp) {
        cout << "\nYou have logined as Member: \n";
    }
    
}
