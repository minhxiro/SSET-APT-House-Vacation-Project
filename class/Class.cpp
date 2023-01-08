#include "Class.h"


using std::string;
using std::cin;
using std::cout;
using std::vector;
using std::fstream;

using std::regex;


city Member::getLocation() {
    return this->location;
}

// Member

void Member::acceptReQuest(int acceptID) {
    vector<vector<string> > allRequest = System::extractByRow(requestFile);
    int id = this->memberHouse->houseID;
    if (allRequest.size() == 0) {
        std::cerr << "There are no requests to accept" << "\n";


    }
    for (int i = 0; i < allRequest.size(); i++) {
        //if the requestID is not  equal to accepted requestID, the system will delete the request from data file
        if (std::stoi(allRequest[i][0]) != acceptID && std::stoi(allRequest[i][1]) == id) {
            allRequest.erase(allRequest.begin() + i);

            System::deleteRowData(i, requestFile);


        }

    }
    cout << "Request " << acceptID << " have been accepted" << "\n";

}

void Member::declineRequest(int declineID) {
    vector<vector<string> > allRequest = System::extractByRow(requestFile);
    int id = this->memberHouse->houseID;
    if (allRequest.size() == 1) {
        std::cerr << "The request have been accepted, can not be declined" << "\n";


    } else {
        for (int i = 0; i < allRequest.size(); i++) {
            if (std::stoi(allRequest[i][0]) == declineID && std::stoi(allRequest[i][1]) == id) {
                allRequest.erase(allRequest.begin() + i);

                System::deleteRowData(i, requestFile);


            }
        }
    }

}

// void Member::showAllHouse() {
//     cout << "List of available houses is being showed below:\n";
//     vector<string> listofHouse;
//     listofHouse = System::extractByColumnIndex(0, houseFile);

//     cout << "House name: \n";
//     for (string &obj: listofHouse) {
//         cout << obj << " ";
//     }
// }


