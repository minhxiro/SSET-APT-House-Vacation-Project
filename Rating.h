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

// Declare Rating
class Rating {
private:
    int score;
    string comment;
    string currentDate;
    string houseID;
public:
    Rating(int score = 0, string comment = "", string houseID = "")
    : score(score), comment(comment), houseID(houseID){}
    void rateHouse();
    void showInfo();
    double calculateAverageScoreForHouse(string houseID);
};
// Declare Rating TEnant
class RatingTenant {
private:
    int score;
    string comment;
    string currentDate;
    string occupierID;
public:
    RatingTenant(int score = 0, string comment = "", string occupierID = "")
    : score(score), comment(comment), occupierID(occupierID){} 
    void rateOccupier(); 
    void showInfo(); 
    double calculateAverageScoreForMember(string occupierID);
};