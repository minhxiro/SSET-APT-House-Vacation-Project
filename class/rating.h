#ifndef RATING_H
#define RATING_H
#include <iostream>
using std:: string;
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
#endif