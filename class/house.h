#ifndef HOUSE_H
#define HOUSE_H
#include "enum.h"
#include "User.h"
#include <iostream>
using std::string;
class House {
    private:
        User owner;
        string location;
        string description;
        int consuming_point;
        int required_score;
        city location;
};
#endif