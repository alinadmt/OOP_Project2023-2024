#pragma once
#include <iostream>
#include <string>
using namespace std;

class Ticket {
	int ticketID = 0;
	string ticketType = "";
	int row = 0;
	int seatNo = 0;
	float price;
	static bool isValid;
	int ticketsSoldPerMonth[12];

};

