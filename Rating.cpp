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

        ofstream outFile("rating.dat", ios_base::app);
        outFile << "House score: " << score << "; ";
        outFile << "Comment: " << comment << endl;
    }

    void showInfo() {
        ifstream inFile("rating.dat");
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
    }

    double calculateAverageScore() {
    ifstream inFile("rating.dat");
    string line;
    int totalScore = 0;
    int numScores = 0;
    while (getline(inFile, line)) {
        size_t scorePos = line.find("House score: ");
        if (scorePos != string::npos) {
            int score = stoi(line.substr(scorePos + 13, 3));
            totalScore += score;
            numScores++;
        }
    }
    return static_cast<double>(totalScore) / numScores;
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

        ofstream outFile("rating.dat", ios_base::app);
        outFile << "Member score: " << score << "; ";
        outFile << "Comment: " << comment << endl;
    }

    void showInfo() {
        ifstream inFile("rating.dat");
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
    }

    double calculateAverageScore() {
    ifstream inFile("rating.dat");
    string line;
    int totalScore = 0;
    int numScores = 0;
    while (getline(inFile, line)) {
        size_t scorePos = line.find("Member score: ");
        if (scorePos != string::npos) {
            int score = stoi(line.substr(scorePos + 14, 3));
            totalScore += score;
            numScores++;
        }
    }
    return static_cast<double>(totalScore) / numScores;
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
        cout << "4. Show average score" << endl;
        cout << "5. Exit" << endl;
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
            double H_avgScore = member.calculateAverageScore();
            cout << "Average house score: " << H_avgScore << endl;
            double M_avgScore = house.calculateAverageScore();
            cout << "Average member score: " << M_avgScore << endl;   
        } else if (selection == 5) {
            exit(0);
        } else {
            cout << "invalid\n";
        }
    }
    return 0;
}
