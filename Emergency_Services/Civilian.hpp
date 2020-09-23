#include "Human.hpp"
#ifndef CIVILIAN_HPP_
#define CIVILIAN_HPP_

class Civilian : public Human {
// This class creates a civilian object, a type of human, with a property debt
private:
	// Variables
	Civilian& operator=(const Civilian& other);
    	Civilian(const Civilian& other);

protected:
    // Variables to be inherited
    int debt;
public:
    // Constructor
	Civilian(const std::string &name);

	// Getter methods
	int getDebt();

	// Setter methods
	void increaseDebt(int debt);
	void decreaseDebt(int debt);
};

#endif /* CIVILIAN_HPP_ */
