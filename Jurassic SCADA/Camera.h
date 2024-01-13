#pragma once

#include "Ui_JurassicSCADA.h"

class Camera
{
	int* cameraID;
	bool* nightVision;
	QString* footage;

public:
	// Constructors
	Camera(QWidget* parent = nullptr);
	Camera(int, bool, QString);

	// Getters and Setters
	void setCameraID(int);
	int getCameraID();
	void setNightVision(bool);
	bool getNightVision();
	void setFootage(QString);
	QString getFootage();

	// Destructor
	~Camera();

	// Camera functions
	
	void displayCameraFootage(Ui::JurassicSCADA*);
	void displayNightVision(Ui::JurassicSCADA*);
};