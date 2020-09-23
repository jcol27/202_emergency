#include "FireFighter.hpp"

FireFighter::FireFighter(const std::string &name) : Staff(name) {
	// Firefighter constructor
	this->name = name;
	this->complete = false;
	this->type = FIREFIGHTER;
}

void FireFighter::performJob() {
	// Method to perform the firefighters job (has no job, so just sets to
	// complete)
	this->complete = true;
}

FireFighter::~FireFighter() {
	// Destructor
}

