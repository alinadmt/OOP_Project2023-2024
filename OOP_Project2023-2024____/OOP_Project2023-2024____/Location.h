#pragma once
#include <iostream>
#include <string>
using namespace std;


class Location {
private:
	const int noSeats=1000;
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
		int* copy = new int[this->noSeats];
		for (int i = 0; i < this->noSeats; i++) {
			copy[i] = this->seatsPerRow[i];
		}
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
	
	}

	//ctor with parameters

	Location(int seats, int rows, int zones, int totalSeats, const string& name)
		: noSeats(seats), noRows(rows), noZones(zones), noOfTotalSeats(totalSeats), locationName(name) {
		seatsPerRow = new int[noRows];
		for (int i = 0; i < noRows; ++i) {
			seatsPerRow[i] = noSeats;
		}
	}

	// Destructor
	~Location() {
		cout << endl << "Destructor";
		delete[] seatsPerRow;
	}


};