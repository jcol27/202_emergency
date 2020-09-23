#include "EmergencyServicesSystem.hpp"
#include <iostream>
#include <vector>

EmergencyServicesSystem::EmergencyServicesSystem() {
	// Emergency Services System Constructor
	this->staffCount = 0;
	this->policeCount = 0;
	this->paramedicCount = 0;
	this->firefighterCount = 0;
	this->emergencies = {};
	this->police = {};
	this->paramedics = {};
	this->firefighters = {};
	this->vehicles = {};
}

std::string EmergencyServicesSystem::author(){
	// Method to return the upi of the author
	return "jcol704";
}

bool EmergencyServicesSystem::addEmergency(Emergency* emergency) {
	// Method to add the emergency to the system, and return true if successful

	// Check if the emergency already exists ie the input emergency has the same
	// address as an emergency in the emergencies vector
	for (unsigned int i = 0; i < emergencies.size(); i++) {
		Address* address1 = emergencies[i]->getAddress();
		Address* address2 = emergency->getAddress();

		// If the addresses are the same, return false
		if (address1->getNumber() == address2->getNumber()
				&& address1->getPostcode() == address2->getPostcode()
				&& address1->getStreet() == address2->getStreet()
				&& address1->getSuburb() == address2->getSuburb()) {
			return false;
		}
	}

	// If false has not been returned, this code will execute, adding the input
	// emergency to the list of emergencies and returning true
	emergencies.push_back(emergency);
	return true;
}

int EmergencyServicesSystem::getStaffCount() {
	// Method to return the staff count of the system
	return this->staffCount;
}

int EmergencyServicesSystem::getpoliceCount() {
	// Method to return the number of police in the system
	return this->policeCount;
}

int EmergencyServicesSystem::getparamedicCount() {
	// Method to return the number of paramedics in the system
	return this->paramedicCount;
}

int EmergencyServicesSystem::getfirefighterCount() {
	// Method to return the number of firefighters in the system
	return this->firefighterCount;
}

void EmergencyServicesSystem::hirePoliceOfficer(PoliceOfficer* policeOfficer) {
	// Method to hire a police officer to the system
	police.push_back(policeOfficer);
	this->staffCount++;
}

void EmergencyServicesSystem::hireParamedic(Paramedic* paramedic) {
	// Method to hire a paramedic to the system
	paramedics.push_back(paramedic);
	this->staffCount++;
}

void EmergencyServicesSystem::hireFireFighter(FireFighter* fireFighter) {
	// Method to hire a firefighter to the system
	firefighters.push_back(fireFighter);
	this->staffCount++;
}

void EmergencyServicesSystem::buyVehicle(Vehicle* vehicle) {
	// Method to add a vehicle to the system
	vehicles.push_back(vehicle);
}

