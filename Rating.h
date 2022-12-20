#include <iostream>
#include <string>
using std::string;
using std::cout;

class Rating
{
private:
    int ratingId;
    int score;
    string comment;
    string currentDate;
    int tenantId;
    int houseId;
public:
    Rating(int ratingId = 0, int score = 0, string comment = "", string currentDate = "", int tenantId = 0, int houseId = 0)
    : ratingId(ratingId), score(score), comment(comment), currentDate(currentDate), tenantId(tenantId), houseId(houseId){}
    void rateHouse() {}
    void rateOccupier() {}
    void showInfo() {}
};
