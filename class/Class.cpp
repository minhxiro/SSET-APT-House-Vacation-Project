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
#include "./SystemClass/System.h"
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
    vector<vector<string> > allRequest = System::extractByRow(getFilePath(request_file));
    int id = this->memberHouse->houseID;
    if(allRequest.size() == 0){
        std::cerr << "There are no requests to accept" << "\n";
        

    }
    for(int i = 0; i<allRequest.size();i++){
        //if the requestID is not  equal to accepted requestID, the system will delete the request from data file
        if(std::stoi(allRequest[i][0]) != acceptID && std::stoi(allRequest[i][1]) == id){
            allRequest.erase(allRequest.begin()+i);

            System::deleteRowData(i, getFilePath(request_file));
            

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

                System::deleteRowData(i, getFilePath(request_file));
                

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
    vector <string> listHouse = System::extractByColumnIndex(1, getFilePath(house_file)); // Note
    cout << "How many houses you want to request? ";
    cin >> n;
    // Enter house ID to find house
    for(int i = 0; i < n; i++) {
        cout << "Enter the house ID: ";
        cin.ignore();
        getline(cin, houseID);
        for(string &tmp : listHouse) {
            while(houseID != tmp) {
                cout <<"Your house is not added in the list\n";
                cout << "Enter the house ID: ";
                getline(cin, houseID);
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
    vector <vector<string>> list_of_request = System::extractByRow(getFilePath(request_file)); // Get data into a 2D vector
    
    cout << "Your request today is: \n";
    for(vector <string> &obj : list_of_request) {
        for(string &temp : obj) {
            cout << temp << " ";
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

    vector<vector<string> > houseList = System::extractByRow(getFilePath(house_file));

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

    vector<vector<string> > memberList = System::extractByRow(getFilePath(member_file));

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


    vector<vector<string> > houseList = System::extractByRow(getFilePath(house_file));

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

    vector<vector<string> > requestList = System::extractByRow(getFilePath(request_file));

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



    vector<vector<string> > houseList = System::extractByRow(getFilePath(house_file));

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



    vector<vector<string> > houseList = System::extractByRow(getFilePath(house_file));

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

    vector<vector<string> > sortList = System::sortAscending(4, getFilePath(member_file));

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

void User::registre() {
    string data;
    string cityLocation;
    cout << "Enter your user name: ";
    getline(cin, this->name);
    while (!System::inputUsernameAuthentication(this->name)) {
        cout << "Username should only contain 8 to 15 character and no white spaces!!!, enter again: ";
        getline(cin, this->name);
    }
    cout << "Enter your password: ";
    getline(cin, this->password);
    while (System::inputPasswordAuthenticate(this->password) != true) {
        cout
                << "Minimum 8 and maximum 10 characters, at least one uppercase letter, one lowercase letter, one number and one special character"
                << "\n";
        cout << "Please enter again: ";
        getline(cin, this->password);
    }

    cout << "Enter your full name: ";
    getline(cin, this->full_name);
    while (System::inputNameAuthentication(this->full_name) != true) {
        cout << "Name must contain 8 to 20 characters and no digits, no special characters, and no white spaces"
             << "\n";
        cout << "Please enter again: ";
        getline(cin, this->full_name);
    }
    cout << "Enter your phone number: ";
    getline(cin, this->phonenum);
    while (System::inputPhoneAuthenticate(this->phonenum) != true) {
        cout << "phone number must have 11 numbers and start with 0" << "\n";
        cout << "Please enter again: ";
        getline(cin, this->phonenum);
    }
    cout << "\n 1.HANOI \n 2.HUE \n 3.SAIGON";
    cout << "Enter your city location: ";
    string choice;

    getline(cin, choice);
    while (true) {
        if (choice != "1" && choice != "2" && choice != "3") {
            cout << "Your input is invalid input again!: ";
            getline(cin, choice);
        } else {
            break;
        }
    }
    switch (std::stoi(choice)) {
        case 1:
            cityLocation = "HUE";
            break;
        case 2:
            cityLocation = "HANOI";
            break;
        case 3:
            cityLocation = "SAIGON";
            break;

    }
    data = "MEM" + std::to_string(System::idAutoIncrement(getFilePath(member_file))) + ";" + this->full_name + ";" +
           this->phonenum + ";" + this->name + ";" + this->password + ";" + "500" + ";" + cityLocation + ";" + "0";
    System::addData(data, getFilePath(member_file));


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
// Menu
void System :: showMenuOption() {
    int choice;
    string username;
    User client;
    Member obj;
    cout << "EEET2482/COSC2082 ASSIGNMENT\nVACATION HOUSE EXCHANGE APPLICATION\n";
    cout << "Instructors: Mr. Linh Tran & Phong Ngo\nGroup: Group Name\nsXXXXXXX, Student Name\nsXXXXXXX, Student Name\nsXXXXXXX, Student Name\n";
    cout << "Use the app as 1. Guest   2. Member   3. Admin\nEnter your choice:";
    cin >> choice;
    while(choice != 1 && choice != 2 && choice != 3) {
        cout << "Invalid Input,\nEnter your choice: ";
        cin >> choice;
    }
    if(choice == 1) {
        User::guestMenu();
    }
    else if(choice == 2) {
        int memberChoice;
        client.login();
        client.checkLogin();
        client.enterOtpCode();
        cout << "This is your menu:\n0.Exit\n1.View Information\n";
        cout << "Enter your choice: ";
        cin >> memberChoice;
        
        switch (memberChoice) {
            case 0:
                this->showMenuOption();
                break;
            case 1:
                obj.showAccountInfo();
                break;
            default:
                while(memberChoice != 0 && memberChoice != 1) {
                    cout << "You must enter invalid option: \n";
                    cout << "Enter your choice: ";
                    cin >> memberChoice;
                }
        }
    }
    else if(choice == 3) {
        Admin ad;
        int credit;
        string dateRange;
        cout << "You have logined as Admin, select your action:\n1.Show All Member\n2.View House Detail\n3.Show all house"
             <<"\n4.View Member Detail\n5.View All Request\n6.Search house by credit\n7.Search house by ID"
             << "\n8.Search House By Date Range\n9.Sort By Member Score\n";
        int adminChoice;
        cout << "Enter your option: ";
        cin >> adminChoice;
        switch(adminChoice) {
            case 1:
                ad.showAllMember();
                break;
            case 2:
                ad.viewHouseDetail(obj.memberID);
                break;
            case 3:
                ad.showAllHouse();
                break;
            case 4:
                ad.viewMemberDetail();
                break;
            case 5:
                ad.viewAllReQuest();
                break;
            case 6:
                cout << "Enter credit: ";
                cin >> credit;
                ad.searchHouseByCredit(credit);
                break;
            case 7:
                
                break;
            case 8:
                cout << "Enter date range: ";
                getline(cin, dateRange);
                ad.searchHouseByDateRange(dateRange);
                break;
            case 9:
                ad.sortByMemberScore();
                break;
            default:
                cout << "Invalid input\n";
                break;
        }
    }
    
}
void User::guestMenu() {
    cout << "You have logined as guest\n";

}