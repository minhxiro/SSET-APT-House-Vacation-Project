
#include <iostream>
#include <System.h>
#include <regex>

using std::string;
using std::cout;
using std::regex;


bool inputUsernameAuthentication(string username) {
    //false: cout "Username should only contains 8 to 15 character and no white spaces!!!"
    //true: continue
    regex reg("\s");
    if (std::regex_match(username, reg)) {
        return false;
    } else {
        if (8 > username.length() || username.length() > 14) {
            return false;
        } else {
            return true;
        }
    }
}

bool inputNameAuthentication(string name) {
    //false: Name must contain 8 to 20 characters and no digits, no special characters, and no white spaces
    //true: continue
    regex reg("^[a-zA-Z]*{8,20}$");
    if (std::regex_match(name, reg)) {
        return true;
    } else {
        return false;
    }
}

bool inputPasswordAuthenticate(string password){
    //false: Minimum 8 and maximum 10 characters, at least one uppercase letter, one lowercase letter, one number and one special character:
    //true: continue
    regex reg ("^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[@$!%*?&])[A-Za-z\d@$!%*?&]{8,10}$");
    if(std::regex_match(password,reg)){
        return true;
    }else{
        return false;
    }


}

bool inputPhoneAuthenticate(string phoneNum);

bool inputNumAuthenticate(string num);

bool inputRangeAuthenticate(string range);

bool creditAuth(int credits);

bool scoreAuth(int scores);

int main() {

}