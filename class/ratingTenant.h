#ifndef RATING_TENANT_H
#define RATING_TENANT_H
#include <iostream>

using std:: string;
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
#endif