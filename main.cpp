#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "./class/Class.h"

using std:: string;
using std:: cin;
using std:: cout;
using std:: vector;
using std:: fstream;

int main() {
    User user;
//    user.registre();
    user.login();
    int num = user.checkLogin();
    user.showAccountInfo(num);
}