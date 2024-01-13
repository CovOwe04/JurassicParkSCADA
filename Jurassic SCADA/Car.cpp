// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Aleks
// Car class function definitions

#include "Car.h"
#include "FileManagement.h"

Car::Car(QWidget* parent)
{
    this->fuelReserve = new float;
    *this->fuelReserve = 0;
}

Car::Car(float fuelReserve)
{
    this->fuelReserve = new float;
    *this->fuelReserve = fuelReserve;
}

Car::~Car()
{
}

float Car::getFuelReserve() const
{
    return *this->fuelReserve;
}

void Car::setFuelReserve(float fuelReserve)
{
    *this->fuelReserve = fuelReserve;
}

void Car::decreaseFuelReserve(float amount) {
    *fuelReserve -= amount;

    if (*fuelReserve < 0) {
        setFuelReserve(100);
    }

}

