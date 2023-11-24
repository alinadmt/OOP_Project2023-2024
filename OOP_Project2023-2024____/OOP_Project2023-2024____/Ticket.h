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
	float price = 0;
	bool isValid;
	int ticketsSoldPerMonth[12];
	int currentMonth = 0;

public:

	bool isTicketIDUnique(int id) const {
		return true;
	}

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

	bool getisValid() {
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

	//setters
	
	void setTicketID(int id) {
		if (id <= 0 || id > 1000 || !isTicketIDUnique(id)) {
			throw exception("Ticket ID must be positive, should not exceed 1000 and must be unique.");
		}
		this->ticketID = id;
	}

	void setTicketType(string type) {
		if (type.empty()) {
			throw exception("Ticket type cannot be empty. Please provide a valid ticket type.");
		}
		this->ticketType = type;
	}

	void setRow(int row) {
		if (row < 1) {
			throw exception("Row number must be greater than or equal to 1.");
		}
		this->row = row;
	}

	void setSeatNo(int no) {
		if (no < 1 || no>99) {
			throw exception("Row number must be greater than or equal to 1 and less than or equal to 99.");
		}
		this->seatNo = no;;
	}

	void setPrice(float newPrice) {
		if (newPrice < 5.0 || newPrice > 1000.0) {
			throw exception("Price should be in the range 5 lei to 1000 lei");
		}
		this->price = newPrice;
	}

	void setIsValid(bool newIsValid) {
		isValid = newIsValid;
	}

	void setTicketsSoldPerMonth(int monthIndex, int ticketsSold) {
		if (monthIndex < 0 || monthIndex >= 12) {
			throw exception("Month index should be in the range 0 to 11.");
		}

		if (ticketsSold < 0) {
			throw exception("Number of tickets sold cannot be negative.");
		}
		this->ticketsSoldPerMonth[monthIndex] = ticketsSold;
	}

	void setCurrentMonth(int newMonth) {
		if (newMonth < 1 || newMonth > 12) {
			throw std::out_of_range("Month should be in the range 1 to 12.");
		}
		this->currentMonth = newMonth;
	}

	//default ctor
	Ticket() {

	}

	//ctor with parameters
	Ticket(int id, const string& type, int rowNum, int seatNum, float ticketPrice, bool valid, const int* soldPerMonth, int month)
		: ticketID(id), ticketType(type), row(rowNum), seatNo(seatNum), price(ticketPrice), isValid(valid), currentMonth(month) {
		for (int i = 0; i < 12; ++i) {
			ticketsSoldPerMonth[i] = soldPerMonth[i];
		}
	}

	// Destructor
	~Ticket() {
		cout << endl << "Destructor:";
	}
};


