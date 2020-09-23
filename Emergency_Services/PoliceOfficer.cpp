#include "PoliceOfficer.hpp"

PoliceOfficer::PoliceOfficer(const std::string &name) : Staff(name) {
	// Police officer constructor
	this->suspect = 0;
	//void performJob();
	this->type = POLICEOFFICER;
}

void PoliceOfficer::assignSuspect(Suspect* suspect){
	// Assign the officer a suspect
	this->suspect = suspect;
}

Suspect* PoliceOfficer::getAssignedSuspect() {
	// Return the officer's assigned suspect
	return this->suspect;
}

void PoliceOfficer::performJob() {
	// Perform the officer's job
	// Set the suspect's caught bool to true, increment the caught amount,
	// and set the officer's complete bool to true
	this->getAssignedSuspect()->setCaught();
	this->suspect->setCaughtAmount(suspect->getCaughtByAmount() + 1);
	this->complete = true;
}

PoliceOfficer::~PoliceOfficer(){
	// Destructor

}
