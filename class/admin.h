#ifndef ADMIN_H
#define ADMIN_H
#include <vector>
#include "Member.h"
#include "House.h"
using std:: vector;
class Admin : public User {
    private:
        vector <Member *> members;
        vector <House *> houseList;
    public:
        Admin();
        void showAllMember();
        void viewHouseDetail();
        void showAllHouse(House& allHouse);
        void viewMemberDetail();
        void viewAllReQuest(Request &userRequest);
        void searchHouseByCredit();
        void searchHouseById();
        void searchHouseByDateRange();
        ~Admin() {}
};
#endif