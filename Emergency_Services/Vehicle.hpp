
#ifndef VEHICLE_HPP_
#define VEHICLE_HPP_
#include <string>
class Vehicle {
	// This class creates a vehicle object for transporting staff in an
	// emergency sevices system, with a name and a capacity
private:
    	Vehicle& operator=(const Vehicle& other);
    	Vehicle(const Vehicle& other);

    	// Variables
    	std::string name;
    	int capacity;
public:
    // Constructor
	Vehicle(const std::string &name, int capacity);

	// Getter methods
	int getCapacity();
	std::string getName();

	// Destructor
	virtual ~Vehicle();
};

#endif /* VEHICLE_HPP_ */
