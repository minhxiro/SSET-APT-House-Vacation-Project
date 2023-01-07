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
    int houseID;
public:
    Rating(int score = 0, string comment = "", int houseID = 0)
    : score(score), comment(comment), houseID(houseID){}
    void rateHouse();
    void showInfo();
    double calculateAverageScore();
};
// Declare Rating TEnant
class RatingTenant {
private:
    int score;
    string comment;
    string currentDate;
    int  occupierID;
public:
    RatingTenant(int score = 0, string comment = "", int  occupierID = 0)
    : score(score), comment(comment), occupierID( occupierID){} 
    void rateOccupier(); 
    void showInfo(); 
    double calculateAverageScore();
};