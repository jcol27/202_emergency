#include "Staff.hpp"
#include "Victim.hpp"
#ifndef PARAMEDIC_HPP_
#define PARAMEDIC_HPP_

class Paramedic : public Staff{
// This class creates a paramedic object, a type of staff, with a victim
private:
   	Paramedic& operator=(const Paramedic& other);
   	Paramedic(const Paramedic& other);
    Victim* victim;
public:
    // Constructor
	Paramedic(const std::string &name);

	// Getter methods
	Victim* getAssignedVictim();

	// Setter methods
	void assignVictim(Victim* victim);

	// General methods
	void performJob();

	// Destructor
	~Paramedic();
};

#endif /* PARAMEDIC_HPP_ */
