#include "Civilian.hpp"
#ifndef SUSPECT_HPP_
#define SUSPECT_HPP_

class Suspect : public Civilian{
// This class creates a suspect, a type of civilian, with a isCaught bool,
// and a caughtAmount int
private:
    	Suspect& operator=(const Suspect& other);
    	Suspect(const Suspect& other);

    	// Variables
    	bool caught;
    	int caughtAmount;
public:
    	// Constructor
	Suspect(const std::string &name);

	// Getter methods
	int getCaughtByAmount();
	bool isCaught();

	// Setter methods
	void setCaught();
	void setCaughtAmount(int amount);

	// Destructor
	virtual ~Suspect();
};

#endif /* SUSPECT_HPP_ */
