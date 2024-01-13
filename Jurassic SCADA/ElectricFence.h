// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Luke
// ElectricFence class declaration

#pragma once
#include "Ui_JurassicSCADA.h"
#include <string>
#define NUMBER_OF_FENCES 8
using namespace std;

class ElectricFence
{
    int* fenceID;
    bool* fenceIsActive;
    float* fenceVoltage;
public:
    //Constructors
    ElectricFence(QWidget* parent = nullptr);
    ElectricFence(int, bool, float);
    ElectricFence(const ElectricFence& other);

    // Copy assignment operator
    ElectricFence& operator=(const ElectricFence& other);

    void activateElectricFence();
    void deactivateElectricFence();
    float getElectricFenceVoltage();
    void setElectricFenceVoltage(float voltage);
    bool getElectricFenceStatus();
    void setElectricFenceStatus(bool status);

    //Destructor
    ~ElectricFence();
};
int getActiveFenceCount(ElectricFence[], int);