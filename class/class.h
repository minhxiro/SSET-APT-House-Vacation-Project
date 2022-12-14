#ifndef _CLASS_
  
// Defines _ANIMALS_ if above
// conditions fails
#define CLASS
  
#include <iostream>
#include <string>
using std:: string;
using std:: cin;
using std:: cout;
enum location {HUE, HANOI, SAIGON}; // enum
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
        
        ~User() {}
        void addHouse(House &obj) {}
        void deleteHouse(House &obj) {}
        


};


class Admin : protected User {
    public:
        void showAllMember() {}
        void viewHouseDetail() {}
        void showAllHouse() {}
        void viewMemberDetail() {}
        void viewAllReQuest() {}
        void searchHouseByCredit() {}
        void searchHouseById() {}
        void searchHouseByDateRange() {}
};

class Member : protected User {
    private:
        int memberID;
        
};
class House {
    private:
        User owner;
        string location;
        string description;
        int consuming_point;
        int required_score;
};
#endif
