#pragma once

#include "ui_JurassicSCADA.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QObject>
#include <stdbool.h>
#include "Camera.h"
#include "Gate.h"
#include "ElectricFence.h"
#include "FileManagement.h"
#include "Incubator.h"
#include "Car.h"
#include "Monorail.h"
#include <Qtimer.h>

#define MAXCAMERAS	6

class JurassicSCADA : public QMainWindow
{
	Q_OBJECT

public:
    JurassicSCADA(QWidget *parent = nullptr);
    ~JurassicSCADA();

private:
    Ui::JurassicSCADA ui;	
	Camera* cameraArray;
	Gate* gateArray;
	ElectricFence* fenceArray;
	FileManagement* FileArray;
	Incubator* incubator;
	Monorail* monorail;
	Car* car;
	QTimer* fuelUpdateTimer;
	QTimer* temperatureChangeTimer;


public slots:
	
	// ********* Camera Button handlers *********
	void on_camerabtn_clicked();
	void on_cameraBackbtn_clicked();
	void on_camerabtn1_clicked();
	void on_camerabtn2_clicked();
	void on_camerabtn3_clicked();
	void on_camerabtn4_clicked();
	void on_camerabtn5_clicked();
	void on_camerabtn6_clicked();
	void on_camerabtnClicked(Camera, FileManagement);
	void on_nightVisionToggle_clicked();
	void on_nightVisionbtnClicked(Camera*, FileManagement);
	// ******************************************

	// ********* Incubator Button Handlers ******
	void on_incubatorbtn_clicked();
	void on_incubatorBackbtn_clicked();
	void on_btnIncrease_clicked();
	void on_btnDecrease_clicked();
	void updateTemperature(float newTemperature);
	void handleTemperatureChange();
	// ******************************************

	// ********* Monorail Button Handlers *******
	void on_monorailbtn_clicked();
	void on_monorailBackbtn_clicked();
	void updatelblPowerStatus(bool);
	void on_monorailPowerbtn_clicked();
	void on_refuel1btn_clicked();
	void on_refuel2btn_clicked();
	void on_refuel3btn_clicked();
	void updateFuelReserves();
	// ******************************************

	// ********* Gate Button handlers *********
	void on_gatesbtn_clicked();
	void on_gatebackbtn_clicked();
	void on_gate1btn_clicked();
	void on_gate2btn_clicked();
	void on_gate3btn_clicked();
	void on_gate4btn_clicked();
	void on_gate5btn_clicked();
	void on_gate6btn_clicked();
	void on_gate7btn_clicked();
	void on_gate8btn_clicked();
	void changeGateCountDisplay(Gate[], int);
	// ******************************************

		// ********* Fence Button handlers *********
	void on_fencebtn_clicked();
	void on_fencebackbtn_clicked();
	void on_fence1btn_clicked();
	void on_fence2btn_clicked();
	void on_fence3btn_clicked();
	void on_fence4btn_clicked();
	void on_fence5btn_clicked();
	void on_fence6btn_clicked();
	void on_fence7btn_clicked();
	void on_fence8btn_clicked();
	void on_fence1incbtn_clicked();
	void on_fence1decbtn_clicked();
	void on_fence2incbtn_clicked();
	void on_fence2decbtn_clicked();
	void on_fence3incbtn_clicked();
	void on_fence3decbtn_clicked();
	void on_fence4incbtn_clicked();
	void on_fence4decbtn_clicked();
	void on_fence5incbtn_clicked();
	void on_fence5decbtn_clicked();
	void on_fence6incbtn_clicked();
	void on_fence6decbtn_clicked();
	void on_fence7incbtn_clicked();
	void on_fence7decbtn_clicked();
	void on_fence8incbtn_clicked();
	void on_fence8decbtn_clicked();
	void changeFenceCountDisplay(ElectricFence[], int);
	// ******************************************
};
