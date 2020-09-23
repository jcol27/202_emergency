#include <vector>
#include <iostream>
#include "PoliceOfficer.hpp"
#include "FireFighter.hpp"
#include "Paramedic.hpp"
#include "Emergency.hpp"
#include "Vehicle.hpp"

#ifndef EMERGENCYSERVICESSYSTEM_HPP_
#define EMERGENCYSERVICESSYSTEM_HPP_

class EmergencyServicesSystem {
	// This class creates an emergency services system, with an emergency and
	// staff and vehicles to handle the emergency
private:
	// Variables
	std::vector<Emergency*> emergencies;
    std::vector<PoliceOfficer*> police;
    std::vector<Paramedic*> paramedics;
    std::vector<FireFighter*> firefighters;
    std::vector<Vehicle*> vehicles;

    int staffCount;
	int policeCount;
	int paramedicCount;
	int firefighterCount;
public:
	// Constructor
	EmergencyServicesSystem();

	// General methods
	static std::string author();
	void hirePoliceOfficer(PoliceOfficer* policeOfficer);
	void hireParamedic(Paramedic* paramedic);
	void hireFireFighter(FireFighter* fireFighter);
	void buyVehicle(Vehicle* vehicle);

	bool addEmergency(Emergency* emergency);
	bool assignStaffToEmergency(Address* address, int numPoliceOfficers,
			int numParamedics, int numFireFighters);
	bool transportStaff(Address* address);
	bool resolveEmergency(Address* address);

	// Getter methods
	int getStaffCount();
	int getpoliceCount();
	int getparamedicCount();
	int getfirefighterCount();

	// Destructor
	virtual ~EmergencyServicesSystem();
};

#endif /* EMERGENCYSERVICESSYSTEM_HPP_ */
