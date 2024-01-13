// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Aleks
// Incubator class function definitions

#include "Incubator.h"


Incubator::Incubator(QWidget* parent) {
	this->temperature = new float;
	this->realTemperature = new float;
	this->loadingTemp = new QString;
	*this->temperature = 0;
	*this->realTemperature = false;
	*this->loadingTemp = "No loading info";
}

Incubator::Incubator(float temperature, QString loading){
	this->temperature = new float;
	this->realTemperature = new float;
	this->loadingTemp = new QString;
	*this->temperature = temperature;
	*this->realTemperature = temperature;
	*this->loadingTemp = loading;

	
}

Incubator::~Incubator() {}

float Incubator::getTemperature() const {
    return *this->temperature;
}

void Incubator::setTemperature(float newTemperature) {
    *this->temperature = newTemperature;
}


