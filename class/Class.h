#ifndef _CLASS_



#define _CLASS_



#include "../SystemClass/System.h"

using std:: string;
using std:: cin;
using std:: cout;
using std:: vector;

enum city {HUE, HANOI, SAIGON}; //enum for cities

enum requestStatus {PENDING, DENIED, APPROVED}; // enum for request status

enum houseStatus {AVAILABLE, UNAVAILABLE}; // enum for house status
// Prototyping classes
class House;
class Admin;
class Member;
class Request;
class Rating;
class RatingTenant;
class User;

// Declare User class



class User {
protected:
    double ratingScore;
    int credit;
    string memberID;
    string name;
    string fullName;
    string password;
    string phonenum;
    int otp;
    bool isOwner();
public:
    

    void logOut();
    void guestMenu();
    bool login();
    bool enterOtpCode();
    void registre();
    void showAccountInfo();
    // int checkLogin();
    bool isAdmin();
    void showMenuOption();
    void memberMenu();
    void adminMenu();
    void showAllHouse();
    void searchHouseById();
    void viewHouseDetail(int id);
};

// Declare Admin class
class Admin : public User {
private:
    vector <Member *> members;
    vector <House *> houseList;
public:

    
    void showAllMember();
    
    
    void viewMemberDetail();
    void viewAllReQuest();
    void searchHouseByCredit(int credit);
    
    void searchHouseByDateRange(string dateRange);
    void sortByMemberScore();
    
};

//Declare member class
class Member : public User {
private:
    
    city location;
    House* memberHouse;
    

    vector <Rating> ratingFromTenant;
    vector <RatingTenant> ratingFromOwner;
    vector <Request> allRequest;
    vector <House *> houseList;
public:
     
    friend class Admin;
    city getLocation();
    virtual void showAccountInfo();
    // void showAllHouse();
    void searchHouseByRegion();
    void reviewAllRequest();
    void acceptReQuest(string acceptID);
    void declineRequest(string declineID);
    RatingTenant rateTentant();
    void deleteHouseList();
    void addHouseList();
    void viewAllHouse();
    void requestHouse();
    void cancelRequest();
    void rateHouse();
    friend class System;
    
};

// Declare Request class
class Request {
private:
    string requestID;
    string houseId;
    string tenantId;
    requestStatus status;
public:
    
    friend class Member;
    


};
// Declare house class
class House {
private:
    User owner;
    string ownerID;
    string currentDate;
    string houseID;
    string dateRange;
    houseStatus stat;
    string description;
    int consuming_point;
    int required_score;
    Rating *rate;
    city location;
    friend class Admin;
    friend class Member;
};


// Declare Rating
class Rating {
private:
    string ratingID;
    int score;
    string comment;
    string currentDate;
    string tenantID;
    string houseID;

    friend class House;
    friend class Member;
public:
    

};
// Declare Rating TEnant
class RatingTenant {
private:
    string ratingId;
    int score;
    string comment;
    string currentDate;
    string tenantID;
    string ownerID;
public:

    
};
// Declare system
//
// Created by Trung Ngo on 17/12/2022.
//






#endif

