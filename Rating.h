#include <iostream>
#include <string>
using std::string;
using std::cout;

class Rating
{
private:
    int RatingId;
    int Score;
    string Comment;
    string CurrentDate;
    int TenantId;
    int HouseId;
public:
    Rating(int RatingId = 0, int Score = 0, string Comment = "", string CurrentDate = "", int TenantId = 0, int HouseId = 0)
    : RatingId(RatingId), Score(Score), Comment(Comment), CurrentDate(CurrentDate), TenantId(TenantId), HouseId(HouseId){}

    void showInfo(){
        cout << "Rating ID: " << RatingId << ", Score: " << Score << ", Comment: " << Comment << ", Current Date: " 
        << CurrentDate << ", Tenant ID: " << TenantId << ", House ID: " << HouseId;
    }
};
