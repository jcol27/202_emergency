#include "Staff.hpp"
#include "Suspect.hpp"
#ifndef POLICEOFFICER_HPP_
#define POLICEOFFICER_HPP_

class PoliceOfficer : public Staff {
// This class creates a police officer object, a type of staff, with a
// suspect
private:
	PoliceOfficer& operator=(const PoliceOfficer& other);
    PoliceOfficer(const PoliceOfficer& other);
    Suspect* suspect;
public:
    // Constructor
	PoliceOfficer(const std::string &name);

	// Getter methods
	Suspect* getAssignedSuspect();

	// Setter methods
	void assignSuspect(Suspect* suspect);

	// General methods
	void performJob();

	// Destructor
	virtual ~PoliceOfficer();
};

#endif /* POLICEOFFICER_HPP_ */
