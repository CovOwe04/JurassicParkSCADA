// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Aleks
// Monorail class declaration

#pragma once
#include <string>
#include "Car.h"
#include <vector>
#include "ui_JurassicSCADA.h"

class Monorail {
public:
    Monorail(QWidget* parent = nullptr);
    Monorail(bool);
    ~Monorail();

    bool getPowerStatus() const;
    void setPowerStatus(bool status);

    const std::vector<Car>& getCars() const;

    //bool getCarDoorsLockedStatus(size_t carIndex) const;
    //void setCarDoorsLockedStatus(size_t carIndex, bool locked);

    void addCar(const Car& car);
public slots:


private:

    bool* powerStatus;
    std::vector<Car> cars;
};

