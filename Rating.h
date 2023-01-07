#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::vector;
using std::ofstream;
using std::ifstream;
using std::ios_base;
using std::endl;

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
    double calculateAverageScore() {}
};
