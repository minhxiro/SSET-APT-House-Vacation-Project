#include "Rating.h"

class Member {
private:
    int score;
    string comment;
public:
    void rateHouse() {
        while (true) {
            cout << "Enter your score for the house (-10 to 10): ";
            cin >> score;
            if (score >= -10 && score <= 10) {
                break;
            } else {
                cout <<  "Invalid score. Please enter a score between -10 and 10." << endl;
            }
        }

        cout << "Enter your comment for the house: ";
        cin.ignore(); 
        getline(cin, comment);

        ofstream outFile("rating_data.dat", ios_base::app);
        outFile << "\nScore: " << score << "; ";
        outFile << "Comment: " << comment;
    }

    void showInfo() {
        ifstream inFile("rating_data.dat");
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
    }
};

class HouseOwner {
private:
    int score;
    string comment;
public:
    void rateOccupier() {
        while (true) {
            cout << "Enter your score for the occupier (-10 to 10): ";
            cin >> score;
            if (score >= -10 && score <= 10) {
                break;
            } else {
                cout <<  "Invalid score. Please enter a score between -10 and 10." << endl;
            }
        }

        cout << "Enter your comment for the occupier: ";
        cin.ignore(); 
        getline(cin, comment);

        ofstream outFile("rating_data.dat", ios_base::app);
        outFile << "\nScore: " << score << "; ";
        outFile << "Comment: " << comment;
    }

    void showInfo() {
        ifstream inFile("rating_data.dat");
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
    }
};

int main() {
Member member;
HouseOwner house;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Rate a house" << endl;
        cout << "2. Rate a occupier" << endl;
        cout << "3. Show rating information" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your selection: ";

        int selection;
        cin >> selection;

        if (selection == 1) {
            member.rateHouse();
        } else if (selection == 2) {
            house.rateOccupier();
        } else if (selection == 3) {
            member.showInfo();
        } else if (selection == 4) {
            exit(0);
        } else {
            cout << "invalid\n";
        }
    }
return 0;
}
