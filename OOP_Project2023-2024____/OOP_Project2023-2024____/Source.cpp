#include <iostream>
#include <string>
using namespace std;


class Location {
	const int noSeats;
	int rows;
	string zones;
	int* seatsPerRow;
	string locationName;

};

class Event {
	string name;
	string date;
	string time;
	string type;
	const int maxTickets;
	static int ticketsSold;
	int eventID;


};

class Ticket {
	int ticketID;
	string ticketType;
	int row;
	int seatNo;
	bool isValid;

};















int main() {

}