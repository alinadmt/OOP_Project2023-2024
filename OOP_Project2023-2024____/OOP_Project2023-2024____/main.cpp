#include <iostream>
#include "Event.h"
#include "Location.h"
#include "Ticket.h"
#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)
using namespace std;

int main() {

	//test getter and setter for "Event" class
	Event event1;

	/*char* name = nullptr;
	name = new char[14];
	strcpy(name, "Steaua-Dinamo");*/
	event1.setEventName("Steaua-Dinamo");
	cout << endl << "The name of the event is: " << event1.getEventName();

	event1.setDate("12/12/2022");
	cout << endl << "The date is: " << event1.getDate();

	event1.setEventTime("19:00");
	cout << endl << "The time is: " << event1.getEventTime();

	event1.setMaxTickets(200);
	cout << endl << "Max number of tickets is: " << event1.getMaxTickets();

	cout << endl << "Event ID is: " << event1.getEventId();

	Event event2("Miami Beach", "13/12/2023", "12:43", 400, EventType::MOVIE);
	cout << endl << "The name of the event is: " << event2.getEventName();
	cout << endl << "The date of the event is: " << event2.getDate();
	cout << endl << "The time of the event is: " << event2.getEventTime();
	cout << endl << "The no of max tickets of the event is: " << event2.getMaxTickets();
	cout << endl;

	event2.ticketsRemained(100);



	time_t current_time = time(NULL);
	//cout << endl << current_time;
	//int time = current_time;
	string time_s = to_string(current_time);
	//cout << endl << "Time as string is: " << time_s;
	cout << endl << endl << endl << "______________________________________________________________";

	cout << endl << event1;
	cout << endl << event2;


	Event event3;
	//cin >> event3;
	event3=++event3;
	event3 = --event3;
	event3 = event3 + 2;
	cout << endl << event3;


	cout << endl << endl << endl << "______________________________________________________________";

	Location location1;
	location1.getLocationName();
	location1.getNoOfTotalSeats();

	location1.setNoRows(20);
	cout<<endl<<"The number of rows is: "<<location1.getNoRows();

	location1.setNoZones(5);
	cout << endl << "There are " << location1.getNoSeats() << " zones";
	location1.getNoZones();
	location1.getSeatsPerRow();
	cout << endl << location1;

	Location location2;
	//cin >> location2;
	location2 = ++location2;
	location2 = location2 + 2;
	cout << endl << location2;

	Location location3;
	location3.addSeat(3);
	location3.print();

	cout << location3;

	cout << endl << endl << endl << "______________________________________________________________";
	cout << endl;

	Ticket ticket1;
	ticket1.setTicketID(1);
	cout << endl << ticket1.getTicketID();

	ticket1.setTicketType("VIP");
	cout << endl << ticket1.getTicketType();
	ticket1.getisValid();
	ticket1.getPrice();
	ticket1.getRow();
	ticket1.getSeatNo();
	cout << endl;

	Ticket ticket2;
	//cin >> ticket2;
	ticket2 = ++ticket2;
	ticket2 = --ticket2;
	cout << endl << ticket2;

	//index operator
	cout << endl << "Feb sales data is " << ticket2[1];
	ticket2[0] = 50;
	cout << event2;


	Ticket ticket3;
	float avgTicketsSold = ticket3.calculateMeanTicketsSoldPerMonth();
	cout << "Mean Tickets sold per month: " << avgTicketsSold << endl;

	ticket3.setPrice(20);
	float priceWithVAT, priceWithoutVAT;
	ticket3.calcTicketVAT(priceWithVAT, priceWithoutVAT);
	cout << "Price with VAT: " << priceWithVAT <<endl;
	cout << "Price without VAT: " << priceWithoutVAT <<endl;
	return 0;

}