// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Jon
// WeatherForecast class declaration

#pragma once
#include <string>

class WeatherForecast {
public:
    WeatherForecast();
    WeatherForecast(std::string dataFileName, float temperature, float humidity, float airPressure, float windSpeed, int windDirection);
    ~WeatherForecast();

    float getTemperature() const;
    void setTemperature(float temp);
    float getAirPressure() const;
    void setAirPressure(float pressure);
    float getWindSpeed() const;
    void setWindSpeed(float speed);
    int getWindDirection() const;
    void setWindDirection(int direction);
    float getHumidity() const;
    void setHumidity(float humidity);

    void readWeatherData();

private:
    std::string dataFileName;
    float temperature;
    float humidity;
    float airPressure;
    float windSpeed;
    int windDirection;
};

