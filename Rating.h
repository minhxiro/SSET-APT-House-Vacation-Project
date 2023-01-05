#include <iostream>
#include <string>
using std::string;
using std::cout;

class Rating
{
private:
    int score;
    string comment;
    int occupierId;
    int houseId;
public:
    Rating(int score = 0, string comment = "", int occupierId = 0, int houseId = 0)
    : score(score), comment(comment), occupierId(occupierId), houseId(houseId){}
    void rateHouse() {}
    void rateOccupier() {}
    void showInfo() {}
};
