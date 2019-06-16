//
//  Ticket.hpp
//  project 5
//
//  Created by Ankush Bharadwaj on 2/26/19.
//  Copyright © 2019 Ankush Bharadwaj. All rights reserved.
//

#ifndef Ticket_h
#define Ticket_h

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Ticket
{

public:
    
    enum KIND {ATHLETICGAME, CONCERT, MOVIE, OTHER};
    string getRow();
    string getEvent();
    int getSeat();
    string getVenue();
    double getPrice();
    void setPrice(double price);
    KIND getKind();
    string getDayTime();
    
    Ticket(string row, int seat, string event, string venue, double price, KIND kind, string daytime);
    
private:
    string mRow, mEvent, mVenue, mDayTime;
    double mPrice;
    int mSeat;
    KIND myKind;
};


#endif /* Ticket_h */
