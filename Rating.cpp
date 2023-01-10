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

    houseID = "HOU1";

    ofstream outFile("rating.dat", ios_base::app);
    outFile << "RAH" << System::idAutoIncrement("rating.dat") << ";";
    outFile << score << ";";
    outFile << comment << ";";
    outFile << System::getCurrentDate() << ";";
    outFile << houseID << ";";
    outFile.close();
    
    double H_avgScore = calculateAverageScoreForHouse(houseID);
    cout << "Average house score: " << H_avgScore << endl;
    ofstream outFile2("rating.dat", ios_base::app);
    outFile2 << H_avgScore << endl;
    outFile2.close();
}

void Rating::showInfo() {
    ifstream inFile("rating.dat");
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
}

double Rating::calculateAverageScoreForHouse(string houseID) {
    // Extract the house ID column and the score column from the rating.dat file
    vector<string> houseIDs = System::extractByColumnIndex(4, "rating.dat");
    vector<string> scores = System::extractByColumnIndex(1, "rating.dat");

    int totalScore = 0;
    int numScores = 0;
    // Iterate through the house IDs and scores and add up the scores for the given house ID
    for (int i = 0; i < houseIDs.size(); i++) {
        if (houseIDs[i] == houseID) {
            totalScore += stoi(scores[i]);
            numScores++;
        }
    }
    if (numScores == 0) {
        return 0; // no scores found for given house ID
    }
    // Calculate and return the average score
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

    occupierID = "MEM1";

    ofstream outFile("ratingTenant.dat", ios_base::app);
    outFile << "RAM" << System::idAutoIncrement("ratingTenant.dat") << ";";
    outFile << score << ";";
    outFile << comment << ";";
    outFile << System::getCurrentDate() << ";";
    outFile << occupierID << ";";
    outFile.close();

    double M_avgScore = calculateAverageScoreForMember(occupierID);
    cout << "Average house score: " << M_avgScore << endl;
    ofstream outFile2("ratingTenant.dat", ios_base::app);
    outFile2 << M_avgScore << endl;
    outFile2.close();
}

void RatingTenant::showInfo() {
    ifstream inFile("ratingTenant.dat");
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
}

double RatingTenant::calculateAverageScoreForMember(string occupierID) {
    // Extract the member ID column and the score column from the rating.dat file
    vector<string> occupierIDs = System::extractByColumnIndex(4, "ratingTenant.dat");
    vector<string> scores = System::extractByColumnIndex(1, "ratingTenant.dat");

    int totalScore = 0;
    int numScores = 0;
    // Iterate through the member IDs and scores and add up the scores for the given member ID
    for (int i = 0; i < occupierIDs.size(); i++) {
        if (occupierIDs[i] == occupierID) {
            totalScore += stoi(scores[i]);
            numScores++;
        }
    }
    if (numScores == 0) {
        return 0; // no scores found for given member ID
    }
    // Calculate and return the average score
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
            house.showInfo();
        } else if (selection == 4) {
            exit(0);
        } else {
            cout << "invalid\n";
        }
    }
    return 0;
}
