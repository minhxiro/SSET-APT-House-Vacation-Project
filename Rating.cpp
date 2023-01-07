#include "Rating.h"
#include "System.h"

void Rating::rateHouse() {
    string input;
    while (true) {
        cout << "Enter your score for the house (-10 to 10): ";
        cin >> input;
        if (!input.empty()) { // check if input is not empty
            if (System::inputNumAuthenticate(input)) { // check if input is a number
                score = stoi(input); // convert string to integer
                if (score >= -10 && score <= 10) {
                    break; // input is valid, break out of loop
                } else {
                    cout << "Invalid score. Please enter a score between -10 and 10." << endl;
                }
            } else {
                cout << "Invalid input. Please enter a number between -10 and 10." << endl;
            }
        } else {
            cout << "No input detected. Please enter a number between -10 and 10." << endl;
        }
    }

    cout << "Enter your comment for the house: ";
    cin.ignore(); 
    getline(cin, comment);

    ofstream outFile("rating.dat", ios_base::app);
    outFile << "Rate ID: " << "RA" << System::idAutoIncrement("rating.dat") << "; ";
    outFile << "House score: " << score << "; ";
    outFile << "Comment: " << comment << "; ";
    outFile << "Current date: " << System::getCurrentDate() << endl;
}

void Rating::showInfo() {
    ifstream inFile("rating.dat");
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
}

double Rating::calculateAverageScoreForHouse(string houseID) {
    ifstream inFile("rating.dat");
    string line;
    int totalScore = 0;
    int numScores = 0;
    while (getline(inFile, line)) {
        size_t idPos = line.find("House ID: ");
        if (idPos != string::npos) {
            string id = line.substr(idPos + 10, 7);
            if (id == houseID) {
                size_t scorePos = line.find("House score: ");
                if (scorePos != string::npos) {
                    int score = stoi(line.substr(scorePos + 13, 3));
                    totalScore += score;
                    numScores++;
                }
            }
        }
    }
    if (numScores == 0) {
        return 0; // no scores found for given house ID
    }
    return static_cast<double>(totalScore) / numScores;
}

void RatingTenant::rateOccupier() {
    string input;
    while (true) {
        cout << "Enter your score for the occupier (-10 to 10): ";
        cin >> input;
        if (!input.empty()) { // check if input is not empty
            if (System::inputNumAuthenticate(input)) { // check if input is a number
                score = stoi(input); // convert string to integer
                if (score >= -10 && score <= 10) {
                    break; // input is valid, break out of loop
                } else {
                    cout << "Invalid score. Please enter a score between -10 and 10." << endl;
                }
            } else {
                cout << "Invalid input. Please enter a number between -10 and 10." << endl;
            }
        } else {
            cout << "No input detected. Please enter a number between -10 and 10." << endl;
        }
    }

    cout << "Enter your comment for the occupier: ";
    cin.ignore(); 
    getline(cin, comment);

    ofstream outFile("ratingTenant.dat", ios_base::app);
    outFile << "Rate ID: " << "RA" << System::idAutoIncrement("ratingTenant.dat") << "; ";
    outFile << "Member score: " << score << "; ";
    outFile << "Comment: " << comment << "; ";
    outFile << "Current date: " << System::getCurrentDate() << endl;
}

void RatingTenant::showInfo() {
    ifstream inFile("ratingTenant.dat");
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
}

double RatingTenant::calculateAverageScoreForMember(string occupierID) {
    ifstream inFile("ratingTenant.dat");
    string line;
    int totalScore = 0;
    int numScores = 0;
    while (getline(inFile, line)) {
        size_t idPos = line.find("Member ID: ");
        if (idPos != string::npos) {
            string id = line.substr(idPos + 11, 7);
            if (id == occupierID) {
                size_t scorePos = line.find("Member score: ");
                if (scorePos != string::npos) {
                    int score = stoi(line.substr(scorePos + 14, 3));
                    totalScore += score;
                    numScores++;
                }
            }
        }
    }
    if (numScores == 0) {
        return 0; // no scores found for given house ID
    }
    return static_cast<double>(totalScore) / numScores;
}

int main() {
Rating member;
RatingTenant house;
string temp;
    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Rate a house" << endl;
        cout << "2. Rate a occupier" << endl;
        cout << "3. Show rating information" << endl;
        cout << "4. Show average house score" << endl;
        cout << "5. Show average member score" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your selection: ";

        int selection;
        cin >> selection;

        if (selection == 1) {
            member.rateHouse();
        } else if (selection == 2) {
            house.rateOccupier();
        } else if (selection == 3) {
            member.showInfo();
            house.showInfo();
        } else if (selection == 4) {
            cout << "Enter house ID: ";
            cin >> temp;
            double H_avgScore = member.calculateAverageScoreForHouse(temp);
            cout << "Average house score: " << H_avgScore << endl;
        } else if (selection == 5) {
            cout << "Enter occupier ID: ";
            cin >> temp;
            double M_avgScore = house.calculateAverageScoreForMember(temp);
            cout << "Average member score: " << M_avgScore << endl;  
        } else if (selection == 6) {
            exit(0);
        } else {
            cout << "invalid\n";
        }
    }
    return 0;
}
