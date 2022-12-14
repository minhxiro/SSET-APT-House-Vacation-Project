#ifndef _CLASS_
  
// Defines _ANIMALS_ if above
// conditions fails
#define CLASS
  
#include <iostream>
#include <string>
using std:: string;
using std:: cin;
using std:: cout;
enum city {HUE, HANOI, SAIGON}; // enum
class House;
class User {
    protected:
        string name;
        string full_name;
        string password;
        string phonenum;
        int credit_point;
        int rating_score;

        bool isOwner() {

        }
    public:
        User(string name = "", string full_name = "",  string password = "", string phonenum = "", int credit_point = 500, int rating_score = 0)
            : name(name), full_name(full_name), password(password), phonenum(phonenum), credit_point(credit_point), rating_score(rating_score) {}
        
        
        void login();
        void registre();
        void showAccountInfo();
        
        ~User() {}

};


class Admin : public User {
    public:
        void showAllMember();
        void viewHouseDetail();
        void showAllHouse();
        void viewMemberDetail();
        void viewAllReQuest();
        void searchHouseByCredit();
        void searchHouseById();
        void searchHouseByDateRange();
};

class Member : public User {
    private:
        int memberID;
        city location;
        House house_list;
    public:
        void showAllHouse();
        void searchHouseByRegion();
        void reviewAllRequest();
        void acceptReQuest();
        void declineRequest();
        void rateTentant();
        void deleteHouseList();
        void addHouseList();
        void rateTenant();
        void viewAllHouse();
        void requestHouse();
        void cancelRequest();
        void rateHouse();
        ~Member() {}
};


class House {
    private:
        User owner;
        string location;
        string description;
        int consuming_point;
        int required_score;
        city location;
};

class System {
    
};
#endif
