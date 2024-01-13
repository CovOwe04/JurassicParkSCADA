// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Jon
// FeedSchedule class function definitions

#include "FeedSchedule.h"
#include "FileManagement.h"

// TODO: FeedSchedule yet to be implemented





FeedSchedule::FeedSchedule()
{
    
}

FeedSchedule::FeedSchedule(std::string dataFileName, std::string mealType, 
    int mealFrequency, int timeSinceLastFed)
{
    
}

FeedSchedule::~FeedSchedule()
{
    
}

void FeedSchedule::addFood(std::string foodType)
{
    
}

void FeedSchedule::dismissFeedAlarm()
{
    
}

int FeedSchedule::getTimeSinceLastFed() const
{
    return this->timeSinceLastFed;
}

void FeedSchedule::setTimeSinceLastFed(int time)
{
    
}

std::string FeedSchedule::getMealType() const
{
    return this->mealType;
}

void FeedSchedule::setMealType(std::string type)
{
    
}

int FeedSchedule::getMealFrequency() const
{
    return this->mealFrequency;
}

void FeedSchedule::setMealFrequency(int frequency)
{
    
}

void FeedSchedule::readFeedScheduleData()
{
    
}

