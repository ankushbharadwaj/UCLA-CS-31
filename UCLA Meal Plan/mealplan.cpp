//
//  main.cpp
//  mealplan
//
//  Created by Ankush Bharadwaj on 1/24/19.
//  Copyright © 2019 Ankush Bharadwaj. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    std::string tb;
    std::string meal;
    std::string ss;
    std::string rn;
    std::string price;
    
    
    cout << "Ticket or BruinCard? ";
    getline(std::cin,tb);
    
    if ((tb != "Ticket" && tb != "BruinCard") || tb.empty()) {
        cout << "The kind value must either be Ticket or BruinCard.\n";
        return 0;
    }
    
    //ticket => 2 questions total
    if (tb == "Ticket") {
        
        //meal type
        cout << "Breakfast, Lunch or Dinner? ";
        getline(std::cin,meal);
        if ((meal != "Breakfast" && meal != "Lunch" && meal != "Dinner") || meal.empty()) {
            cout << "The meal value must either be Breakfast, Lunch or Dinner.\n";
            return 0;
        }
        //price
        if (tb == "Ticket" && meal == "Breakfast") {
            price = "12.50";
        }
        if (tb == "Ticket" && meal == "Lunch") {
            price = "14.50";
        }
        if (tb == "Ticket" && meal == "Dinner") {
            price = "17.00";
        }
        
    }
    
    //bruincard
    if (tb == "BruinCard") {
        
        //meal type
        cout << "Breakfast, Lunch or Dinner? ";
        getline(std::cin,meal);
        if ((meal != "Breakfast" && meal != "Lunch" && meal != "Dinner") || meal.empty()) {
            cout << "The meal value must either be Breakfast, Lunch or Dinner.\n";
            return 0;
        }
        
        //student or staff
        cout << "Student or Staff? ";
        getline(std::cin,ss);
        if ((ss != "Student" && ss != "Staff") || ss.empty()) {
            cout << "The type value must either be Student or Staff.\n";
            return 0;
        }
        //resident or not
        if (ss == "Student") {
            cout << "Resident? ";
            getline(std::cin,rn);
            if ((rn != "Yes" && rn != "No") || rn.empty()) {
                cout << "The resident value must either be Yes or No.\n";
                return 0;
            }
        }
        
        //bruincard and staff
        if (tb == "BruinCard" && ss == "Staff" && meal == "Breakfast") {
            price = "11.25";
        }
        if (tb == "BruinCard" && ss == "Staff" && meal == "Lunch") {
            price = "12.75";
        }
        if (tb == "BruinCard" && ss == "Staff" && meal == "Dinner") {
            price = "14.75";
        }
        
        //bruincard and resident student
        if (tb == "BruinCard" && ss == "Student" && rn == "Yes" && meal == "Breakfast") {
            price = "9.75";
        }
        if (tb == "BruinCard" && ss == "Student" && rn == "Yes" && meal == "Lunch") {
            price = "11.25";
        }
        if (tb == "BruinCard" && ss == "Student" && rn == "Yes" && meal == "Dinner") {
            price = "12.25";
        }
        
        //bruincard and nonresident student
        if (tb == "BruinCard" && ss == "Student" && rn == "No" && meal == "Breakfast") {
            price = "10.00";
        }
        if (tb == "BruinCard" && ss == "Student" && rn == "No" && meal == "Lunch") {
            price = "11.75";
        }
        if (tb == "BruinCard" && ss == "Student" && rn == "No" && meal == "Dinner") {
            price = "12.75";
        }
    }

    //final statements
    cout << "Thank you for eating at UCLA today. Your meal cost is $" << price << ".\n";
    return 0;
}

