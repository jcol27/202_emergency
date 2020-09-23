#include "Human.hpp"
#include "Address.hpp"
#include "Civilian.hpp"

#ifndef STAFF_HPP_
#define STAFF_HPP_

enum Type {
	// Enum for the type of staff the objects created from derived classes
	// are
	STAFF,
	POLICEOFFICER,
	PARAMEDIC,
	FIREFIGHTER
};

class Staff : public Human {
// This class creates a staff object, a type of human
private:
	Staff& operator=(const Staff& other);
    	Staff(const Staff& other);
protected:
    // Variables to be inherited
    int ID;
    static int nextID;
    bool complete;
    Type type;
    bool assigned;
    Address* address;

public:
    // Constructor
	Staff(const std::string &name);

	// Getter methods
	Address* getAddress();
	Type getType();
	int getID();
	bool isAssigned();
	bool isJobComplete();

	// Setter methods
	void setAssigned(bool assigned);
	void setAddress(Address* address);
	void setComplete();

	// General methods
	virtual void performJob();

	// Destructor
	virtual ~Staff();
};


#endif /* STAFF_HPP_ */
