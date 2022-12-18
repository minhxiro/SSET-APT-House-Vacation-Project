#include <string>
using std::string;
class RatingTenant
{
private:
    int RatingId;
    int Score;
    string Comment;
    string CurrentDate;
    int TenantId;
    int OwnerId;
public:
    RatingTenant(int RatingId = 0, int Score = 0, string Comment = "", string CurrenDate = "", int TenantId = 0, int OwnerId = 0)
    : RatingId(RatingId), Score(Score), Comment(Comment), CurrentDate(CurrentDate), TenantId(TenantId), OwnerId(OwnerId){}
};