void Member::requestHouse() {
    int n;
    string houseID;
    string data;
    // Get house ID in a vector

    vector<string> listHouse = System::extractByColumnIndex(0, houseFile); // Note

    cout << "How many houses you want to request? ";
    cin >> n;
    // Enter house ID to find house
    for (int i = 0; i < n; i++) {
        cout << "Enter the house ID: ";
        cin.ignore();
        getline(cin, houseID);

        for (string &tmp: listHouse) {
            // while (houseID != tmp) {
            //     cout << "Your house is not added in the list\n";

            // }
            if (houseID == tmp) {
                cout << "Successful to request house";
                //Note is here
                // data = "RE" + std::to_string(System::idAutoIncrement(memberFile))+ ";" + "Mem" + std::to_string(this->memberID)
                // +";" + "HOU" + std::to_string(this->memberHouse->houseID) + ";" + this->memberHouse->currentDate + ";" + this->memberHouse->stat;
                Request obj;
                obj.houseId = std::stoi(houseID);
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
//             System :: addData(convert.str(), ratingFile;
//             cout << "Enter the comment:\n"; // Prompt user to enter comment
//             getline(cin, obj->rate->comment);
//             System :: addData(obj->rate->comment, ratingFile;
//         }
//         else continue;
//     }
// }

void Member::cancelRequest() {
    int houseID;
    int index = 0;
    int i = 0;
    vector<string> list_of_request = System::extractByColumnIndex(0, requestFile);
    cout << "List of house you have requested: \n";
    for (Request &obj: this->allRequest) {
        cout << obj.houseId << " ";
    }

    cout << "Enter the id of house that you want delete: ";
    cin >> houseID;
    for (Request &obj: this->allRequest) {
        if (obj.houseId == houseID) {
            index++;
        }
    }

    // Delete the house in the vector
    this->allRequest.erase(this->allRequest.begin() + index);
    // Delete request in other request list:
    for (string &obj: list_of_request) {
        if (std::stoi(obj) == houseID) {
            i++;
        }
    }
    System::deleteRowData(i, requestFile);
}


void Member::addHouseList() {
    cout << "Enter your house date: ";
    cin >> this->memberHouse->dateRange;
    System::addData(this->memberHouse->dateRange, houseFile);
    cout << "Enter house owner: ";
    getline(cin, this->fullName);
    System::addData(this->fullName, houseFile);
}


void Member :: reviewAllRequest() {
    vector <vector<string>> list_of_request = System::extractByRow(requestFile); // Get data into a 2D vector
    
    cout << "Your request today is: \n";
    for(vector <string> &obj : list_of_request) {
        for(string &temp : obj) {
            cout << temp << " ";

        }
    }
}

// Delete house
void Member::deleteHouseList() {
    int index = 0;

    vector<string> housid = System::extractByColumnIndex(0, houseFile);
    for (string &obj: housid) {
        if (this->memberHouse->houseID == std::stoi(obj)) {
            index++;
        }
    }
    System::deleteRowData(index, houseFile);
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
    vector<vector<string> > memberList = System::extractByRow(memberFile);
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

// void showAllHouse() {
//     cout << "All house of the system: " << "\n";
//     cout
//             << std::left
//             << std::setw(8)
//             << "HouseID"
//             << std::left
//             << std::setw(15)
//             << "OwnerID"
//             << std::left
//             << std::setw(15)
//             << "Location"
//             << std::left
//             << std::setw(15)
//             << "Status"
//             << "\n";

//     vector<vector<string> > houseList = System::extractByRow(houseFile);

//     for (int i = 0; i < houseList.size(); i++) {
//         cout
//                 << std::left
//                 << std::setw(8)
//                 << houseList[i][0]
//                 << std::left
//                 << std::setw(15)
//                 << houseList[i][1]
//                 << std::left
//                 << std::setw(15)
//                 << houseList[i][6]
//                 << std::left
//                 << std::setw(15)
//                 << houseList[i][7]
//                 << "\n";
//     }
// }

void Admin::viewMemberDetail() {

    vector<vector<string> > memberList = System::extractByRow(memberFile);

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

void User :: viewHouseDetail(int id) {
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


    vector<vector<string> > houseList = System::extractByRow(houseFile);

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
        } else {
            cout << "\nThere is no house with this ID" << "\n";
        }
    }
}

void Admin::viewAllReQuest() {

    vector<vector<string> > requestList = System::extractByRow(requestFile);

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


    vector<vector<string> > houseList = System::extractByRow(houseFile);

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


    vector<vector<string> > houseList = System::extractByRow(houseFile);

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

    vector<vector<string> > sortList = System::sortAscending(4, memberFile);

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

bool User::login() {
    cout << "Enter the user name: ";
    cin >> this->name;
    cout << "Enter password: ";
    cin >> this->password;

    bool check = System::verifyLogin(this->name, this->password);
    bool secureCode = enterOtpCode();
    if(check && secureCode) {
        return true;
    }
    else if(!check && secureCode) {
        
        return false;
    }
    return true;
}



void User::showAccountInfo(int j) {
    vector <string> tmp;
     string *informationData = new string[1000];
    fstream file;
    file.open(memberFile, std::ios::in);
    if (!file) {
        std::cerr << "Fail to open file\n";
    }
    int index = 0;
    while (!file.eof()) {
        file >> informationData[index];
        index++;
    }

    file.close();
    for(int i = 0; i < index;i++) {
        if(i == j) {
            tmp = System::splitStr(informationData[i], ';');
        }
    }
    this->fullName = tmp[1];
    this->phonenum = tmp[2];
    this->memberID = std::stoi(tmp[0]);
    this->credit = std::stoi(tmp[5]);
    this->ratingScore = std::stoi(tmp[7]);
    cout << "Your full name is: " << this->fullName << "\n";
    cout << "Your phone number is: " << this->phonenum << "\n";
    cout << "Your ID is: " << this->memberID << "\n";
    cout << "Your credit is: " << this->credit << "\n";
    cout << "Your rating score is: " << this->ratingScore << "\n";
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
    getline(cin, this->fullName);
    while (System::inputNameAuthentication(this->fullName) != true) {
        cout << "Name must contain 8 to 20 characters and no digits, no special characters, and no white spaces"
             << "\n";
        cout << "Please enter again: ";
        getline(cin, this->fullName);
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

    data = "MEM" + std::to_string(System::idAutoIncrement(memberFile)) + ";" + this->fullName + ";" +
           this->phonenum + ";" + this->name + ";" + this->password + ";" + "500" + ";" + cityLocation + ";" + "0";
    System::addData(data, memberFile);



}


bool User::enterOtpCode() {
    // Get the otp from system:
    int code;
    this->otp = System::sendOTP();
    cout << "Your OTP Code is: " << this->otp;
    cout << "\nPlease enter the code sent to you to verify if you are robot or not:\n";
    cin >> code;
    // Check OTP code
    // while (code != this->otp) {
    //     this->otp = System::sendOTP();
    //     cout << "Your OTP Code is: " << this->otp;
    //     cout << "\nPlease enter the code sent to you to verify if you are robot or not: \n";
    //     cin >> code;
    // }
    if (code == this->otp) {
        return true;
    }
    else return false;
}
bool User::isAdmin() {
    bool check = System::verifyAdmin(this->name, this->password);
    if(check) {
        return true;
    }
    else return false;
    return true;
}
void User::showAllHouse() {
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

    vector<vector<string> > houseList = System::extractByRow(houseFile);

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

// Menu
void User::showMenuOption() {
    int choice;
    string username;
    
    cout << "-----------Main Menu------------------------\n\n\n";
    
    cout << "Use the app as 1. Guest   2. Member   3. Admin\nEnter your choice:\n";
    cin >> choice;
    while(choice != 1 && choice != 2 && choice != 3) {
        cout << "Invalid Input,\nEnter your choice: \n";
        cin >> choice;
    }
    if(choice == 1) {
        guestMenu();
    }
    else if(choice == 2) {
        memberMenu();
    }
    else if(choice == 3) {
        adminMenu();
    }
    
}
void User::guestMenu() {
    int userSelection;
    cout << "You have logined as guest\n\n\n";
    cout << "---------Guest Menu----------\n\n";
    cout << "Choose the option:\n1.Register\n2.View all house\n3.Exit to main menu\n";
    cin >> userSelection;
    switch(userSelection) {
        case 1:
            registre();
            
            break;
        case 2:
            showAllHouse();
            
            break;
        case 3:
            showMenuOption();
    }
}

void User:: memberMenu() {
    // Member mem;
    cout << "You have chosen to login as member, please Input your account: \n\n";
    cout << "--------Member Login------------\n\n\n\n\n";
    
    if(login()) {
        cout << "\nYou have login as Member\n"; // Add current Member here
        
    }
    else {
        cout << "Wrong user name or password\n";
        showMenuOption();
    }
}

void User:: adminMenu() {
    cout << "You have chosen to login as admin, please Input your account: \n\n";
    cout << "--------Admin Login------------\n\n\n\n\n";
    login();
    
    if(isAdmin()) {
        Admin ad;
        int userSelection;
        cout << "\nYou have logined as Admin\n\n";
        cout << "Please choose your option:\n\n\n";
        cout << "1.Show All Member\n2.View House Detail\n3.Show All House\n4.View Member Detail\n5.View All Request"
            <<"\n6.Search House By Credit\n7.Search House By ID\n8.Search House By Date Range\n9.Sort By Member Score\n10.Exit to main menu\n";
        cout << "Enter your option: ";
        cin >> userSelection;
        cout << "\n";
        switch(userSelection) {
            case 1:
                ad.showAllMember();
                break;
            case 2:
                int id;
                cout <<"\nEnter House ID: ";
                cin >> id;
                viewHouseDetail(id);
                break;
                
            case 3:
                showAllHouse();
                break;
            case 4:
                ad.viewMemberDetail();
                break;
            case 5:
                ad.viewAllReQuest();
                break;
            case 6:
                int credit;
                cout << "\nEnter your expected credit: ";
                cin >> credit;
                ad.searchHouseByCredit(credit);
                break;
            case 7:
                // ad.searchHouseById();
                break;
            case 8:
                {string duration;
                cout << "\nEnter the house date range: ";
                getline(cin, duration);
                ad.searchHouseByDateRange(duration);
                break;
                }
            case 9:
                ad.sortByMemberScore();
                break;
            case 10:
                showMenuOption();
                break;
        }
    }
    
}
