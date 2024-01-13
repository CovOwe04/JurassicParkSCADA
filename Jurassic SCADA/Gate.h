// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Luke
// Gate class declaration

#pragma once
#include "Ui_JurassicSCADA.h"
#include <string>
#define NUMBER_OF_GATES 8
using namespace std;

class Gate
{
    int* gateID;
    bool* gateIsClosed;

public:
    //Contructors
    Gate(QWidget* parent = nullptr);
    Gate(int, bool);
    Gate(const Gate& other);

    // Copy assignment operator
    Gate& operator=(const Gate& other);

    //Getters and Setters
    void openGate();
    void closeGate();
    bool getGateStatus();
    void setGateStatus(bool status);

    //Destructor
    ~Gate();
};

int getClosedGateCount(Gate[], int);
