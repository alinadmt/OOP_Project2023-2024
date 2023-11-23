#pragma once
#include <iostream>
#include <string>
using namespace std;


enum class EventType{CONCERT, FOOTBALL, THEATER, CONFERENCE, WEBINAR, MOVIE, STANDUP};


class Util {
public:
	static char* copyString(const char* source) {
		if (source == nullptr) {
			return nullptr;
		}
		char* value = new char[strlen(source) + 1];
		strcpy_s(value, strlen(source) + 1, source);
		return value;
	}

	static string typeToString(EventType eventType) {
		switch (eventType) {
		case EventType::CONCERT:
			return "Concert ticket";
		case EventType::FOOTBALL:
			return "Football ticket";
		case EventType::THEATER:
			return "Theater ticket";
		case EventType::CONFERENCE:
			return "Conference ticket";
		case EventType::WEBINAR:
			return "Webinar ticket";
		case EventType::MOVIE:
			return "Movie ticket";
		case EventType::STANDUP:
			return "Stand-up ticket";
		default:
			throw exception("Type not covered");
		}

	}
};

class Event {
private:
	string eventName = "";
	char date[11] = "";
	string eventTime = "";
	int maxTickets = 0;
	static int ticketsSold;
	EventType eventType;
	int eventID = 0;

public:

	static int const MIN_SIZE_FOR_EVENT_NAME = 2;

	//getters
	string getEventName() {
		return this->eventName;
	}

	char* getDate() {
		return Util::copyString(this->date);
	}


	string getEventTime() {
		return this->eventTime;
	}

	EventType getEventType() {
		return this->eventType;
	}

	int getMaxTickets() {
		return this->maxTickets;
	}

	static int getTicketsSold() {
		return Event::ticketsSold;
	}

	int getEventId() {
		return this->eventID;
	}

	//setters

	void setEventName(string newName) {
		if (newName.size() < Event::MIN_SIZE_FOR_EVENT_NAME) {
			throw exception("The name is too short!");
		}
		this->eventName = newName;
	}

	void setDate(const char* newDate) {
		if (strlen(newDate) != 10) {
			throw exception("Wrong date");
		}
		if (newDate[2] != '/' || newDate[5] != '/') {
			throw exception("Wrong date format");
		}

		strcpy_s(this->date, newDate);
	}

	void setEventTime(string newTime) {
		if (newTime.empty()) {
			throw exception("Time cannot be empty!");
		}
		this->eventTime = newTime;
	}

	void setEventType(EventType eventType) {
		this->eventType = eventType;
	}

	void setMaxTickets(int maxTickets) {
		if (maxTickets <= 0) {
			throw exception("No. of tickets cannot be negative!");
		}
		this->maxTickets = maxTickets;
	}

	//setter ticketsSold:





	void setEventID(int eventID) {
		if (eventID < 0) {
			throw exception("ID should be positive!");
		}
		this->eventID = eventID;
	}

	//default ctor
	Event() :eventName("No name"), eventTime(00), maxTickets(9999), eventID(1), eventType(EventType::MOVIE) {
		this->setDate("00/00/0000");
		//this->setTicketsSold(0);
		Event::ticketsSold += 1;
	}

	//destructor
	~Event() {
		delete[] this->date;
		Event::ticketsSold -= 1;
	}


};

