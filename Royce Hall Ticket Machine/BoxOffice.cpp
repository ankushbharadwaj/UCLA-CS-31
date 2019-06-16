//
//  BoxOffice.cpp
//  project 5
//
//  Created by Ankush Bharadwaj on 2/26/19.
//  Copyright © 2019 Ankush Bharadwaj. All rights reserved.
//

#include "BoxOffice.h"
#include "Ticket.h"
#include "Project5Helper.h"

BoxOffice::BoxOffice() {
    
}

Ticket BoxOffice::buyTicket(string row, int seat, string event, string venue, Ticket::KIND  kind, string daytime) {
    double tempPrice = 0.0;
    Ticket t(row, seat, event, venue, tempPrice, kind, daytime);
    return t;
}

Ticket BoxOffice::buyRoyceHallStudentTicket(string row, int seat, string event, Ticket::KIND  kind, string daytime) {
    string venue = "Royce Hall";
    double tempPrice;
    Project5Helper helper;
    switch (kind) {
        case Ticket::ATHLETICGAME:
            tempPrice = 75.00;
            break;
        case Ticket::CONCERT:
            if (helper.endsWithPM(daytime)) { //if true, event  at night
                tempPrice = 65.00;
            }
            else
                tempPrice = 50.00;
            break;
        case Ticket::MOVIE:
            tempPrice = 12.50;
            break;
        case Ticket::OTHER:
            if (helper.endsWithPM(daytime)) { //if true, event  at night
                tempPrice = 55.00;
            }
            else
                tempPrice = 40.00;
            break;
        default:
            cerr << "error in kind" << endl;
    }
    if (helper.startsWithOrchestra(row)) { //if true, row orchestra
        tempPrice = tempPrice*2.0;
    }
    //student discount
    if (tempPrice >= 40.00) {
        tempPrice -= 30.00;
    }
    else {
        tempPrice = tempPrice - (tempPrice * .2);
    }
    
    Ticket t(row, seat, event, venue, tempPrice, kind, daytime);
    return t;
}

Ticket BoxOffice::buyRoyceHallStaffTicket(string row, int seat, string event, Ticket::KIND  kind, string daytime) {
    string venue = "Royce Hall";
    double tempPrice;
    Project5Helper helper;
    switch (kind) {
        case Ticket::ATHLETICGAME:
            tempPrice = 75.00;
            break;
        case Ticket::CONCERT:
            if (helper.endsWithPM(daytime)) { //if true, event  at night
                tempPrice = 65.00;
            }
            else
                tempPrice = 50.00;
            break;
        case Ticket::MOVIE:
            tempPrice = 12.50;
            break;
        case Ticket::OTHER:
            if (helper.endsWithPM(daytime)) { //if true, event  at night
                tempPrice = 55.00;
            }
            else
                tempPrice = 40.00;
            break;
        default:
            cerr << "error in kind" << endl;
    }
    if (helper.startsWithOrchestra(row)) { //if true, row orchestra
        tempPrice = tempPrice*2.0;
    }
    //staff discount
    if (tempPrice >= 40.00) {
        tempPrice -= 20.00;
    }
    else {
        tempPrice = tempPrice - (tempPrice * .1);
    }
    
    Ticket t(row, seat, event, venue, tempPrice, kind, daytime);
    return t;
}

Ticket BoxOffice::buyRoyceHallTicket(string row, int seat, string event, Ticket::KIND  kind, string daytime) {
    string venue = "Royce Hall";
    double tempPrice;
    Project5Helper helper;
    switch (kind) {
        case Ticket::ATHLETICGAME:
            tempPrice = 75.00;
            break;
        case Ticket::CONCERT:
            if (helper.endsWithPM(daytime)) { //if true, event  at night
                tempPrice = 65.00;
            }
            else
                tempPrice = 50.00;
            break;
        case Ticket::MOVIE:
            tempPrice = 12.50;
            break;
        case Ticket::OTHER:
            if (helper.endsWithPM(daytime)) { //if true, event  at night
                tempPrice = 55.00;
            }
            else
                tempPrice = 40.00;
            break;
        default:
            cerr << "error in kind" << endl;
    }
    if (helper.startsWithOrchestra(row)) { //if true, row orchestra
        tempPrice = tempPrice*2.0;
    }
    
    //no discount
    
    Ticket t(row, seat, event, venue, tempPrice, kind, daytime);
    return t;
}

