#include "Address.hpp"

Address::Address(int number, std::string street, std::string suburb,
		std::string postcode){
	// Create an address object using the address class

	// If-else statements to check that inputs are valid
	if (number > 10 && number < 999) {
		this->number = number;
	}
	else {
		this->number = 10;
	}

	if (postcode[0] < 49 || postcode[0] > 52) {
		this->postcode = "1111";
	}
	else if (postcode[1] < 49 || postcode[1] > 52) {
		this->postcode = "1111";
	}
	else if (postcode[2] < 48 || postcode[2] > 57) {
		this->postcode = "1111";
	}
	else if (postcode[3] < 48 || postcode[3] > 57) {
		this->postcode = "1111";
	}
	else {
		this->postcode = postcode;
	}

	// Assumed inputs for street and suburb are valid
	this->street = street;
	this->suburb = suburb;

}

void Address::changeAddressTo(int number, std::string street,
		std::string suburb, std::string postcode){
	// Method to change the parameters of an address object

	// If-else statements to check inputs are valid
	if (number > 10 && number < 999) {
		this->number = number;
	}
	else {
		this->number = 10;
	}

	if (postcode[0] < 49 || postcode[0] > 52) {
		this->postcode = "1111";
	}
	else if (postcode[1] < 49 || postcode[1] > 52) {
		this->postcode = "1111";
	}
	else if (postcode[2] < 48 || postcode[2] > 57) {
		this->postcode = "1111";
	}
	else if (postcode[3] < 48 || postcode[3] > 57) {
		this->postcode = "1111";
	}
	else {
		this->postcode = postcode;
	}

	// Assumed inputs for street and suburb are valid
	this->street = street;
	this->suburb = suburb;
}

int Address::getNumber() {
	// Method to return the address number
	return this->number;
}

std::string Address::getPostcode() {
	// Method to return the address postcode
	return this->postcode;
}

std::string Address::getStreet() {
	// Method to return the address street name
	return this->street;
}

std::string Address::getSuburb() {
	// Method to return the address suburb
	return this->suburb;
}

Address::~Address() {
	// Destructor
}

