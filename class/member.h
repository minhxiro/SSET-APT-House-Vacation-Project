#ifndef MEMBER_H
#define MEMBER_H

#include "user.h"
#include "enum.h"
#include "rating.h"
#include "ratingTenant.h"
#include "house.h"
#include "request.h"
#include <vector>
using std:: vector;
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
        
    public:
        Member();
        virtual void registre();
        virtual void showAccountInfo();
        void showAllHouse();
        void searchHouseByRegion();
        void reviewAllRequest();
        Request acceptReQuest();
        Request declineRequest();
        RatingTenant rateTentant();
        void deleteHouseList();
        void addHouseList();
        void viewAllHouse();
        Request requestHouse();
        Request cancelRequest();
        void rateHouse();
        ~Member();
};
#endif