#include <iostream>
#include "Event.h"
#include "Location.h"
#include "Ticket.h"
using namespace std;

int main() {

	//test getter event name for "Event" class
    Event event1;
    event1.setEventName("Meci Steaua-Dinamo");
    cout << endl << "The name of the event is: " << event1.getEventName();

	//test getter no of seats for "Location" class
	Location location1;
	location1.setNoSeats(1000);
	cout << endl << "The number of seats for this theater show is: " << location1.getNoSeats();

	//TESTING THE DESTRUCTOR
	/*{
		Event event2("Miami Beach 2", "13-12-2023", "12:43", 400, EventType::MOVIE, 1);
	}

	Event* pEvent = new Event("Miami Beach 2", "13-12-2023", "12:43", 400, EventType::MOVIE, 1);
	delete pEvent;*/
}