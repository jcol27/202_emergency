#include "Civilian.hpp"

Civilian::Civilian(const std::string &name) : Human(name) {
	// Civilian constructor
	this->debt = 0;
}

int Civilian::getDebt(){
	// Method to return the civilian's debt
	return this->debt;
}

void Civilian::increaseDebt(int debt){
	// Method to increase the civilian's debt
	this->debt = this->debt + debt;

}

void Civilian::decreaseDebt(int debt){
	// Method to decrease the civilian's debt

	// Check debt input is valid ie can't pay off more than they owe
	if (debt < this->debt) {
		this->debt = this->debt - debt;
	}
	else {
		this->debt = 0;
	}
}


