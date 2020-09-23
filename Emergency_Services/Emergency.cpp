#include "Emergency.hpp"

Emergency::Emergency(Address* address, Victim* victim, Suspect* suspect ) {
	// Emergency Constructor
	this->address = address;
	this->victim = victim;
	this->suspect = suspect;
	this->status = CRITICAL;
	this->assignedStaffCount = 0;
	this->assignedStaff = {};
}

Address* Emergency::getAddress(){
	// Method to return the address (object) of the emergency
	return this->address;
}

Suspect* Emergency::getSuspect(){
	// Method to return the suspect (object) of the emergency
	return this->suspect;
}

int Emergency::getAssignedStaffCount() {
	// Method to return the assigned staff count
	return this->assignedStaffCount;
}

Victim* Emergency::getVictim(){
	// Method to return the victim (object) of the emergency
	return this->victim;
}

Status Emergency::getStatus(){
	// Method to return the status of the emergency
	return this->status;
}

void Emergency::setStatus(Status status){
	// Method to set the status of the emergency
	this->status = status;
}

std::vector<Staff*> Emergency::getAssignedStaff(){
	// Method to return the vector of assigned staff
	return this->assignedStaff;
}

void Emergency::assignStaff(Staff *staff){
	// Method to assign staff to the emergency

	// Check method has correct status
	if (this->getStatus() == CRITICAL || this->getStatus() == ASSIGNED) {

		// Add staff to assigned, set assigned to true, change emergency status
		this->assignedStaff.push_back(staff);
		staff->setAssigned(true);
		this->status = ASSIGNED;
	}

}

void Emergency::setAssignedStaffCount(int newCount) {
	// Method to set the assigned staff count
	this->assignedStaffCount = newCount;
}

bool Emergency::resolve(){
	// Method to resolve the emergency and return true if resolved, false if
	// there are no assigned staff

	// Check if emergency is already resolved
	if (this->status == COMPLETED) {
		return true;
	}
	// Check false condition, if there is no assigned staff
	else if (assignedStaff.size() == 0) {
		return false;
	}
	else {
		// Loop through assigned staff, each performs their job
		for (unsigned int i=0; i < this->assignedStaff.size(); i++) {
			this->assignedStaff[i]->performJob();
			this->assignedStaff[i]->setComplete();
		}
		this->status = COMPLETED;
		return true;
	}
}

Emergency::~Emergency() {
	delete victim;
	delete address;
	delete suspect;
}

