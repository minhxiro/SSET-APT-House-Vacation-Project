#ifndef _CLASS_
  

#define CLASS
  
#include <iostream>
#include <string>
#include <vector>
using std:: string;
using std:: cin;
using std:: cout;
using std:: vector;

enum city {HUE, HANOI, SAIGON}; //enum for cities

enum requestStatus {PENDING, DENIED, APPROVED}; // enum for request status

enum houseStatus {AVAILABLE, UNVAILABLE}; // enum for house status
// Prototyping classes
class House;
class Admin;
class Member;
class Request;
class HouseList;
class Rating;
class RatingTenant;
class System;

// Declare User class
class User {
    protected:
        string name;
        string full_name; 
        string password;
        string phonenum;
        

        bool isOwner() {

        }
    public:
        User();
        
        
        void login();
        void enterOtpCode();
        void registre();
        void showAccountInfo();
        
        ~User();

};

// Declare Admin class
class Admin : public User {
    private:
        vector <Member *> members;
        vector <HouseList *> houseList;
    public:
        Admin();
        void showAllMember();
        void viewHouseDetail(int id);
        virtual void showAllHouse();
        void viewMemberDetail();
        void viewAllReQuest(Request &userRequest);
        void searchHouseByCredit();
        void searchHouseById();
        void searchHouseByDateRange();
        ~Admin() {}
};

//Declare member class
class Member : public User {
    private:
        int memberID;
        city location;
        House memberHouse;
        double rating_score;
        int credit;
        
        vector <Rating *> ratingFromTenant;
        vector <RatingTenant *> ratingFromOwner;
        vector <Request *> allRequest;
        vector <HouseList *> houseList;
    public:
    friend class Admin;
        Member();
        void showAllHouse(HouseList& allHouse);
        void searchHouseByRegion();
        void reviewAllRequest(Request &userRequest);
        Request acceptReQuest();
        Request declineRequest();
        RatingTenant rateTentant();
        HouseList deleteHouseList();
        HouseList addHouseList();
        void viewAllHouse();
        Request requestHouse();
        Request cancelRequest();
        void rateHouse();
        ~Member();
};

// Declare Request class
class Request {
    private:
        int request;
        int houseId;
        int tenantId;
        requestStatus status;
    public:
        Request();
        ~Request();
};
// Declare house class
class House {
    private:
        User owner;
        string location;
        string description;
        int consuming_point;
        int required_score;
        city location;
};

// Declare houselist
class HouseList {
    private:
        int houselistID;
        int ownerID;
        string currentDate;
        int houseID;
        string dateRange;
        houseStatus stat;

    public:
    friend class Admin;
        HouseList();
        // Need view house detail
        ~HouseList();
        
};
// Declare Rating
class Rating {
    private:
        int ratingID;
        int score;
        string comment;
        string currentDate;
        int tenantID;
        int houseID;
    public:
        Rating();
        ~Rating();
};
// Declare Rating TEnant
class RatingTenant {
    private:
        int ratingId;
        int score;
        string comment;
        string currentDate;
        int tenantID;
        int ownerID;
    public:
        RatingTenant();
        ~RatingTenant();
};
// Declare system
class System {
    public:
        void showWelcomeMenu();
        void showGuestMenu();
        void showAdmineMenu();
        void showMemberMenu();
        int loginVerify(User &user);
        void sendOtpCode();
        bool inputUserNameAuthenicate(User &user);
        bool inputNameAuthenticate (User &user);
        bool inputPasswordAuthenticate (User &user);
        bool inputPhoneAuthenticate (User &user);
        bool inputNumAuthenticate (User &user);
        bool inputRangeAuthenticate (User &user) ;
        bool creditAuth(User &user) ;
        bool scoreAuth(User &user);

        void deleteRowData (int index, string dataFile);
        void updateCellAtId (int id, string data, string dataFile);
        void updateRowAtIndex (int index, string data, string dataFile);
        void addData(string data, string dataFile) ;

        vector<string*> extractByRow(string dataFile);
        vector<string*> extractByColumnIndex(int index, string dataFile);
        string getCurrentDate();
        int idAutoIncrement();
        void seachByCredits();
        void searchById();
        void searchByDate();
        double ratingAverageScore();
 
};
#endif
