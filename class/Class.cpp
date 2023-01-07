#include "Class.h"

using std::string;
using std::cin;
using std::cout;
using std::vector;
using std::fstream;
using std::regex;


void Member::acceptReQuest(string acceptID) {
    vector<vector<string> > allRequest = System::extractByRow(requestFile);
    string tempHouID = "HOU" + std::to_string(this->memberHouse->houseID); //temp houseID to compare
    int count = 0; //count variable to count the request of a particular house
    for (vector<string> &i: allRequest) {
        //count the appearance
        if (i[2] == tempHouID) {
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
    string tempHouID = "HOU" + std::to_string(this->memberHouse->houseID); //temp houseID to compare
    int count = 0; //count variable to count the request of a particular house
    for (vector<string> &i: allRequest) {
        //count the appearance
        if (i[2] == tempHouID) {
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

void Member::showAllHouse() {
    cout << "List of available houses is being showed below:\n";
    vector<string> listOfHouse;
    listOfHouse = System::extractByColumnIndex(0, houseFile);

    cout << "House name: \n";
    for (string &obj: listOfHouse) {
        cout << obj << " ";
    }
}

void Member::showAccountInfo() {
    cout << "Your full name is: " << this->full_name << "\n";
    cout << "Your phone number is: " << this->phonenum << "\n";
    cout << "Your ID is: " << this->memberID << "\n";
    cout << "Your credit is: " << this->credit << "\n";
    cout << "Your rating score is: " << this->rating_score << "\n";
}

void Member::requestHouse() {
    int n;
    string houseID;
    // Get house ID in a vector
    vector<string> listHouse = System::extractByColumnIndex(1, houseFile); // Note
    cout << "How many houses you want to request? ";
    cin >> n;
    // Enter house ID to find house
    for (int i = 0; i < n; i++) {
        cout << "Enter the house ID: ";
        getline(cin, houseID);
        for (string &tmp: listHouse) {
            while (houseID != tmp) {
                cout << "Your house is not added in the list\n";
            }
            if (houseID == tmp) {
                cout << "Successful to request house";
                System::addData(houseID, requestFile);
                Request obj;
                obj.houseId = std::stoi(houseID);
                this->allRequest.push_back(obj);
            }
        }
    }
}


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


void Member::addHouse() {
    cout << "Enter your house date: ";
    cin >> this->memberHouse->dateRange;
    System::addData(this->memberHouse->dateRange, houseFile);
    cout << "Enter house owner: ";
    getline(cin, this->full_name);
    System::addData(this->full_name, houseFile);
}

void Member::reviewAllRequest() {
    vector<vector<string> > list_of_request = System::extractByRow(requestFile); // Get data into a 2D vector

    cout << "Your request today is: \n";
    for (vector<string> &obj: list_of_request) {
        for (string &temp: obj) {
            cout << "temp ";
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
            << std::setw(10)
            << "MemberID"
            << std::left
            << std::setw(15)
            << "Full Name"
            << "\n";
    vector<vector<string> > memberList = System::extractByRow(memberFile);
    for (int i = 0; i < memberList.size(); i++) {
        cout
                << std::left
                << std::setw(10)
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
            << std::setw(35)
            << "Description"
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
                << std::setw(35)
                << houseList[i][7]
                << "\n";
    }
}

void Admin::viewMemberDetail() {

    vector<vector<string> > memberList = System::extractByRow(memberFile);

    cout << "\nAll members: " << "\n";
    cout
            << std::left
            << std::setw(15)
            << "MemberID"
            << std::left
            << std::setw(15)
            << "Full Name"
            << std::left
            << std::setw(15)
            << "PhoneNum"
            << std::left
            << std::setw(15)
            << "Username"
            << std::left
            << std::setw(8)
            << "Credit"
            << std::left
            << std::setw(15)
            << "Location"
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
                << std::setw(15)
                << memberList[i][2]
                << std::left
                << std::setw(15)
                << memberList[i][3]
                << std::left
                << std::setw(8)
                << memberList[i][5]
                << std::left
                << std::setw(15)
                << memberList[i][6]
                << std::left
                << std::setw(10)
                << memberList[i][7]
                << std::endl;
    }
}

void Admin::viewHouseDetail(int id) {
    //tempID to compare with houseID
    string tempID = "HOU" + std::to_string(id);
    //parameter to count the appearance
    int count = 0;
    vector<vector<string> > houseList = System::extractByRow(houseFile);

    for (int i = 0; i < houseList.size(); i++) {
        if (tempID == houseList[i][0]) {
            count++;
            cout << "\nHouse with this ID will be displayed : " << "\n";
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
                    << std::setw(35)
                    << "Description"
                    << "\n";
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
                    << std::setw(35)
                    << houseList[i][7]
                    << "\n";
        }
    }
    //if count = 0 then there is no matching house
    if (count == 0) {
        cout << "\nThere is no house with this ID\n";
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
    //count variable to count the appearance
    int count = 0;
    vector<vector<string> > houseList = System::extractByRow(houseFile);

    for (int i = 0; i < houseList.size(); i++) {
        if (dateRange == houseList[i][3]) {
            count++;
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
    if (count == 0) {
        cout << "\nThere is no house matching with this date range\n";
    }

}

void Admin::searchHouseByCredit(int credit) {
    //count variable to count the appearance
    int count = 0;
    vector<vector<string> > houseList = System::extractByRow(houseFile);

    for (int i = 0; i < houseList.size(); i++) {
        if (credit == std::stoi(houseList[i][4])) {
            count++;
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
    if (count == 0) {
        cout << "\nThere is no house matching with this credit\n";
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

void User::login() {
    cout << "Enter the user name: ";
    cin >> this->name;
    cout << "Enter password: ";
    cin >> this->password;
}

void User::checkLogin() {
    // Read data of member:
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
    // Check password
    for (int i = 0; i < index; i++) {
        if ((informationData[i].find(this->name) != std::string::npos) &&
            (informationData[i].find(this->password) != std::string::npos)) {
            cout << "You have logined as " << this->name << "\n";
        } else cout << "Wrong username or password\n";
    }
}

void User::showAccountInfo() {
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
    while (!System::inputPasswordAuthenticate(this->password)) {
        cout
                << "Minimum 8 and maximum 10 characters, at least one uppercase letter, one lowercase letter, one number and one special character"
                << "\n";
        cout << "Please enter again: ";
        getline(cin, this->password);
    }

    cout << "Enter your full name: ";
    getline(cin, this->full_name);
    while (!System::inputNameAuthentication(this->full_name)) {
        cout << "Name must contain 8 to 20 characters and no digits, no special characters, and no white spaces"
             << "\n";
        cout << "Please enter again: ";
        getline(cin, this->full_name);
    }
    cout << "Enter your phone number: ";
    getline(cin, this->phonenum);
    while (!System::inputPhoneAuthenticate(this->phonenum)) {
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

    data = "MEM" + std::to_string(System::idAutoIncrement(memberFile)) + ";" + this->full_name + ";" +
           this->phonenum + ";" + this->name + ";" + this->password + ";" + "500" + ";" + cityLocation + ";" + "0";
    System::addData(data, memberFile);


}

void User::enterOtpCode() {
    // Get the otp from system:
    int code;
    this->otp = System::sendOTP();
    cout << "Your OTP Code is: " << this->otp;
    cout << "\nPlease enter the code sent to you to verify if you are robot or not: ";
    cin >> code;
    // Check OTP code
    while (code != this->otp) {
        this->otp = System::sendOTP();
        cout << "Your OTP Code is: " << this->otp;
        cout << "\nPlease enter the code sent to you to verify if you are robot or not: ";
        cin >> code;
    }
    if (code == this->otp) {
        cout << "\nYou have logined as Member: \n";
    }
}

