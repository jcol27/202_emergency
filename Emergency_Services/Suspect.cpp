#include "Suspect.hpp"

Suspect::Suspect(const std::string &name) : Civilian(name) {
	// Suspect constructor
	this->caught = false;
	this->caughtAmount = 0;
}

bool Suspect::isCaught(){
	// Returns whether the suspect is caught
	return this->caught;
}

int Suspect::getCaughtByAmount(){
	// Returns how many times the suspect has been caught
	return this->caughtAmount;
}

void Suspect::setCaught() {
	// Sets the suspect's caught variable to the input
	this->caught = true;
}

void Suspect::setCaughtAmount(int amount) {
	// Sets the suspect's caught amount to the input
	this->caughtAmount = amount;
}

Suspect::~Suspect() {
	// Destructor
}

