#include "Victim.hpp"

Victim::Victim(const std::string &name) : Civilian(name) {
	// Victim constructor
	this->treated = false;
	this->treatedAmount = 0;
}

bool Victim::isTreated(){
	// Return whether the victim is treated
	return this->treated;
}

int Victim::getTreatedByAmount(){
	// Return the treated amount
	return this->treatedAmount;
}

void Victim::setTreated(bool treated) {
	// Set the victim's treated bool to the input
	this->treated = treated;
}

void Victim::setTreatedAmount(int amount) {
	// Set the victim's treated amount int to the input
	this->treatedAmount = amount;
}

Victim::~Victim() {
	// Destructor
}

