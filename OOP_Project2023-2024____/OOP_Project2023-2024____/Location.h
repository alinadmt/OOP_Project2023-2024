#pragma once
#include <iostream>
#include <string>
using namespace std;


class Location {
private:
	const int noSeats = 0;
	int noRows = 0;
	int noZones = 0;
	int* seatsPerRow = nullptr;
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

	string getLocationName() {
		return this->locationName;
	}

};