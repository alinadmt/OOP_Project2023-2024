#pragma once
#include <iostream>
#include <string>
using namespace std;


class Location {
private:
	const int noSeats=1;
	int noRows = 0;
	int noZones = 0;
	int* seatsPerRow = nullptr;
	int noOfTotalSeats = 0;
	string locationName = "";

public:

	//getters

	int getNoSeats() {
		return this->noSeats;
	}

	int getNoRows() {
		return this->noRows;
	}

	int getNoZones() {
		return this->noZones;
	}

	int* getSeatsPerRow() {
		int* copy = new int[noSeats];
		memcpy(copy, seatsPerRow, sizeof(int) * noSeats);
		return copy;
		}

	int getNoOfTotalSeats() {
		return this->noOfTotalSeats;
	}

	string getLocationName() {
		return this->locationName;
	}

	//setters

	void setNoSeats(int noSeats) {
		if (noSeats < 0 || noSeats>500) {
			throw exception("No of seats must be positive and less than or equal to 500.");
		}
	}

	void setNoRows(int noRows) {
		if (noRows <= 0) {
			throw exception("No. of rows cannot be negative!");
		}
		this->noRows = noRows;
	}

	void setNoZones(int noZones) {
		if (noZones <= 0 and noZones>=6) {
			throw exception("No. of zones cannot be negative and must be max 5!");
		}
		this->noZones = noZones;
	}

	void setNoSeatsPerRow(int* someSeats, int noOfSeats) {
		if (someSeats == nullptr) {
			throw exception("No grades");
		}
		if (this->seatsPerRow != nullptr) {
			delete[] this->seatsPerRow;
		}
		this->seatsPerRow = new int[noOfSeats];
		for (int i = 0; i < noOfSeats; i++) {
			this->seatsPerRow[i] = someSeats[i];
		}
		this->noOfTotalSeats = noOfSeats;
	}

	void setNoOfTotalSeats(int noOfTotalSeats) {
		if (noOfTotalSeats <= 0) {
			throw exception("Seats cannot be innexistent");
		}
	}

	void setLocationName(string newName) {
			if (newName.size() < 2 || newName.empty() ) {
				throw exception("The name is too short!");
			}
			this->locationName = newName;
		}
	
	//default ctor

	Location() {
		delete[] this->seatsPerRow;
		this->seatsPerRow=new int[1];
		this->seatsPerRow[0] = 10;
		this->noRows = 0;
		this->noZones = 0;
		this->noOfTotalSeats = 0;
		this->locationName = "";
	
	}

	//ctor with parameters

	Location(int seats, int rows, int zones, int totalSeats, const string& name)
		: noSeats(seats), noRows(rows), noZones(zones), noOfTotalSeats(totalSeats), locationName(name) {
		seatsPerRow = new int[noRows];
		for (int i = 0; i < noRows; ++i) {
			seatsPerRow[i] = noSeats;
		}
	}

	friend ostream& operator<<(ostream& os, const Location& location) {
		os << "No of seats: " << location.noSeats << "\n";
		os << "No of rows: " << location.noRows << "\n";
		os << "No of zones: " << location.noZones << "\n";
		os << "No of seats per row: " << location.seatsPerRow << "\n";
		os << "No of total seats: " << location.noOfTotalSeats << "\n";
		os << "Location name is: " << location.locationName << "\n";
		return os;
	}

	// Overload >> (input)
	friend istream& operator>>(istream& is, Location& location) {

		cout << "Enter the number of rows: ";
		is >> location.noRows;

		cout << "Enter the number of zones: ";
		is >> location.noZones;

		int size;
		cout << "Enter the number of seats per row: ";
		is >> size;
		location.seatsPerRow = new int[size];
		cout << "Enter the seats per row (space-separated): ";
		for (int i = 0; i < size; ++i) {
			is >> location.seatsPerRow[i];
		}

		cout << "Enter the number of total seats: ";
		is >> location.noOfTotalSeats;

		cout << "Enter the name of the location: ";
		is >> location.locationName;

		return is;
	}

	Location& operator++() {
		if (Location::noRows < noOfTotalSeats) {
			++Location::noRows;
		}
		return *this;
	}

	// Overload + (addition)
	Location& operator+(int noZones) {
		if (Location::noRows * noZones <= noOfTotalSeats) {
			Location::noRows += noZones;
		}
		return *this;
	}

	// Overload - (subtraction)
	Location& operator-(int numTickets) {
		if (Location::noRows - noZones >= 0) {
			Location::noRows -= noZones;
		}
		return *this;
	}

	Location& operator=(const Location& other) {
		if (this != &other) {
			delete[] seatsPerRow;
		}
		noRows = other.noRows;
		noZones = other.noZones;
		seatsPerRow = new int[noSeats];
		memcpy(seatsPerRow, other.seatsPerRow, sizeof(int) * noSeats);
		noOfTotalSeats = other.noOfTotalSeats;
		locationName = other.locationName;

		return *this;
	}

	//method to add a seat per row
	void addSeat(int seat) {
		int* newArray = new int[this->noOfTotalSeats + 1];                     
		for (int i = 0; i < this->noOfTotalSeats; i++) {
			newArray[i] = this->seatsPerRow[i];
		}
		newArray[this->noOfTotalSeats] = seat;               
		this->noOfTotalSeats += 1;                           
		if (this->seatsPerRow != nullptr) {           
			delete[] this->seatsPerRow;
		}
		this->seatsPerRow = newArray;
	}

	//print method
	void print() {
		cout << endl << "Seats for " << this->locationName << ": ";
		for (int i = 0; i < this->noOfTotalSeats; i++) {
			cout << this->seatsPerRow[i] << " ";
		}
	}


	string getName() {
		return this->locationName;
	}

	int getNoGrades() {
		return this->noOfTotalSeats;
	}


	// Destructor
	~Location() {
		cout << endl << "Destructor";
		delete[] seatsPerRow;
	}


};