// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Luke
// ElectricFence class function definitions

#include "ElectricFence.h"
#include "FileManagement.h"

//Contructors
ElectricFence::ElectricFence(QWidget* parent)
{
    this->fenceID = new int;
    this->fenceIsActive = new bool;
    this->fenceVoltage = new float;
    *this->fenceID = 0;
    *this->fenceIsActive = true;
    *this->fenceVoltage = 0;
}
ElectricFence::ElectricFence(int ID, bool isActive, float voltage)
{
    this->fenceID = new int;
    this->fenceIsActive = new bool;
    this->fenceVoltage = new float;
    *this->fenceID = ID;
    *this->fenceIsActive = isActive;
    *this->fenceVoltage = voltage;
}
ElectricFence::ElectricFence(const ElectricFence& other)
{
    this->fenceID = new int;
    this->fenceIsActive = new bool;
    this->fenceVoltage = new float;
    *this->fenceID = *other.fenceID;
    *this->fenceIsActive = *other.fenceIsActive;
    *this->fenceVoltage = *other.fenceVoltage;
}

// Implement the copy assignment operator
ElectricFence& ElectricFence::operator=(const ElectricFence& other)
{
    if (this != &other) // Avoid self-assignment
    {
        *this->fenceID = *other.fenceID;
        *this->fenceIsActive = *other.fenceIsActive;
        *this->fenceVoltage = *other.fenceVoltage;
    }
    return *this;
}

//Getter and Setters
void ElectricFence::activateElectricFence()
{
    *fenceIsActive = true;
}
void ElectricFence::deactivateElectricFence()
{
    *fenceIsActive = false;
}
float ElectricFence::getElectricFenceVoltage()
{
    return *fenceVoltage;
}
void ElectricFence::setElectricFenceVoltage(float voltage)
{
    *fenceVoltage = voltage;
}
bool ElectricFence::getElectricFenceStatus()
{
    return *fenceIsActive;
}
void ElectricFence::setElectricFenceStatus(bool status)
{
    *fenceIsActive = status;
}

//destructor
ElectricFence::~ElectricFence()
{
    delete fenceID;
    delete fenceIsActive;
    delete fenceVoltage;
}

int getActiveFenceCount(ElectricFence g[], int arraySize)
{
    int activeFenceCount = 0;

    for (int i = 0; i < arraySize; i++)
        if (g[i].getElectricFenceStatus() == true)
            activeFenceCount++;
    return activeFenceCount;
}

