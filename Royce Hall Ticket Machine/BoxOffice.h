//
//  BoxOffice.hpp
//  project 5
//
//  Created by Ankush Bharadwaj on 2/26/19.
//  Copyright © 2019 Ankush Bharadwaj. All rights reserved.
//

#ifndef BoxOffice_h
#define BoxOffice_h

#include <stdio.h>
#include <string>
#include <iostream>
#include "Ticket.h"
using namespace std;

class BoxOffice
{
public:
    BoxOffice();
    Ticket buyTicket(string row, int seat, string event, string venue, Ticket::KIND kind, string daytime);
    Ticket buyRoyceHallStudentTicket(string row, int seat, string event, Ticket::KIND kind, string daytime);
    Ticket buyRoyceHallStaffTicket(string row, int seat, string event, Ticket::KIND kind, string daytime);
    Ticket buyRoyceHallTicket(string row, int seat, string event, Ticket::KIND kind, string daytime);
};

#endif /* BoxOffice_h */
