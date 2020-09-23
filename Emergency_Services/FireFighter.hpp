#include "Staff.hpp"
#ifndef FIREFIGHTER_HPP_
#define FIREFIGHTER_HPP_

class FireFighter : public Staff{
// This class creates a firefighter object, a type of staff
private:
    	FireFighter& operator=(const FireFighter& other);
    	FireFighter(const FireFighter& other);
public:
    // Constructor
	FireFighter(const std::string &name);

	// General methods
	void performJob();

	// Destructor
	virtual ~FireFighter();

};

#endif /* FIREFIGHTER_HPP_ */
