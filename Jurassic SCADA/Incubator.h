// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Aleks
// Incubator class declaration

#pragma once
#include <string>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "FileManagement.h"
#include "ui_JurassicSCADA.h"


class Incubator {
    
public:
    Incubator(QWidget* parent = nullptr);
    Incubator(float, QString);
    ~Incubator();

    float getTemperature() const;
    void setTemperature(float);

signals:
    void temperatureChanged(float);

private:
    float* temperature;
    float* realTemperature;
    QString* loadingTemp;
};