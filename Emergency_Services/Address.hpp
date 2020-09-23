#ifndef ADDRESS_HPP_
#define ADDRESS_HPP_
#include <iostream>
class Address {
	// This class creates an address object with a number, street, suburb
	// and postcode
private:
	// Variables
    Address& operator=(const Address& other);
    Address(const Address& other);
    int number; // between 10 and 999
    std::string street;
    std::string suburb;
    std::string postcode; // 4 digits, first 2 between 1-4, second two between 0-9
public:
    // Constructor
	Address(int number, std::string street, std::string suburb,
			std::string postcode);

	// Getter methods
	int getNumber();
	std::string getStreet();
	std::string getSuburb();
	std::string getPostcode();

	// Setter methods
	void changeAddressTo(int number, std::string street, std::string suburb,
			std::string postcode);

	// Destructor
	virtual ~Address();
};

#endif /* ADDRESS_HPP_ */
