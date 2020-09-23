#include "Civilian.hpp"
#ifndef VICTIM_HPP_
#define VICTIM_HPP_

class Victim : public Civilian {
	// This class creates a victim object, a type of civilian, with an
	// treated bool and a treatedAmount int
private:
    	Victim& operator=(const Victim& other);
    	Victim(const Victim& other);

    	// Variables
    	bool treated;
    	int treatedAmount;
public:
    // Constructor
	Victim(const std::string &name);

	// Getter methods
	int getTreatedByAmount();

	// Setter methods
	void setTreated(bool treated);
	void setTreatedAmount(int amount);

	// General methods
	bool isTreated();

	// Destructor
	virtual ~Victim();

};

#endif /* VICTIM_HPP_ */
