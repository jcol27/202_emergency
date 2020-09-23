#include "Human.hpp"
#include <string>

Human::Human(const std::string &name) {
	// Human constructor
	this->name = name;
}

std::string Human::getName(){
	// Method to return the Human's name
	return this->name;
}

Human::~Human() {
	// Destructor
}

