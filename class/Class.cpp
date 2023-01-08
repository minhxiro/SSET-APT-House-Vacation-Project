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

void Member::acceptReQuest(string acceptID) {
    vector<vector<string> > allRequest = System::extractByRow(requestFile);

    int count = 0; //count variable to count the request of a particular house
    for (vector<string> &i: allRequest) {
        //count the appearance
        if (i[2] == this->memberHouse->houseID) {
            count++;
        }
    }
    //if count = 0 then there is no request to that house
    if (count == 0) {
        cout << "\nThere are no requests to your house!!\n";
    } else {
        for (vector<string> &i: allRequest) {
            if (i[0] == acceptID) {
                i[4] = "Accepted";
            } else {
                i[4] = "Declined";
            }
        }
    }
}

void Member::declineRequest(string declineID) {
    vector<vector<string> > allRequest = System::extractByRow(requestFile);
    int count = 0; //count variable to count the request of a particular house
    for (vector<string> &i: allRequest) {
        //count the appearance
        if (i[2] == this->memberHouse->houseID) {
            count++;
        }
    }
    //if count = 0 then there is no request to that house
    if (count == 0) {
        cout << "\nThere are no requests to your house!!\n";
    } else {
        for (vector<string> &i: allRequest) {
            if (i[0] == declineID) {
                i[4] = "Declined";
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
    string houseID;
    string data;
    
    // Get house ID in a vector
    cout << "Enter the house ID: ";
    cin >>houseID;
    vector<vector<string> > listHouse = System::extractByRow(houseFile); // Note
    // data = "RE" + std::to_string(System::idAutoIncrement(memberFile))+ ";" + "Mem" + std::to_string(this->memberID)
                // +";" + "HOU" + std::to_string(this->memberHouse->houseID) + ";" + this->memberHouse->currentDate + ";" + this->memberHouse->stat;
    for(int i = 0; i < listHouse.size();i++) {
        if(houseID == listHouse[i][0]) {
            cout<< "Requested\n";
            data = "RE" + std::to_string(System::idAutoIncrement(requestFile))+ ";" + this->memberID
                +";" + houseID + ";" + listHouse[i][2] + ";" + "PENDING";
            System::addData(data, requestFile);
        }
    }
}


void Member::cancelRequest() {
    string houseID;
    int index;
    cout << "Enter ID of the house you want to delete: ";
    cin >> houseID;
    vector <vector<string> > houseRequested = System::extractByRow(requestFile);
    for(int i = 0; i < houseRequested.size(); i++) {
        if(houseID == houseRequested[i][2] && this->memberID == houseRequested[i][1]) {
            index = i;
        }
        
    }
    System:: deleteRowData(index, requestFile);
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
// void Member::deleteHouseList() {
//     int index = 0;

//     vector<string> housid = System::extractByColumnIndex(0, houseFile);
//     for (string &obj: housid) {
//         if (this->memberHouse->houseID == std::stoi(obj)) {
//             index++;
//         }
//     }
//     System::deleteRowData(index, houseFile);
// }


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



void User::showAccountInfo() {
    cout << "All the member of the system: " << "\n";
    cout
            << std::left
            << std::setw(8)
            << "MemberID"
            << std::left
            << std::setw(15)
            << "Full Name"
            << std::left
            << std::setw(21)
            <<"Phone number"
            << "\n";
    vector<vector<string> > memberList = System::extractByRow(currentUserFile);
   
        cout
                << std::left
                << std::setw(8)
                << memberList[1][0]
                << std::left
                << std::setw(15)
                << memberList[1][1]
                << std::left
                << std::setw(21)
                <<memberList[1][2]
                << "\n";
    
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

void User :: logOut() {
    std::ofstream ofs;
    ofs.open(currentUserFile, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

void User:: memberMenu() {
    Member *mem;
    cout << "You have chosen to login as member, please Input your account: \n\n";
    cout << "--------Member Login------------\n\n\n\n\n";
    
    if(login()) {
        int userSeletion;
        cout << "\nYou have login as \n"; // Add current Member here
        cout << "\nPlease select the options:\n";
        cout << "\n1.Show Account Information\n2.Search House by Region\n3.Review All Request\n4.Accept Request"
             << "\n5.Decline Request\n6.Rate Tenant\n7.Delete House List\n8.Add House List\n9.View All House"
             << "\n10.Request House\n11.Cancel Request\n12.Rate House\n13.Exit to main menu\n14.Log out\n";
        cout << "\nEnter your option: ";
        cin >> userSeletion;
        switch(userSeletion) {
            case 1:
                showAccountInfo();
                //Current Member
                break;
            case 2:
                mem->searchHouseByRegion();
               break;
            case 14:
                logOut();
                showMenuOption();
                break;
        }
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
            <<"\n6.Search House By Credit\n7.Search House By ID\n8.Search House By Date Range\n9.Sort By Member Score\n10.Exit to main menu\n11.Log Out\n";
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
            case 11:
                logOut();
                showMenuOption();
                break;
        }
    }
    
}
