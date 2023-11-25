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
		for (int i = 0; i < 12; ++i) {
			this->ticketsSoldPerMonth[i] = 0;
		}
		this->ticketsSoldPerMonth[0] = 12;
		this->ticketID = 0;
		this->ticketType = "";
		this->row = 0;
		this->seatNo = 0;
		this->price = 0.0;
	}

	//ctor with parameters
	Ticket(int id, const string& type, int rowNum, int seatNum, float ticketPrice, bool valid, const int* soldPerMonth, int month)
		: ticketID(id), ticketType(type), row(rowNum), seatNo(seatNum), price(ticketPrice), isValid(valid), currentMonth(month) {
		for (int i = 0; i < 12; ++i) {
			ticketsSoldPerMonth[i] = soldPerMonth[i];
		}
	}

	friend ostream& operator<<(ostream& os, const Ticket& ticket) {
		os << "Ticket ID: " << ticket.ticketID << "\n";
		os << "Ticket type: " << ticket.ticketType << "\n";
		os << "Ticket Row: " << ticket.row << "\n";
		os << "Ticket Seat Number: " << ticket.seatNo << "\n";
		os << "Ticket price: " << ticket.price<< "\n";
		os << "is Valid: " << ticket.isValid<< "\n";
		os << "Tickets sold per mont: " << ticket.ticketsSoldPerMonth << "\n";
		os << "Current month: " << ticket.currentMonth << "\n";
		return os;
	}

	friend istream& operator>>(istream& is, Ticket& ticket) {
		cout << "Enter Ticket ID: ";
		is >> ticket.ticketID;

		cout << "Enter ticket type: ";
		is >> ticket.ticketType;

		cout << "Enter ticket row: ";
		is >> ticket.row;

		cout << "Enter the seat number: ";
		is >> ticket.seatNo;

		cout << "The price is: ";
		is >> ticket.price;

		cout << "Ticket availability: ";
		is >> ticket.isValid;
		
		cout << "Enter tickets sold per month (space-separated): ";
		for (int i = 0; i < 12; ++i) {
			is >> ticket.ticketsSoldPerMonth[i];
		}
		cout << "Enter current month (1-12): ";
		is >> ticket.currentMonth;

		return is;
	}

	// Overload ++ (prefix)
	Ticket& operator++() {
		if (!isValid) {
			++Ticket::ticketsSoldPerMonth[currentMonth];
			++ticketID;
		}
		return *this;
	}

	//Overload -- (prefix)
	Ticket& operator--() {
		if (isValid && ticketsSoldPerMonth[currentMonth] > 0) {
			--Ticket::ticketsSoldPerMonth[currentMonth];
		}
		return *this;
	}

	//index operator
	int& operator[](int index) {
		if (index < 0 || index > 11) {
			throw exception("Wrong month index");
		}
		return this->ticketsSoldPerMonth[index];
	}

	//>=
	bool operator >= (Ticket ticket) {
		if (this->price >= ticket.price) {
			return true;
		}
		else {
			return false;
		}
	}

	//Operator =

	Ticket& operator=(const Ticket& other) {
		if (this != &other) {
			delete[] ticketsSoldPerMonth;
		}
		ticketID = other.ticketID;
		ticketType = other.ticketType;
		row = other.row;
		seatNo = other.seatNo;
		price = other.price;
		isValid = other.isValid;
		for (int i = 0; i < 12; ++i) {
			ticketsSoldPerMonth[i] = other.ticketsSoldPerMonth[i];
		}
		currentMonth = other.currentMonth;

		return *this;

	}

	float calculateMeanTicketsSoldPerMonth() {
		int totalTicketsSold = 0;
		for (int i = 0; i < 12; ++i) {
			totalTicketsSold += ticketsSoldPerMonth[i];
		}
		if (totalTicketsSold > 0) {
			return totalTicketsSold / 12.0f;
		}
		else {
			return 0.0f;
		}
	}


	void calcTicketVAT(float& priceWithVAT, float& priceWithoutVAT) const {
		float vatRate = 0.19;
		priceWithVAT = price * (1 + vatRate);
		priceWithoutVAT = price;
	
	}

	// Destructor
	~Ticket() {
		cout << endl << "Destructor:";
	}
};


