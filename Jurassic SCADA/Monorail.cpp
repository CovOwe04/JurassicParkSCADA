// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Aleks
// Monorail class function definitions

#include "Monorail.h"
#include "FileManagement.h"

Monorail::Monorail(QWidget* parent)
{
    this->powerStatus = new bool;
    *this->powerStatus = true;
    this->cars = std::vector<Car>();
}

Monorail::Monorail(bool powerStatus)
{
    this->powerStatus = new bool;
    *this->powerStatus = powerStatus;
    this->cars = std::vector<Car>();
}

Monorail::~Monorail()
{
    
}

bool Monorail::getPowerStatus() const
{
    return *powerStatus;
}

void Monorail::setPowerStatus(bool status)
{
    *this->powerStatus = status;
}

void Monorail::addCar(const Car& car)
{
    cars.push_back(car);
}

const std::vector<Car>& Monorail::getCars() const
{
    return cars;
}
