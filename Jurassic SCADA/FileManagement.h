#pragma once

#include "io.h"
#include "Ui_JurassicSCADA.h"
#include <iostream>
#include <fstream>
#include <string.h>

class FileManagement
{
	std::string fileName;

public:
	// Constructors
	FileManagement();
	FileManagement(std::string);

	// Getters and Setters
	void setFileName(std::string);
	std::string getFileName();

	// Destructor
	~FileManagement();

	// File Management functions
	void readFileData(Ui::JurassicSCADA*);
};