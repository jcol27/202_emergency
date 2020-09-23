#include "Paramedic.hpp"

Paramedic::Paramedic(const std::string &name) : Staff(name) {
	// Paramedic constructor
	this->victim = NULL;
	this->type = PARAMEDIC;
}

void Paramedic::assignVictim(Victim* victim) {
// Assign the victim object to the paramedic
	this->victim = victim;

}

Victim* Paramedic::getAssignedVictim() {
// Returns the assigned victim object
	return this->victim;
}

void Paramedic::performJob() {
	// Treat the victim, change the victim's treated amount, set the
	// paramedic's completed bool to true
	victim->setTreated(true);
	victim->setTreatedAmount(victim->getTreatedByAmount() + 1);
	this->complete = true;
}

Paramedic::~Paramedic(){
	// Destructor

}
