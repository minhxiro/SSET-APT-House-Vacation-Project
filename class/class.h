#ifndef _CLASS_
  
// Defines _ANIMALS_ if above
// conditions fails
#define CLASS
  
#include <iostream>
#include <string>
using std:: string;
using std:: cin;
using std:: cout;
class House;
class Member {
    private:
        string name;
        string full_name;
        string password;
        string phonenum;
        int credit_point;
        int rating_score;

        bool isOwner() {

        }
    public:
        Member(string name = "", string full_name = "",  string password = "", string phonenum = "", int credit_point = 500, int rating_score = 0)
            : name(name), full_name(full_name), password(password), phonenum(phonenum), credit_point(credit_point), rating_score(rating_score) {}
        
        void addHouse(House &obj) {}
        void deleteHouse(House &obj) {}
        


};

class House {
    private:
        Member owner;
        int consuming_point;
        int required_score;
};
#endif