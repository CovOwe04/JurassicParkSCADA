#include "FileManagement.h"
#include "windows.h"

#define READ		1
#define WRITE		2
#define SEEK		3
#define APPEND		4
#define TRUNC		5
#define MAX_LINES	10

// Constructors
FileManagement::FileManagement()
{
	this->fileName = "";
}

FileManagement::FileManagement(std::string fileName)
{

	this->fileName = fileName;
}

// Getters and Setters
void FileManagement::setFileName(std::string fileName)
{
	this->fileName = fileName;
}
std::string FileManagement::getFileName()
{
	return this->fileName;
}

// Destructor
FileManagement::~FileManagement()
{}

// File Management functions
void FileManagement::readFileData(Ui::JurassicSCADA* ui)
{
	// initializing empty data variable
	std::string fileData;


	// opening a read file
	std::ifstream fin;
	fin.open(this->fileName, READ);


	// checking if file is located
	if (!fin)
	{
		std::cout << "ERROR: file \""<< this->fileName <<"\" not found..." << std::endl;
	}
	else
	{
		ui->popUpWindow->show();
		ui->popUpWindow->update();
		ui->popUpWindow->repaint();
		// read data inside file
		int i = 0;
		while (fin.good())
		{
			fin >> fileData;
			QString popUpMessage = QString::fromStdString(fileData);
			ui->Text->setText(popUpMessage);
			ui->popUpWindow->update();
			ui->popUpWindow->repaint();
			Sleep(200);
		}
		ui->popUpWindow->hide();
	}
	
	// close file to prevent corruption
	fin.close();
}