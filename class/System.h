//
// Created by Trung Ngo on 17/12/2022.
//

#ifndef SSET_APT_HOUSE_VACATION_PROJECT_SYSTEM_H
#define SSET_APT_HOUSE_VACATION_PROJECT_SYSTEM_H

#endif //SSET_APT_HOUSE_VACATION_PROJECT_SYSTEM_H

#include <iostream>
using std::string;

class System{
    friend bool inputUsernameAuthentication(string username);
    friend bool inputNameAuthentication(string name);
    friend bool inputPasswordAuthenticate(string password);
    friend bool inputPhoneAuthenticate(string phoneNum);
    friend bool inputNumAuthenticate(string num);
    friend bool inputRangeAuthenticate(string range);
    friend bool creditAuth(int credits);
    friend bool scoreAuth(int scores);
};