bool EmergencyServicesSystem::assignStaffToEmergency(Address* address,
		int numpoliceOfficers, int numParamedics, int numFireFighters) {
	// Method to assign a given number of each type of staff to the emergency at
	// the input address, and return true if successful

	bool exists; // If the emergency exists
	int position; // the position of the emergency in the emergencies vector

	// Loop to check if there is an emergency at the input address
	for (unsigned int i = 0; i < emergencies.size(); i++) {
		Address* address1 = emergencies[i]->getAddress();

		// If the addresses are the same, return false
		if (address1->getNumber() == address->getNumber()
				&& address1->getPostcode() == address->getPostcode()
				&& address1->getStreet() == address->getStreet()
				&& address1->getSuburb() == address->getSuburb()) {
			exists = true;
			position = i;
		}
	}

	// If there is an emergency at the given address and there is enough of each
	// type of staff in the system, then proceed with the assignment
	if (exists && numpoliceOfficers <= int(police.size())
			&& numParamedics <= int(paramedics.size())
			&& numFireFighters <= int(firefighters.size())) {

		// Add the police officers
		for (int j = 0; j < numpoliceOfficers; j++) {
			// Loop through staff vector
			for (unsigned int k = 0; k < police.size(); k++) {
				// Change the staff's address and assigned bool, move the staff
				// object from the staff vector to the assigned staff vector
				police[k]->setAddress(address);
				police[k]->setAssigned(true);
				police[k]->assignSuspect(emergencies[position]->getSuspect());
				emergencies[position]->assignStaff(police[k]);
				//police.erase(police.begin() + k);
			}
		}

		// Add the paramedics
		for (int j = 0; j < numParamedics; j++) {
			// Loop through staff vector
			for (unsigned int k = 0; k < paramedics.size(); k++) {
				// Change the staff's address and assigned bool, move the staff
				// object from the staff vector to the assigned staff vector
				paramedics[k]->setAddress(address);
				paramedics[k]->setAssigned(true);
				paramedics[k]->assignVictim(emergencies[position]->getVictim());
				emergencies[position]->assignStaff(paramedics[k]);
				//paramedics.erase(paramedics.begin() + k);
			}
		}

		// Add the firefighters
		for (int j = 0; j < numFireFighters; j++) {
			// Loop through staff vector
			for (unsigned int k = 0; k < firefighters.size(); k++) {
				// Change the staff's address and assigned bool, move the staff
				// object from the staff vector to the assigned staff vector
				firefighters[k]->setAddress(address);
				firefighters[k]->setAssigned(true);
				emergencies[position]->assignStaff(firefighters[k]);
				//firefighters.erase(firefighters.begin() + k);
			}
		}

		// Change the status of the emergency to assigned, and set the number of
		// assigned staff of the emergency
		emergencies[position]->setStatus(ASSIGNED);

		return true;
	}
	else {
		return false;
	}
}

bool EmergencyServicesSystem::transportStaff(Address* address) {
	// Method to transport the staff in the system to the emergency at the given
	// address

	bool transported = false; // if the emergency exists
	int capacity = 0; // capacity of all the vehicles

	// Loop through the vehicles vector to find the total available capacity
	for (unsigned int i = 0; i < vehicles.size(); i++) {
		capacity = capacity + vehicles[i]->getCapacity();
	}

	// Loop through emergencies vector to find the emergency at the given address
	for (unsigned int i = 0; i < emergencies.size(); i++) {
		// If the emergency exists and has assigned staff greater than zero but less
		// than the vehicle capacity, do the transport
		Address* address1 = emergencies[i]->getAddress();
		if (address1->getNumber() == address->getNumber()
				&& address1->getPostcode() == address->getPostcode()
				&& address1->getStreet() == address->getStreet()
				&& address1->getSuburb() == address->getSuburb()) {
			if (int(emergencies[i]->getAssignedStaff().size()) > 0
					&& capacity >= int(emergencies[i]->getAssignedStaff().size())) {
				transported = true;
				emergencies[i]->setStatus(TRANSPORTED);
			}
		}
	}
	return transported;
}

bool EmergencyServicesSystem::resolveEmergency(Address* address) {
	// Method to resolve the emergency at the given address

	bool resolved = false;

	// Loop through emergencies vector to find the emergency at the given address
	for (unsigned int i = 0; i < emergencies.size(); i++) {
		// If the emergency exists and has the TRANSPORTED status, resolve it

		if (emergencies[i]->getAddress() == address
				&& emergencies[i]->getStatus() == TRANSPORTED) {
			emergencies[i]->resolve();
			resolved = true;
		}
	}
	return resolved;
}

EmergencyServicesSystem::~EmergencyServicesSystem(){
	//TODO Implement destructor
	for (unsigned int i = 0; i < vehicles.size(); i++) {
		delete vehicles[i];
	}
	for (unsigned int i = 0; i < police.size(); i++) {
		delete police[i];
	}
	for (unsigned int i = 0; i < paramedics.size(); i++) {
		delete paramedics[i];
	}
	for (unsigned int i = 0; i < firefighters.size(); i++) {
		delete firefighters[i];
	}
	for (unsigned int i = 0; i < emergencies.size(); i++) {
		delete emergencies[i];
	}
}

