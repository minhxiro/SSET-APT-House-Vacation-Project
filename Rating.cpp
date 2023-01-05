#include "Rating.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

class Member {
private:
    std::string houseId;
    int score;
    std::vector<std::string> comment;
public:
    void rateHouse() {
        std::cout << "Enter the ID of the house you would like to rate: ";
        std::cin >> houseId;

        while (true) {
            std::cout << "Enter your score for the house (-10 to 10): ";
            std::cin >> score;
            if (score >= -10 && score <= 10) {
                break;
            } else {
                cout <<  "Invalid score. Please enter a score between -10 and 10." << std::endl;
            }
        }

        std::cout << "Enter your comment for the house (enter 'submit' to finish): ";
        while (true) {
            std::string line;
            std::getline(std::cin, line);
            if (line == "submit") {
                break;
            }
            comment.push_back(line);
        }

        std::ofstream outFile("rating_data.dat", std::ios_base::app);
        outFile << "House ID: " << houseId << std::endl;
        outFile << "Score: " << score << std::endl;
        outFile << "Comment: ";
        for (const std::string& line : comment) {
            outFile << "    " << line << std::endl;
        }
}

    void showInfo() {
        std::ifstream inFile("rating_data.dat");
        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl;
        }
    }
};

class HouseOwner {
private:
    std::string occupierId;
    int score;
    std::vector<std::string> comment;
public:
    void rateOccupier() {
        std::cout << "Enter the ID of the occupier you would like to rate: ";
        std::cin >> occupierId;

        while (true) {
            std::cout << "Enter your score for the occupier (-10 to 10): ";
            std::cin >> score;
            if (score >= -10 && score <= 10) {
                break;
            } else {
                cout <<  "Invalid score. Please enter a score between -10 and 10." << std::endl;
            }
        }

        std::cout << "Enter your comment for the occupier (enter 'submit' to finish): ";
        while (true) {
            std::string line;
            std::getline(std::cin, line);
            if (line == "submit") {
                break;
            }
            comment.push_back(line);
        }

        std::ofstream outFile("rating_data.dat", std::ios_base::app);
        outFile << "Occupier ID: " << occupierId << std::endl;
        outFile << "Score: " << score << std::endl;
        outFile << "Comment: ";
        for (const std::string& line : comment) {
            outFile << "    " << line << std::endl;
        }
}

    void showInfo() {
        std::ifstream inFile("rating_data.dat");
        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl;
        }
    }
};

int main() {
Member member;
HouseOwner house;

    while (true) {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Rate a house" << std::endl;
        std::cout << "2. Rate a occupier" << std::endl;
        std::cout << "3. Show rating information" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your selection: ";

        int selection;
        std::cin >> selection;

        if (selection == 1) {
            member.rateHouse();
        } else if (selection == 2) {
            house.rateOccupier();
        } else if (selection == 3) {
            member.showInfo();
        } else if (selection == 4) {
            exit(0);
        } else {
            std::cout << "invalid\n";
        }
    }
return 0;
}
