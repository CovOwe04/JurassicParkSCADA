// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Aleks
// Car class declaration

#pragma once
#include "Ui_JurassicSCADA.h"
#include <string>

class Car {
public:
    Car(QWidget* parent = nullptr);
    Car(float fuelReserve);
    ~Car();

    float getFuelReserve() const;
    void setFuelReserve (float fuelReserve);
    void decreaseFuelReserve(float amount);

private:
    float* fuelReserve;
};
