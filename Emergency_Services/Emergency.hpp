#include "Address.hpp"
#include "Victim.hpp"
#include "Suspect.hpp"
#include "Staff.hpp"
#include <vector>
#ifndef EMERGENCY_HPP_
#define EMERGENCY_HPP_
enum Status {
	// The Status of the emergency
	CRITICAL,
	ASSIGNED,
	TRANSPORTED,
	COMPLETED
};

class Emergency {
	// This class creates an emergency object, with an address, victim, suspect,
	// and staff.
private:
	// Variables
	std::vector<Staff*> assignedStaff;
    	Emergency& operator=(const Emergency& other);
    	Emergency(const Emergency& other);
    Address* address;
    Victim* victim;
    Suspect* suspect;
    Status status;
    int assignedStaffCount;
public:
    // Constructor
	Emergency(Address* address, Victim* victim, Suspect* suspect);

	// Getter methods
	Address* getAddress();
	Suspect* getSuspect();
	Victim* getVictim();
	Status getStatus();
	int getAssignedStaffCount();
	std::vector<Staff*> getAssignedStaff();

	// Setter methods
	void setStatus(Status status);
	void assignStaff(Staff* staff);
	void setAssignedStaffCount(int newCount);

	// General methods
	bool resolve();

	// Destructor
	virtual ~Emergency();
};

#endif /* EMERGENCY_HPP_ */
