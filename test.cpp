#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std:: string;
using std:: cin;
using std:: cout;
using std:: vector;
using std:: fstream;

int main() {
    string name;
    cout << "Enter name: ";
    getline(cin, name);
    cout << name;
}