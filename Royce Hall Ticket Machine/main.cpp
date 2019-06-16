//
//  main.cpp
//  project 5
//
//  Created by Ankush Bharadwaj on 2/26/19.
//  Copyright © 2019 Ankush Bharadwaj. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "Ticket.h"
#include "BoxOffice.h"
#include <string>
using namespace std;

int main() {
    
    //following checks to make sure that the functions in the ticket class work fine
    Ticket t("Pavillion Row 13", 45, "Dodgers vs. Brewers", "Dodger Stadium", 150.00, Ticket::ATHLETICGAME, "August 1, 7:30PM");
    assert((t.getDayTime() == "August 1, 7:30PM"));
    assert((t.getVenue() == "Dodger Stadium"));
    assert((t.getSeat() == 45));
    assert((t.getPrice() == 150.00));
    assert((t.getRow() == "Pavillion Row 13"));
    assert((t.getEvent() == "Dodgers vs. Brewers"));
    assert((t.getKind() == Ticket::ATHLETICGAME));
    t.setPrice(50.00);
    assert((t.getPrice() == 50.00));
    cerr << "poetic justice" << endl;
    
    //following checks to make sure that the functions in the boxoffice class work fine
    BoxOffice b;
    
    //check buyTicket
    Ticket g = b.buyTicket( "Pavillion Row 13", 45, "Dodgers vs. Brewers", "Dodger Stadium", Ticket::ATHLETICGAME, "August 1, 7:30PM" );
    assert((g.getDayTime() == "August 1, 7:30PM"));
    assert((g.getVenue() == "Dodger Stadium"));
    assert((g.getSeat() == 45));
    assert((g.getPrice() == 0));
    assert((g.getRow() == "Pavillion Row 13"));
    assert((g.getEvent() == "Dodgers vs. Brewers"));
    assert((g.getKind() == Ticket::ATHLETICGAME));
    
    //check buyRoyceHallStudentTicket
    Ticket h = b.buyRoyceHallStudentTicket( "Orchestra Row U", 20, "Episode VII: The Force Awakens", Ticket::MOVIE, "September 1, 7:30PM" );
    assert((h.getDayTime() == "September 1, 7:30PM"));
    assert((h.getVenue() == "Royce Hall"));
    assert((h.getSeat() == 20));
    assert((h.getPrice() == 20)); //THIS ONE
    assert((h.getRow() == "Orchestra Row U"));
    assert((h.getEvent() == "Episode VII: The Force Awakens"));
    assert((h.getKind() == Ticket::MOVIE));
    
    //check buyRoyceHallStaffTicket
    Ticket i = b.buyRoyceHallStaffTicket( "Balcony Row J", 120, "An Evening With David Sedaris",  Ticket::OTHER, "October 1, 7:30PM" );
    assert((i.getDayTime() == "October 1, 7:30PM"));
    assert((i.getVenue() == "Royce Hall"));
    assert((i.getSeat() == 120));
    assert((i.getPrice() == 35)); //THIS ONE
    assert((i.getRow() == "Balcony Row J"));
    assert((i.getEvent() == "An Evening With David Sedaris"));
    assert((i.getKind() == Ticket::OTHER));
    
    //check buyRoyceHallTicket
    Ticket j = b.buyRoyceHallTicket( "Orchestra Row A", 12, "Barry Manilow Live In Concert",  Ticket::CONCERT, "November 1, 7:30PM" );
    assert((j.getDayTime() == "November 1, 7:30PM"));
    assert((j.getVenue() == "Royce Hall"));
    assert((j.getSeat() == 12));
    assert((j.getPrice() == 130)); //THIS ONE
    assert((j.getRow() == "Orchestra Row A"));
    assert((j.getEvent() == "Barry Manilow Live In Concert"));
    assert((j.getKind() == Ticket::CONCERT));
    
    
    cerr << "by kendrick lamar" << endl;
    
    return 0;
}
