#pragma once
#include <iostream>
#include <string>
using namespace std;


enum class EventType { CONCERT, FOOTBALL, THEATER, CONFERENCE, WEBINAR, MOVIE, STANDUP };


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
	char* eventName = nullptr;
	char date[100] = "";
	string eventTime = "";
	int maxTickets = 0;
	static int ticketsSold;
	EventType eventType;
	int eventID = 0;

public:

	static int const MIN_SIZE_FOR_EVENT_NAME = 2;

	//getters
	char* getEventName() {
		char* eventName = new char[strlen(this->eventName) + 1];
		for (int i = 0; i < strlen(this->eventName); i++) {
			eventName[i] = this->eventName[i];
		}
		eventName[strlen(this->eventName)] = '\0';

		return eventName;
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

	void setEventName(const char* eventName) {
		if (eventName == nullptr) {
			throw "Invalid event name";
		}
		if (this->eventName != nullptr) {
			delete[] this->eventName;
		}
		this->eventName = new char[strlen(eventName) + 1];
		for (int i = 0; i < strlen(eventName) + 1; i++) {
			this->eventName[i] = eventName[i];
		}
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


	void setEventID(int eventID) {
		if (eventID < 0) {
			throw exception("ID should be positive!");
		}
		this->eventID = eventID;
	}

	//default ctor + random generated id
	Event():eventType(EventType::CONCERT) {

		delete[] this->eventName;
		this->eventName=new char[7];

		strcpy_s(this->eventName, 7, "noname");
		strcpy_s(this->date, 11, "01/01/1970");
		this->eventTime = "";
		this->maxTickets = 0;
		time_t current_time = time(NULL);
		this->eventID = current_time;
	}

	//ctor with parameters
	Event(const char* eventName, const char* eventDate, const string& timeee, int maxTix, EventType type)
		: maxTickets(maxTix), eventType(type) {

		if (eventName == nullptr) {
			throw "Invalid event name";
		}
		if (this->eventName != nullptr) {
			delete[] this->eventName;
		}
		this->eventName = new char[strlen(eventName) + 1];
		for (int i = 0; i < strlen(eventName) + 1; i++) {
			this->eventName[i] = eventName[i];
		}

		if (strlen(eventDate) != 10) {                         		
			throw exception("Wrong date");
		}
		if (eventDate[2] != '/' || eventDate[5] != '/') {
			throw exception("Wrong date format");
		}
		strcpy_s(date, eventDate);

		time_t current_time = time(NULL);
		this->eventID = current_time;
		
		if (timeee.empty()) {                                       
			throw exception("Time cannot be empty!");
		}
		eventTime = timeee;
	}

	friend ostream& operator<<(ostream& os, const Event& event) {
		os << "Event Name: " << event.eventName << "\n";
		os << "Event Date: " << event.date << "\n";
		os << "Event Time: " << event.eventTime << "\n";
		os << "Max Tickets: " << event.maxTickets << "\n";
		os << "Tickets Sold: " << Event::ticketsSold << "\n";
		os << "Event Type: " << Util::typeToString(event.eventType) << "\n";
		os << "Event ID: " << event.eventID << "\n";
		return os;
	}

	// Overload >> (input)
	friend istream& operator>>(istream& is, Event& event) {
		cout << "Enter Event Name: ";
		char buffer[100];
		is >> buffer;
		event.setEventName(buffer);

		cout << "Enter Event Date (format: MM/DD/YYYY): ";
		is >> buffer;
		event.setDate(buffer);

		cout << "Enter Event Time: ";
		is >> event.eventTime;

		cout << "Enter Max Tickets: ";
		is >> event.maxTickets;

		int typeInt;
		cout << "Enter Event Type (0 for CONCERT, 1 for FOOTBALL, etc.): ";
		is >> typeInt;
		event.setEventType(static_cast<EventType>(typeInt));

		time_t current_time = time(nullptr);
		event.setEventID(static_cast<int>(current_time));

		return is;
	}

	// Overload ++ (prefix)
	Event& operator++() {
		if (Event::ticketsSold < maxTickets) {
			++Event::ticketsSold;
		}
		return *this;
	}

	// Overload -- (prefix)
	Event& operator--() {
		if (Event::ticketsSold > 0) {
			--Event::ticketsSold;
		}
		return *this;
	}

	// Overload + (addition)
	Event& operator+(int numTickets) {
		if (Event::ticketsSold + numTickets <= maxTickets) {
			Event::ticketsSold += numTickets;
		}
		return *this;
	}

	// Overload - (subtraction)
	Event& operator-(int numTickets) {
		if (Event::ticketsSold - numTickets >= 0) {
			Event::ticketsSold -= numTickets;
		}
		return *this;
	}

	Event& operator=(const Event& other) {
		if (this != &other) {
			delete[] eventName;
		}
			eventName = Util::copyString(other.eventName);
			strcpy_s(date, other.date);
			eventTime = other.eventTime;
			maxTickets = other.maxTickets;
			eventType = other.eventType;
			eventID = other.eventID;

			return *this;
		}


	//tickets left method
	void ticketsRemained(int ticketsSold) {
		if (ticketsSold < maxTickets) {
			cout<<"This is the number of unsold tickets: "<<(maxTickets - ticketsSold);
		}
		else if (ticketsSold == maxTickets) {
			cout<< "No more tickets available";
		}
		else  {
			cout << "Error! Tickets sold must be <= Max no of tickets";
		}

	}


	//destructor
	~Event() {
		cout << endl << "Destructor";
		delete[] Util::copyString(date);
		delete[] eventName;
	}

};

int Event::ticketsSold = 0;






