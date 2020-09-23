#include "Staff.hpp"

int Staff::nextID = 0;

Staff::Staff(const std::string &name) : Human(name) {
	// Staff constructor
	// TODO fix this shit
	//this->complete = false;
	this->ID = nextID++;
	this->assigned = false;
	this->address = NULL;
	this->type = STAFF;
	this->complete = false;
}

void Staff::performJob(){
	// Virtual method to perform job, overwritten in derived classes
	this->complete = true;
}

bool Staff::isJobComplete() {
	// Return whether or not the  staff member has completed their job
	return this->complete;
}

Address* Staff::getAddress() {
	// Return the address the staff is assigned to
	return this->address;
}

void Staff::setAddress(Address* address) {
	// Set the address the staff is assigned to
	this->address = address;
}

Type Staff::getType() {
	// Return the type of the staff member:
	// STAFF, POLICEOFFICER, PARAMEDIC, FIREFIGHTER
	return this->type;
}

void Staff::setAssigned(bool assigned){
	// Set whether or not the staff member is assigned to an emergency
	this->assigned = assigned;
}

void Staff::setComplete(){
	// Sets the staff member to have completed their task
	this->complete = true;
}

bool Staff::isAssigned(){
	// Return whether or not the staff member is assigned to an emergency
	return this->assigned;
}

int Staff::getID(){
	// Return the staff member's ID
	return this->ID;
}

Staff::~Staff() {
	// Destructor
}

