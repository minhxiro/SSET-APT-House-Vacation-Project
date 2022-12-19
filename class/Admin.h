//
// Created by Vo Nguyen Kien on 18/12/2022.
//

#ifndef SSET_APT_HOUSE_VACATION_PROJECT_ADMIN_H
#define SSET_APT_HOUSE_VACATION_PROJECT_ADMIN_H

#endif //SSET_APT_HOUSE_VACATION_PROJECT_ADMIN_H
#include <iostream>
#include "User.h"
#include "System.h"
using std::string;
using std::vector;
class Admin : public User {
private:
    vector <Member *> members;
    vector <HouseList *> houseList;
public:
    Admin();
    void showAllMember();
    void viewHouseDetail(int id){

    };

    virtual void showAllHouse();
    void viewMemberDetail();
    void viewAllReQuest(Request &userRequest);
    void searchHouseByCredit();
    void searchHouseById();
    void searchHouseByDateRange();
    void sortByMemberScore();
    ~Admin() {}
};