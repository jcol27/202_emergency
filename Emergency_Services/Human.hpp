#include <string>
#ifndef HUMAN_HPP_
#define HUMAN_HPP_

class Human {
	// This class creates a human, with a name
private:
   	Human& operator=(const Human& other);
   	Human(const Human& other);
protected:
   	// Variables to be inherited
   	std::string name;
public:
   	// Constructor
	Human(const std::string &name);

	// Getter methods
	std::string getName();

	// Destructor
	virtual ~Human();
};

#endif /* HUMAN_HPP_ */
