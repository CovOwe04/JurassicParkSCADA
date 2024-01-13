// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Shared
// Pen class function definitions

#include "Pen.h"
#include "FileManagement.h"

Pen::Pen()
{

}

Pen::Pen(std::string dataFileName, std::string dinosaurName, PenID penID)
{

}
    
Pen::~Pen()
{

}

PenID Pen::getPenID() const
{
    return this->penID;
}

void Pen::setPenID(PenID penID)
{

}

void Pen::setDinosaurName(std::string name)
{

}

std::string Pen::getDinosaurName() const
{
    return this->dinosaurName;
}


void Pen::readPenData()
{

}

