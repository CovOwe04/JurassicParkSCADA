// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Shared
// Pen class declaration

#pragma once
#include <string>
#include "Camera.h"
#include "FeedSchedule.h"
#include "ElectricFence.h"
#include "Gate.h"

enum PenID {
    TYRANNOSAURUS   =   1,
    VELOCIRAPTOR    =   2,
    STEGOSAURUS     =   3,
    TRICERATOPS     =   4,
    DIPLODOCUS      =   5,
    SPINOSAURUS     =   6,
};

class Pen {
public:
    Pen();
    Pen(std::string dataFileName, std::string dinosaurName, PenID penID);
    ~Pen();

    void setPenID(PenID penID);
    PenID getPenID() const;
    void setDinosaurName(std::string name);
    std::string getDinosaurName() const;

    void readPenData();

private:
    std::string dataFileName;
    std::string dinosaurName;
    PenID penID;
};

