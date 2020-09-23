#include "Vehicle.hpp"

Vehicle::Vehicle(const std::string &name, int capacity) {
	// Vehicle object constructor
	this->name = name;
	this->capacity = capacity;
}

int Vehicle::getCapacity(){
	// Method to return the vehicle capacity
	return this->capacity;
}

std::string Vehicle::getName(){
	// Method to return the vehicle name
	return this->name;
}

Vehicle::~Vehicle() {
	// Destructor
}

