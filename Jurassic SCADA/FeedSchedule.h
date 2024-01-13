// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Jon
// FeedSchedule class declaration

#pragma once
#include <string>

class FeedSchedule {
public:
    FeedSchedule();
    FeedSchedule(std::string dataFileName, std::string mealType, int mealFrequency, int timeSinceLastFed);
    ~FeedSchedule();

    void addFood(std::string foodType);
    void dismissFeedAlarm();
    int getTimeSinceLastFed() const;
    void setTimeSinceLastFed(int time);
    std::string getMealType() const;
    void setMealType(std::string type);
    int getMealFrequency() const;
    void setMealFrequency(int frequency);
    void readFeedScheduleData();

private:
    std::string dataFileName;
    std::string mealType;
    int mealFrequency;
    int timeSinceLastFed;
};
