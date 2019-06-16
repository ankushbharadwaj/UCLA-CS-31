//
//  Ticket.cpp
//  project 5
//
//  Created by Ankush Bharadwaj on 2/26/19.
//  Copyright © 2019 Ankush Bharadwaj. All rights reserved.
//

#include "Ticket.h"

Ticket::Ticket(string row, int seat, string event, string venue, double price, KIND kind, string daytime)
{
    mRow = row;
    mSeat = seat;
    mEvent = event;
    mVenue = venue;
    mPrice = price;
    myKind = kind;
    mDayTime = daytime;
}

string Ticket::getRow () {
    return mRow;
}

string Ticket::getEvent () {
    return mEvent;
}

int Ticket::getSeat() {
    return mSeat;
}

string Ticket::getVenue() {
    return mVenue;
}

double Ticket::getPrice() {
    return mPrice;
}

Ticket::KIND Ticket::getKind() {
    return myKind;
}

string Ticket::getDayTime() {
    return mDayTime;
}

void Ticket::setPrice(double price) {
    mPrice = price;
}
