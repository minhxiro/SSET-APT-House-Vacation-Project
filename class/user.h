#ifndef USER_H
#define USER_H
#include <iostream>
using std:: string;
class User {
    protected:
        string name;
        string full_name; 
        string password;
        string phonenum;
        

    public:
        User();
        
        
        void login();
        void checkLogin();
        void enterOtpCode();
        virtual void registre();
        void showAccountInfo();
        
        ~User();

};
#endif