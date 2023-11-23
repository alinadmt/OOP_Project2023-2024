#pragma once
#include <iostream>
#include <string>
using namespace std;

class Ticket {
private:
	int ticketID = 0;
	string ticketType = "";
	int row = 0;
	int seatNo = 0;
	float price;
	bool isValid;
	int ticketsSoldPerMonth[12];
	int currentMonth = 0;

public:

	//getters
	int getTicketID() {
		return this->ticketID;
	}

	string getTicketType() {
		return this->ticketType;
	}

	int getRow() {
		return this->row;
	}

	int getSeatNo() {
		return this->seatNo;
	}

	float getPrice() {
		return this->price;
	}

	bool isValid() {
		return this->isValid;
	}

	Ticket(string ticketType, float price)
		:ticketType(ticketType), price(price) {
		for (int i = 0; i < 12; i++) {
			this->ticketsSoldPerMonth[i] = 0;
		}
		this->currentMonth = 0;
	}

	int getMonthData(int monthIndex) {
		return this->ticketsSoldPerMonth[monthIndex];
	}



};

