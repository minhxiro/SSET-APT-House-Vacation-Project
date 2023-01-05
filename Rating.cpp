#include "Rating.h"

class Member {
private:
    string houseId;
    int score;
    vector<string> comment;
public:
    void rateHouse() {
        cout << "Enter the ID of the house you would like to rate: ";
        cin >> houseId;

        while (true) {
            cout << "Enter your score for the house (-10 to 10): ";
            cin >> score;
            if (score >= -10 && score <= 10) {
                break;
            } else {
                cout <<  "Invalid score. Please enter a score between -10 and 10." << endl;
            }
        }

        cout << "Enter your comment for the house (enter 'submit' to finish): ";
        while (true) {
            string line;
            getline(cin, line);
            if (line == "submit") {
                break;
            }
            comment.push_back(line);
        }

        ofstream outFile("rating_data.dat", ios_base::app);
        outFile << "House ID: " << houseId << endl;
        outFile << "Score: " << score << endl;
        outFile << "Comment: ";
        for (const string& line : comment) {
            outFile << "    " << line << endl;
        }
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
    string occupierId;
    int score;
    vector<string> comment;
public:
    void rateOccupier() {
        cout << "Enter the ID of the occupier you would like to rate: ";
        cin >> occupierId;

        while (true) {
            cout << "Enter your score for the occupier (-10 to 10): ";
            cin >> score;
            if (score >= -10 && score <= 10) {
                break;
            } else {
                cout <<  "Invalid score. Please enter a score between -10 and 10." << endl;
            }
        }

        cout << "Enter your comment for the occupier (enter 'submit' to finish): ";
        while (true) {
            string line;
            getline(cin, line);
            if (line == "submit") {
                break;
            }
            comment.push_back(line);
        }

        ofstream outFile("rating_data.dat", ios_base::app);
        outFile << "Occupier ID: " << occupierId << endl;
        outFile << "Score: " << score << endl;
        outFile << "Comment: ";
        for (const string& line : comment) {
            outFile << "    " << line << endl;
        }
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
