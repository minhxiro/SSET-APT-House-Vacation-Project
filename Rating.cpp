#include "Rating.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>

struct House {
    int score;
    std::string comment;
};

class Member {
private:
    std::map<std::string, House> occupiedHouses;
public:
    void rateHouse() {
        std::string houseId;
        int score;
        std::string comment;

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

        std::cout << "Enter your comment for the house: ";
        std::cin.ignore(); // ignore the newline character left in the input buffer
        std::getline(std::cin, comment);

        occupiedHouses[houseId] = {score, comment};

        std::ofstream outFile("rating_data.txt", std::ios_base::app);
        outFile << "Occupier ID: " << houseId << std::endl;
        outFile << "Score: " << score << std::endl;
        outFile << "Comment: " << comment << std::endl;
}

    void showInfo() const {
        std::cout << "Occupied houses:" << std::endl;   
        for (const auto& it : occupiedHouses) {
            std::cout << "  House ID: " << it.first << std::endl;
            std::cout << "  Score: " << it.second.score << std::endl;
            std::cout << "  Comment: " << it.second.comment << std::endl;
        }
    }
};

struct Occupier {
    int score;
    std::string comment;
};

class HouseOwner {
private:
    std::map<std::string, Occupier> occupiers;
public:
    void rateOccupier() {
        std::string tenantId;
        int score;
        std::string comment;

        std::cout << "Enter the ID of the occupier you would like to rate: ";
        std::cin >> tenantId;

        while (true) {
            std::cout << "Enter your score for the occupier (-10 to 10): ";
            std::cin >> score;
            if (score >= -10 && score <= 10) {
                break;
            } else {
                cout <<  "Invalid score. Please enter a score between -10 and 10." << std::endl;
            }
        }

        std::cout << "Enter your comment for the occupier: ";
        std::cin.ignore(); // ignore the newline character left in the input buffer
        std::getline(std::cin, comment);

        occupiers[tenantId] = {score, comment};

        std::ofstream outFile("rating_data.txt", std::ios_base::app);
        outFile << "Occupier ID: " << tenantId << std::endl;
        outFile << "Score: " << score << std::endl;
        outFile << "Comment: " << comment << std::endl;
}

    void showInfo() const {
        std::cout << "Occupiers:" << std::endl;
        for (const auto& it : occupiers) {
            std::cout << "  Occupier ID: " << it.first << std::endl;
            std::cout << "  Score: " << it.second.score << std::endl;
            std::cout << "  Comment: " << it.second.comment << std::endl;
        }
    }
};


int main() {
Member member;
HouseOwner house;

    while (true) {
        std::cout << "Menu:" << std::endl;
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
            house.showInfo();
        } else if (selection == 4){
            exit(0);
        } else {
            std::cout << "invalid\n";
        }
    }
return 0;
}