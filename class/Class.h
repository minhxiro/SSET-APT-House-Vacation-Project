#ifndef _CLASS_



#define _CLASS_


#include "../SystemClass/System.h"
using std:: string;
using std:: cin;
using std:: cout;
using std:: vector;

//enum city {HUE, HANOI, SAIGON}; //enum for cities
//
//enum requestStatus {PENDING, DENIED, APPROVED}; // enum for request status
//
//enum houseStatus {AVAILABLE, UNAVAILABLE}; // enum for house status
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
    string name;
    string full_name;
    string password;
    string phonenum;
    int otp;
    bool isOwner();
public:
    



    void login();
    void enterOtpCode();
    void registre();
    void showAccountInfo();
    void checkLogin();
    
    

};

// Declare Admin class
class Admin : public User {
private:
    vector <Member *> members;
    vector <House *> houseList;
public:

    
    void showAllMember();
    void viewHouseDetail(int id);
    virtual void showAllHouse();
    void viewMemberDetail();
    void viewAllReQuest();
    void searchHouseByCredit(int credit);
    void searchHouseById();
    void searchHouseByDateRange(string dateRange);
    void sortByMemberScore();
    
};

//Declare member class
class Member : public User {
private:
    int memberID;
    string location;
    House* memberHouse;
    double rating_score;
    int credit;

    vector <Rating> ratingFromTenant;
    vector <RatingTenant> ratingFromOwner;
    vector <Request> allRequest;
    vector <House *> houseList;
public:
    friend class Admin;
    virtual void showAccountInfo();
    void showAllHouse();
    void searchHouseByRegion();
    void reviewAllRequest();
    void acceptReQuest(int declineID);
    void declineRequest(int declineID);
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
    int request;
    int houseId;
    int tenantId;
    string status;
public:
    
    friend class Member;
    


};
// Declare house class
class House {
private:
    User owner;
    int ownerID;
    string currentDate;
    int houseID;
    string dateRange;
    string stat;
    string description;
    int consuming_point;
    int required_score;
    Rating *rate;
    string location;
    friend class Admin;
    friend class Member;
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

    friend class House;
    friend class Member;
public:
    

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

    
};
// Declare system
//
// Created by Trung Ngo on 17/12/2022.
//






#endif

