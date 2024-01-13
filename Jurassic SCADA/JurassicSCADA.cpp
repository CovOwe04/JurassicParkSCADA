#include "JurassicSCADA.h"
#include <QObject>
#include "Incubator.h"
#include "monorail.h"


JurassicSCADA::JurassicSCADA(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.cameraScreen->hide();
	ui.gateScreen->hide();
	ui.fenceScreen->hide();
	ui.popUpWindow->hide();
	ui.IncubatorScreen->hide();
	ui.monorailScreen->hide();

	//********************************* Initialization of camera objects *******************************************
	
	// for testing purposes
	Camera c;
	Camera c1(2, true, "Cam 1 footage");
	c1.setCameraID(1);
	c1.setNightVision(false);
	c1.setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 1.jpg\"/></p></body></html>");
	
	int expectedCamID = c1.getCameraID();
	bool expectedNightVision = c1.getNightVision();
	QString expectedFootage = c1.getFootage();


	
	Camera c2(1, false, "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 2.jpg\"/></p></body></html>");
	Camera c3(1, false, "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 3.jpg\"/></p></body></html>");
	Camera c4(1, false, "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 4.jpg\"/></p></body></html>");
	Camera c5(1, false, "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 5.jpg\"/></p></body></html>");
	Camera c6(1, false, "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 6.png\"/></p></body></html>");
	this->cameraArray = new Camera[6];
	this->cameraArray[0] = c1;
	this->cameraArray[1] = c2;
	this->cameraArray[2] = c3;
	this->cameraArray[3] = c4;
	this->cameraArray[4] = c5;
	this->cameraArray[5] = c6;
	// *************************************************************************************************************

	//********************************* Initialization of Gate objects *******************************************
	Gate g1(1, true);
	Gate g2(2, true);
	Gate g3(3, true);
	Gate g4(4, true);
	Gate g5(5, true);
	Gate g6(6, true);
	Gate g7(7, true);
	Gate g8(8, true);
	this->gateArray = new Gate[NUMBER_OF_GATES];
	this->gateArray[0] = g1;
	this->gateArray[1] = g2;
	this->gateArray[2] = g3;
	this->gateArray[3] = g4;
	this->gateArray[4] = g5;
	this->gateArray[5] = g6;
	this->gateArray[6] = g7;
	this->gateArray[7] = g8;
	// *************************************************************************************************************

	//********************************* Initialization of Fence objects *******************************************
	ElectricFence f1(1, true, 500.0);
	ElectricFence f2(2, true, 500.0);
	ElectricFence f3(3, true, 500.0);
	ElectricFence f4(4, true, 500.0);
	ElectricFence f5(5, true, 500.0);
	ElectricFence f6(6, true, 500.0);
	ElectricFence f7(7, true, 500.0);
	ElectricFence f8(8, true, 500.0);
	this->fenceArray = new ElectricFence[NUMBER_OF_GATES];
	this->fenceArray[0] = f1;
	this->fenceArray[1] = f2;
	this->fenceArray[2] = f3;
	this->fenceArray[3] = f4;
	this->fenceArray[4] = f5;
	this->fenceArray[5] = f6;
	this->fenceArray[6] = f7;
	this->fenceArray[7] = f8;
	ui.Fence1Data2->setText(QString("Voltage: %1V").arg(fenceArray[0].getElectricFenceVoltage()));
	ui.Fence2Data2->setText(QString("Voltage: %1V").arg(fenceArray[1].getElectricFenceVoltage()));
	ui.Fence3Data2->setText(QString("Voltage: %1V").arg(fenceArray[2].getElectricFenceVoltage()));
	ui.Fence4Data2->setText(QString("Voltage: %1V").arg(fenceArray[3].getElectricFenceVoltage()));
	ui.Fence5Data2->setText(QString("Voltage: %1V").arg(fenceArray[4].getElectricFenceVoltage()));
	ui.Fence6Data2->setText(QString("Voltage: %1V").arg(fenceArray[5].getElectricFenceVoltage()));
	ui.Fence7Data2->setText(QString("Voltage: %1V").arg(fenceArray[6].getElectricFenceVoltage()));
	ui.Fence8Data2->setText(QString("Voltage: %1V").arg(fenceArray[7].getElectricFenceVoltage()));
	// *************************************************************************************************************

	//********************************* Initialization of File objects *******************************************
	// file pointer for camera text files

	FileManagement CameraSwitch("NightVisionToggle.txt");
	FileManagement NightVisionToggle("NightVisionToggle.txt");
	FileManagement GateClosing("GateClosing.txt");
	FileManagement GateOpening("GateOpening.txt");
	FileManagement FenceActivating("FenceActivating.txt");
	FileManagement FenceDeactivating("FenceDeactivating.txt");
	FileManagement TemperatureChanging("TemperatureChanging.txt");
	FileManagement RefillingFuel("RefillingFuel.txt");
	FileManagement MonorailActivating("MonorailActivating.txt");
	FileManagement MonorailDeactivating("MonorailDeactivating.txt");

	// for testing purposes
	FileManagement test;
	CameraSwitch.setFileName("CameraSwitch.txt");
	std::string expectedFileName = CameraSwitch.getFileName();


	this->FileArray = new FileManagement[10];
	this->FileArray[0] = CameraSwitch;
	this->FileArray[1] = NightVisionToggle;
	this->FileArray[2] = GateClosing;
	this->FileArray[3] = GateOpening;
	this->FileArray[4] = FenceActivating;
	this->FileArray[5] = FenceDeactivating;
	this->FileArray[6] = TemperatureChanging;
	this->FileArray[7] = RefillingFuel;
	this->FileArray[8] = MonorailActivating;
	this->FileArray[9] = MonorailDeactivating;
	// *************************************************************************************************************


	//********************************* Initialization of incubator object ***************************************
	this->incubator = new Incubator(25.0, "TemperatureChanging.txt");
	ui.lblTemp->setText(QString::number(incubator->getTemperature()));
	//************************************************************************************************************

	//********************************* Initialization of monorail-car object(s) ****************************************
	Monorail monorail(true);
	updatelblPowerStatus(monorail.getPowerStatus());
	Car car1(45);
	Car car2(57);
	Car car3(75);
	monorail.addCar(car1);
	monorail.addCar(car2);
	monorail.addCar(car3);
	ui.lblFuelReserve1->setText(QString::number(car1.getFuelReserve()));
	ui.lblFuelReserve2->setText(QString::number(car2.getFuelReserve()));
	ui.lblFuelReserve3->setText(QString::number(car3.getFuelReserve()));
	//********************************************************************************************************************

	//********************************* Timers to help emulate realtime changes in data *********************************
	fuelUpdateTimer = new QTimer(this);
	connect(fuelUpdateTimer, &QTimer::timeout, this, &JurassicSCADA::updateFuelReserves);
	fuelUpdateTimer->start(1500);
	temperatureChangeTimer = new QTimer(this);
	temperatureChangeTimer->setSingleShot(true);
	connect(temperatureChangeTimer, &QTimer::timeout, this, &JurassicSCADA::handleTemperatureChange);
	//*******************************************************************************************************************
}

JurassicSCADA::~JurassicSCADA()
{}

// *************** Main menu camera module buttons*****************
void JurassicSCADA::on_camerabtn_clicked()
{
    ui.mainSCADA->hide();
    ui.cameraScreen->show();
}

void JurassicSCADA::on_cameraBackbtn_clicked()
{
	ui.cameraScreen->hide();
	ui.mainSCADA->show();
}
//*****************************************************************

// *************** Main menu gate module buttons*****************
void JurassicSCADA::on_gatesbtn_clicked()
{
	ui.mainSCADA->hide();
	ui.gateScreen->show();
}

void JurassicSCADA::on_gatebackbtn_clicked()
{
	ui.gateScreen->hide();
	ui.mainSCADA->show();
}
//*****************************************************************

// *************** Main menu fence module buttons*****************
void JurassicSCADA::on_fencebtn_clicked()
{
	ui.mainSCADA->hide();
	ui.fenceScreen->show();
}

void JurassicSCADA::on_fencebackbtn_clicked()
{
	ui.fenceScreen->hide();
	ui.mainSCADA->show();
}
//*****************************************************************

// ********** Gate button handlers ****************
void JurassicSCADA::on_gate1btn_clicked()
{
	//Switch the gate status
	gateArray[0].setGateStatus(!(gateArray[0].getGateStatus()));
	
	//Update the UI accordingly
	if (gateArray[0].getGateStatus() == true)
	{
		FileArray[2].readFileData(&ui);
		ui.Gate1Data->setText("Gate 1 Closed");
		ui.Gate1LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
	}
	else
	{
		FileArray[3].readFileData(&ui);
		ui.Gate1Data->setText("Gate 1 Open");
		ui.Gate1LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
	}
	changeGateCountDisplay(gateArray, NUMBER_OF_GATES);
	
}
void JurassicSCADA::on_gate2btn_clicked()
{
	gateArray[1].setGateStatus(!(gateArray[1].getGateStatus()));
	if (gateArray[1].getGateStatus() == true)
	{
		FileArray[2].readFileData(&ui);
		ui.Gate2Data->setText("Gate 2 Closed");
		ui.Gate2LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
	}
	else
	{
		FileArray[3].readFileData(&ui);
		ui.Gate2Data->setText("Gate 2 Open");
		ui.Gate2LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
	}
	changeGateCountDisplay(gateArray, NUMBER_OF_GATES);
}
void JurassicSCADA::on_gate3btn_clicked()
{
	gateArray[2].setGateStatus(!(gateArray[2].getGateStatus()));
	if (gateArray[2].getGateStatus() == true)
	{
		FileArray[2].readFileData(&ui);
		ui.Gate3Data->setText("Gate 3 Closed");
		ui.Gate3LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
	}
	else
	{
		FileArray[3].readFileData(&ui);
		ui.Gate3Data->setText("Gate 3 Open");
		ui.Gate3LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
	}
	changeGateCountDisplay(gateArray, NUMBER_OF_GATES);
}
void JurassicSCADA::on_gate4btn_clicked()
{
	gateArray[3].setGateStatus(!(gateArray[3].getGateStatus()));
	if (gateArray[3].getGateStatus() == true)
	{
		FileArray[2].readFileData(&ui);
		ui.Gate4Data->setText("Gate 4 Closed");
		ui.Gate4LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
	}
	else
	{
		FileArray[3].readFileData(&ui);
		ui.Gate4Data->setText("Gate 4 Open");
		ui.Gate4LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
	}
	changeGateCountDisplay(gateArray, NUMBER_OF_GATES);
}
void JurassicSCADA::on_gate5btn_clicked()
{
	gateArray[4].setGateStatus(!(gateArray[4].getGateStatus()));
	if (gateArray[4].getGateStatus() == true)
	{
		FileArray[2].readFileData(&ui);
		ui.Gate5Data->setText("Gate 5 Closed");
		ui.Gate5LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
	}
	else
	{
		FileArray[3].readFileData(&ui);
		ui.Gate5Data->setText("Gate 5 Open");
		ui.Gate5LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
	}
	changeGateCountDisplay(gateArray, NUMBER_OF_GATES);
}
void JurassicSCADA::on_gate6btn_clicked()
{
	gateArray[5].setGateStatus(!(gateArray[5].getGateStatus()));
	if (gateArray[5].getGateStatus() == true)
	{
		FileArray[2].readFileData(&ui);
		ui.Gate6Data->setText("Gate 6 Closed");
		ui.Gate6LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
	}
	else
	{
		FileArray[3].readFileData(&ui);
		ui.Gate6Data->setText("Gate 6 Open");
		ui.Gate6LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
	}
	changeGateCountDisplay(gateArray, NUMBER_OF_GATES);
}
void JurassicSCADA::on_gate7btn_clicked()
{
	gateArray[6].setGateStatus(!(gateArray[6].getGateStatus()));
	if (gateArray[6].getGateStatus() == true)
	{
		FileArray[2].readFileData(&ui);
		ui.Gate7Data->setText("Front Gate Closed");
		ui.Gate7LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
	}
	else
	{
		FileArray[3].readFileData(&ui);
		ui.Gate7Data->setText("Front Gate Open");
		ui.Gate7LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
	}
	changeGateCountDisplay(gateArray, NUMBER_OF_GATES);
}
void JurassicSCADA::on_gate8btn_clicked()
{
	gateArray[7].setGateStatus(!(gateArray[7].getGateStatus()));
	if (gateArray[7].getGateStatus() == true)
	{
		FileArray[2].readFileData(&ui);
		ui.Gate8Data->setText("Back Gate Closed");
		ui.Gate8LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
	}
	else
	{
		FileArray[3].readFileData(&ui);
		ui.Gate8Data->setText("Back Gate Open");
		ui.Gate8LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
	}
	changeGateCountDisplay(gateArray, NUMBER_OF_GATES);
}
void JurassicSCADA::changeGateCountDisplay(Gate g[], int arraySize)
{
	int closedCount = getClosedGateCount(g, arraySize);
	ui.GateMenuData1->setText(QString("Gates Closed: %1/8").arg(closedCount));
	ui.GateData1->setText(QString("Gates Closed: %1/8").arg(closedCount));
	if (closedCount >=7)
	{
		ui.GateIcon->setText("<html><head/><body><p><img src =\":/JurassicSCADA/Gate_Icon.png\"/></p></body></html>");
		ui.GateMenuData2->setText("Threat Level: Low");
		ui.GateData2->setText("Threat Level: Low");
	}
	else if (closedCount >= 5)
	{
		ui.GateIcon->setText("<html><head/><body><p><img src =\":/JurassicSCADA/Gate_Icon.png\"/></p></body></html>");
		ui.GateMenuData2->setText("Threat Level: Medium"); 
		ui.GateData2->setText("Threat Level: Medium");
	}
	else
	{
		ui.GateIcon->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
		ui.GateMenuData2->setText("Threat Level: High");
		ui.GateData2->setText("Threat Level: High");
	}
}

// ********** Fence button handlers ****************
void JurassicSCADA::on_fence1btn_clicked()
{
	//Switch the fence status
	fenceArray[0].setElectricFenceStatus(!(fenceArray[0].getElectricFenceStatus()));

	//Update the UI accordingly
	if (fenceArray[0].getElectricFenceStatus() == true)
	{
		FileArray[4].readFileData(&ui);
		ui.Fence1Data->setText("Fence 1 Active");
		ui.Fence1LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
		ui.Fence1Data2->setText(QString("Voltage: %1V").arg(fenceArray[0].getElectricFenceVoltage()));
	}
	else
	{
		FileArray[5].readFileData(&ui);
		ui.Fence1Data->setText("Fence 1 Inactive");
		ui.Fence1LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
		ui.Fence1Data2->setText("Voltage: 0.0V");
	}
	changeFenceCountDisplay(fenceArray, NUMBER_OF_FENCES);
}
void JurassicSCADA::on_fence2btn_clicked()
{
	//Switch the fence status
	fenceArray[1].setElectricFenceStatus(!(fenceArray[1].getElectricFenceStatus()));

	//Update the UI accordingly
	if (fenceArray[1].getElectricFenceStatus() == true)
	{
		FileArray[4].readFileData(&ui);
		ui.Fence2Data->setText("Fence 2 Active");
		ui.Fence2LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
		ui.Fence2Data2->setText(QString("Voltage: %1V").arg(fenceArray[1].getElectricFenceVoltage()));
	}
	else
	{
		FileArray[5].readFileData(&ui);
		ui.Fence2Data->setText("Fence 2 Inactive");
		ui.Fence2LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
		ui.Fence2Data2->setText("Voltage: 0.0V");
	}
	changeFenceCountDisplay(fenceArray, NUMBER_OF_FENCES);
}
void JurassicSCADA::on_fence3btn_clicked()
{
	//Switch the fence status
	fenceArray[2].setElectricFenceStatus(!(fenceArray[2].getElectricFenceStatus()));

	//Update the UI accordingly
	if (fenceArray[2].getElectricFenceStatus() == true)
	{
		FileArray[4].readFileData(&ui);
		ui.Fence3Data->setText("Fence 3 Active");
		ui.Fence3LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
		ui.Fence3Data2->setText(QString("Voltage: %1V").arg(fenceArray[2].getElectricFenceVoltage()));
	}
	else
	{
		FileArray[5].readFileData(&ui);
		ui.Fence3Data->setText("Fence 3 Inactive");
		ui.Fence3LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
		ui.Fence3Data2->setText("Voltage: 0.0V");
	}
	changeFenceCountDisplay(fenceArray, NUMBER_OF_FENCES);
}
void JurassicSCADA::on_fence4btn_clicked()
{
	//Switch the fence status
	fenceArray[3].setElectricFenceStatus(!(fenceArray[3].getElectricFenceStatus()));

	//Update the UI accordingly
	if (fenceArray[3].getElectricFenceStatus() == true)
	{
		FileArray[4].readFileData(&ui);
		ui.Fence4Data->setText("Fence 4 Active");
		ui.Fence4LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
		ui.Fence4Data2->setText(QString("Voltage: %1V").arg(fenceArray[3].getElectricFenceVoltage()));
	}
	else
	{
		FileArray[5].readFileData(&ui);
		ui.Fence4Data->setText("Fence 4 Inactive");
		ui.Fence4LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
		ui.Fence4Data2->setText("Voltage: 0.0V");
	}
	changeFenceCountDisplay(fenceArray, NUMBER_OF_FENCES);
}
void JurassicSCADA::on_fence5btn_clicked()
{
	//Switch the fence status
	fenceArray[4].setElectricFenceStatus(!(fenceArray[4].getElectricFenceStatus()));

	//Update the UI accordingly
	if (fenceArray[4].getElectricFenceStatus() == true)
	{
		FileArray[4].readFileData(&ui);
		ui.Fence5Data->setText("Fence 5 Active");
		ui.Fence5LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
		ui.Fence5Data2->setText(QString("Voltage: %1V").arg(fenceArray[4].getElectricFenceVoltage()));
	}
	else
	{
		FileArray[5].readFileData(&ui);
		ui.Fence5Data->setText("Fence 5 Inactive");
		ui.Fence5LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
		ui.Fence5Data2->setText("Voltage: 0.0V");
	}
	changeFenceCountDisplay(fenceArray, NUMBER_OF_FENCES);
}
void JurassicSCADA::on_fence6btn_clicked()
{
	//Switch the fence status
	fenceArray[5].setElectricFenceStatus(!(fenceArray[5].getElectricFenceStatus()));

	//Update the UI accordingly
	if (fenceArray[5].getElectricFenceStatus() == true)
	{
		FileArray[4].readFileData(&ui);
		ui.Fence6Data->setText("Fence 6 Active");
		ui.Fence6LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
		ui.Fence6Data2->setText(QString("Voltage: %1V").arg(fenceArray[5].getElectricFenceVoltage()));
	}
	else
	{
		FileArray[5].readFileData(&ui);
		ui.Fence6Data->setText("Fence 6 Inactive");
		ui.Fence6LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
		ui.Fence6Data2->setText("Voltage: 0.0V");
	}
	changeFenceCountDisplay(fenceArray, NUMBER_OF_FENCES);
}
void JurassicSCADA::on_fence7btn_clicked()
{
	//Switch the fence status
	fenceArray[6].setElectricFenceStatus(!(fenceArray[6].getElectricFenceStatus()));

	//Update the UI accordingly
	if (fenceArray[6].getElectricFenceStatus() == true)
	{
		FileArray[4].readFileData(&ui);
		ui.Fence7Data->setText("Front Fence Active");
		ui.Fence7LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
		ui.Fence7Data2->setText(QString("Voltage: %1V").arg(fenceArray[6].getElectricFenceVoltage()));
	}
	else
	{
		FileArray[5].readFileData(&ui);
		ui.Fence7Data->setText("Front Fence Inactive");
		ui.Fence7LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
		ui.Fence7Data2->setText("Voltage: 0.0V");
	}
	changeFenceCountDisplay(fenceArray, NUMBER_OF_FENCES);
}
void JurassicSCADA::on_fence8btn_clicked()
{
	//Switch the fence status
	fenceArray[7].setElectricFenceStatus(!(fenceArray[7].getElectricFenceStatus()));

	//Update the UI accordingly
	if (fenceArray[7].getElectricFenceStatus() == true)
	{
		FileArray[4].readFileData(&ui);
		ui.Fence8Data->setText("Back Fence Active");
		ui.Fence8LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
		ui.Fence8Data2->setText(QString("Voltage: %1V").arg(fenceArray[7].getElectricFenceVoltage()));
	}
	else
	{
		FileArray[5].readFileData(&ui);
		ui.Fence8Data->setText("Back Fence Inactive");
		ui.Fence8LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
		ui.Fence8Data2->setText("Voltage: 0.0V");
	}
	changeFenceCountDisplay(fenceArray, NUMBER_OF_FENCES);
}
void JurassicSCADA::on_fence1incbtn_clicked()
{
	if (fenceArray[0].getElectricFenceStatus() == true)
	{
		fenceArray[0].setElectricFenceVoltage(fenceArray[0].getElectricFenceVoltage() + 100);
		ui.Fence1Data2->setText(QString("Voltage: %1V").arg(fenceArray[0].getElectricFenceVoltage()));
	}
}
void JurassicSCADA::on_fence1decbtn_clicked()
{
	if (fenceArray[0].getElectricFenceStatus() == true && fenceArray[0].getElectricFenceVoltage() > 100)
	{
		fenceArray[0].setElectricFenceVoltage(fenceArray[0].getElectricFenceVoltage() - 100);
		ui.Fence1Data2->setText(QString("Voltage: %1V").arg(fenceArray[0].getElectricFenceVoltage()));
	}
}
void JurassicSCADA::on_fence2incbtn_clicked()
{
	if (fenceArray[1].getElectricFenceStatus() == true)
	{
		fenceArray[1].setElectricFenceVoltage(fenceArray[1].getElectricFenceVoltage() + 100);
		ui.Fence2Data2->setText(QString("Voltage: %1V").arg(fenceArray[1].getElectricFenceVoltage()));
	}
}
void JurassicSCADA::on_fence2decbtn_clicked()
{
	if (fenceArray[1].getElectricFenceStatus() == true && fenceArray[1].getElectricFenceVoltage() > 100)
	{
		fenceArray[1].setElectricFenceVoltage(fenceArray[1].getElectricFenceVoltage() - 100);
		ui.Fence2Data2->setText(QString("Voltage: %1V").arg(fenceArray[1].getElectricFenceVoltage()));
	}
}
void JurassicSCADA::on_fence3incbtn_clicked()
{
	if (fenceArray[2].getElectricFenceStatus() == true)
	{
		fenceArray[2].setElectricFenceVoltage(fenceArray[2].getElectricFenceVoltage() + 100);
		ui.Fence3Data2->setText(QString("Voltage: %1V").arg(fenceArray[2].getElectricFenceVoltage()));
	}
}
void JurassicSCADA::on_fence3decbtn_clicked()
{
	if (fenceArray[2].getElectricFenceStatus() == true && fenceArray[2].getElectricFenceVoltage() > 100)
	{
		fenceArray[2].setElectricFenceVoltage(fenceArray[2].getElectricFenceVoltage() - 100);
		ui.Fence3Data2->setText(QString("Voltage: %1V").arg(fenceArray[2].getElectricFenceVoltage()));
	}
}
void JurassicSCADA::on_fence4incbtn_clicked()
{
	if (fenceArray[3].getElectricFenceStatus() == true)
	{
		fenceArray[3].setElectricFenceVoltage(fenceArray[3].getElectricFenceVoltage() + 100);
		ui.Fence4Data2->setText(QString("Voltage: %1V").arg(fenceArray[3].getElectricFenceVoltage()));
	}
}
void JurassicSCADA::on_fence4decbtn_clicked()
{
	if (fenceArray[3].getElectricFenceStatus() == true && fenceArray[3].getElectricFenceVoltage() > 100)
	{
		fenceArray[3].setElectricFenceVoltage(fenceArray[3].getElectricFenceVoltage() - 100);
		ui.Fence4Data2->setText(QString("Voltage: %1V").arg(fenceArray[3].getElectricFenceVoltage()));
	}
}
void JurassicSCADA::on_fence5incbtn_clicked()
{
	if (fenceArray[4].getElectricFenceStatus() == true)
	{
		fenceArray[4].setElectricFenceVoltage(fenceArray[4].getElectricFenceVoltage() + 100);
		ui.Fence5Data2->setText(QString("Voltage: %1V").arg(fenceArray[4].getElectricFenceVoltage()));
	}
}
void JurassicSCADA::on_fence5decbtn_clicked()
{
	if (fenceArray[4].getElectricFenceStatus() == true && fenceArray[4].getElectricFenceVoltage() > 100)
	{
		fenceArray[4].setElectricFenceVoltage(fenceArray[4].getElectricFenceVoltage() - 100);
		ui.Fence5Data2->setText(QString("Voltage: %1V").arg(fenceArray[4].getElectricFenceVoltage()));
	}
}
void JurassicSCADA::on_fence6incbtn_clicked()
{
	if (fenceArray[5].getElectricFenceStatus() == true)
	{
		fenceArray[5].setElectricFenceVoltage(fenceArray[5].getElectricFenceVoltage() + 100);
		ui.Fence6Data2->setText(QString("Voltage: %1V").arg(fenceArray[5].getElectricFenceVoltage()));
	}
}
void JurassicSCADA::on_fence6decbtn_clicked()
{
	if (fenceArray[5].getElectricFenceStatus() == true && fenceArray[5].getElectricFenceVoltage() > 100)
	{
		fenceArray[5].setElectricFenceVoltage(fenceArray[5].getElectricFenceVoltage() - 100);
		ui.Fence6Data2->setText(QString("Voltage: %1V").arg(fenceArray[5].getElectricFenceVoltage()));
	}
}
void JurassicSCADA::on_fence7incbtn_clicked()
{
	if (fenceArray[6].getElectricFenceStatus() == true)
	{
		fenceArray[6].setElectricFenceVoltage(fenceArray[6].getElectricFenceVoltage() + 100);
		ui.Fence7Data2->setText(QString("Voltage: %1V").arg(fenceArray[6].getElectricFenceVoltage()));
	}
}
void JurassicSCADA::on_fence7decbtn_clicked()
{
	if (fenceArray[6].getElectricFenceStatus() == true && fenceArray[6].getElectricFenceVoltage() > 100)
	{
		fenceArray[6].setElectricFenceVoltage(fenceArray[6].getElectricFenceVoltage() - 100);
		ui.Fence7Data2->setText(QString("Voltage: %1V").arg(fenceArray[6].getElectricFenceVoltage()));
	}
}
void JurassicSCADA::on_fence8incbtn_clicked()
{
	if (fenceArray[7].getElectricFenceStatus() == true)
	{
		fenceArray[7].setElectricFenceVoltage(fenceArray[7].getElectricFenceVoltage() + 100);
		ui.Fence8Data2->setText(QString("Voltage: %1V").arg(fenceArray[7].getElectricFenceVoltage()));
	}
}
void JurassicSCADA::on_fence8decbtn_clicked()
{
	if (fenceArray[7].getElectricFenceStatus() == true && fenceArray[7].getElectricFenceVoltage() > 100)
	{
		fenceArray[7].setElectricFenceVoltage(fenceArray[7].getElectricFenceVoltage() - 100);
		ui.Fence8Data2->setText(QString("Voltage: %1V").arg(fenceArray[7].getElectricFenceVoltage()));
	}
}

void JurassicSCADA::changeFenceCountDisplay(ElectricFence g[], int arraySize)
{
	int activeCount = getActiveFenceCount(g, arraySize);
	ui.FenceMenuData1->setText(QString("Fences Active: %1/8").arg(activeCount));
	ui.FenceData1->setText(QString("Fences Active: %1/8").arg(activeCount));
	if (activeCount >= 7)
	{
		ui.FenceIcon->setText("<html><head/><body><p><img src =\":/JurassicSCADA/Fence Icon.png\"/></p></body></html>");
		ui.FenceMenuData2->setText("Threat Level: Low");
		ui.FenceData2->setText("Threat Level: Low");
	}
	else if (activeCount >= 5)
	{
		ui.FenceIcon->setText("<html><head/><body><p><img src =\":/JurassicSCADA/Fence Icon.png\"/></p></body></html>");
		ui.FenceMenuData2->setText("Threat Level: Medium");
		ui.FenceData2->setText("Threat Level: Medium");
	}
	else
	{
		ui.FenceIcon->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
		ui.FenceMenuData2->setText("Threat Level: High");
		ui.FenceData2->setText("Threat Level: High");
	}
}

// ********* Camera button handlers ***************
void JurassicSCADA::on_camerabtn1_clicked() 
{
	on_camerabtnClicked(this->cameraArray[0], this->FileArray[0]);
}
void JurassicSCADA::on_camerabtn2_clicked()
{
	on_camerabtnClicked(this->cameraArray[1], this->FileArray[0]);
}
void JurassicSCADA::on_camerabtn3_clicked()
{
	on_camerabtnClicked(this->cameraArray[2], this->FileArray[0]);
}
void JurassicSCADA::on_camerabtn4_clicked()
{
	on_camerabtnClicked(this->cameraArray[3], this->FileArray[0]);
}
void JurassicSCADA::on_camerabtn5_clicked()
{
	on_camerabtnClicked(this->cameraArray[4], this->FileArray[0]);
}
void JurassicSCADA::on_camerabtn6_clicked()
{
	on_camerabtnClicked(this->cameraArray[5], this->FileArray[0]);
	
}
void JurassicSCADA::on_nightVisionToggle_clicked()
{
	
	on_nightVisionbtnClicked(this->cameraArray, this->FileArray[1]);
}

void JurassicSCADA::on_camerabtnClicked(Camera camera, FileManagement fileptr)
{
	
	fileptr.readFileData(&ui);
	camera.displayCameraFootage(&ui);
}

// *********************** night vision logic to switch the image to a night vision filtered image before displaying ******************************
void JurassicSCADA::on_nightVisionbtnClicked(Camera* camera, FileManagement fileptr)
{
	fileptr.readFileData(&ui);
	if (ui.cameraLabel->text() == camera[0].getFootage())
	{
		if (camera[0].getNightVision() == false)
			camera[0].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 1 NV.jpg\"/></p></body></html>");
		else
			camera[0].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 1.jpg\"/></p></body></html>");

		camera[0].displayNightVision(&ui);
	}



	else if (ui.cameraLabel->text() == camera[1].getFootage())
	{
		if (camera[1].getNightVision() == false)
			camera[1].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 2 NV.jpg\"/></p></body></html>");
		else
			camera[1].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 2.jpg\"/></p></body></html>");

		camera[1].displayNightVision(&ui);
	}



	else if (ui.cameraLabel->text() == camera[2].getFootage())
	{
		if (camera[2].getNightVision() == false)
			camera[2].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 3 NV.jpg\"/></p></body></html>");
		else
			camera[2].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 3.jpg\"/></p></body></html>");

		camera[2].displayNightVision(&ui);
	}



	else if (ui.cameraLabel->text() == camera[3].getFootage())
	{
		if (camera[3].getNightVision() == false)
			camera[3].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 4 NV.jpg\"/></p></body></html>");
		else
			camera[3].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 4.jpg\"/></p></body></html>");

		camera[3].displayNightVision(&ui);
	}



	else if (ui.cameraLabel->text() == camera[4].getFootage())
	{
		if (camera[4].getNightVision() == false)
			camera[4].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 5 NV.jpg\"/></p></body></html>");
		else
			camera[4].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 5.jpg\"/></p></body></html>");

		camera[4].displayNightVision(&ui);
	}



	else if (ui.cameraLabel->text() == camera[5].getFootage())
	{	
		if (camera[5].getNightVision() == false)
			camera[5].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 6 NV.jpg\"/></p></body></html>");
		else
			camera[5].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 6.png\"/></p></body></html>");

		camera[5].displayNightVision(&ui);
	}
	
}
// *********************************************************************************************************************************

//**********************************************  Incubator Button Logic  ******************************************
void JurassicSCADA::on_btnIncrease_clicked()
{
    float currentTemperature = incubator->getTemperature();
    incubator->setTemperature(currentTemperature + 0.1);
	ui.lblTemp->setText(QString::number(incubator->getTemperature()));
	temperatureChangeTimer->start(1000);
}

void JurassicSCADA::on_btnDecrease_clicked()
{
	float currentTemperature = incubator->getTemperature();
    incubator->setTemperature(currentTemperature - 0.1);
	ui.lblTemp->setText(QString::number(incubator->getTemperature()));
	temperatureChangeTimer->start(1000);
}

void JurassicSCADA::updateTemperature(float newTemperature) {
	// Update the UI element displaying the temperature
	ui.lblTemp->setText(QString::number(newTemperature));
	FileArray[6].readFileData(&ui);
}

void JurassicSCADA::on_incubatorbtn_clicked()
{
	ui.mainSCADA->hide();
	ui.IncubatorScreen->show();
}

void JurassicSCADA::on_incubatorBackbtn_clicked()
{
	ui.IncubatorScreen->hide();
	ui.mainSCADA->show();
}

void JurassicSCADA::handleTemperatureChange()
{

	FileArray[6].readFileData(&ui);
}
//******************************************************************************************************************


//*********************************************  Monorail Button Logic  ********************************************
void JurassicSCADA::on_monorailbtn_clicked()
{
	ui.mainSCADA->hide();
	ui.monorailScreen->show();
	
}

void JurassicSCADA::on_monorailBackbtn_clicked()
{
	ui.monorailScreen->hide();
	ui.mainSCADA->show();
}

void JurassicSCADA::updatelblPowerStatus(bool powerStatus)
{
	if (powerStatus == true)
	{
		ui.lblPowerStatus->setText("<html><head/><body><p><img src=\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
		ui.lblPowerText->setText("Monorail Power: ON");
	}
	else
	{
		ui.lblPowerStatus->setText("<html><head/><body><p><img src=\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
		ui.lblPowerText->setText("Monorail Power: OFF");
	}
}

void JurassicSCADA::on_monorailPowerbtn_clicked()
{
	if (ui.lblPowerStatus->text() == "<html><head/><body><p><img src=\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>")
	{
		FileArray[9].readFileData(&ui);
		ui.lblPowerStatus->setText("<html><head/><body><p><img src=\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
		ui.lblPowerText->setText("Monorail Power: OFF");
	}
	else
	{
		FileArray[8].readFileData(&ui);
		ui.lblPowerStatus->setText("<html><head/><body><p><img src=\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
		ui.lblPowerText->setText("Monorail Power: ON");
	}
}

void JurassicSCADA::on_refuel1btn_clicked() 
{
	FileArray[7].readFileData(&ui);
	ui.lblFuelReserve1->setText(QString::number(100));
}

void JurassicSCADA::on_refuel2btn_clicked()
{
	FileArray[7].readFileData(&ui);
	ui.lblFuelReserve2->setText(QString::number(100));
}

void JurassicSCADA::on_refuel3btn_clicked()
{
	FileArray[7].readFileData(&ui);
	ui.lblFuelReserve3->setText(QString::number(100));
}

void JurassicSCADA::updateFuelReserves() {
	float currentFuelReserve1 = ui.lblFuelReserve1->text().toFloat();
	float currentFuelReserve2 = ui.lblFuelReserve2->text().toFloat();
	float currentFuelReserve3 = ui.lblFuelReserve3->text().toFloat();

	currentFuelReserve1 -= 0.01;
	currentFuelReserve2 -= 0.01;
	currentFuelReserve3 -= 0.01;

	ui.lblFuelReserve1->setText(QString::number(currentFuelReserve1));
	ui.lblFuelReserve2->setText(QString::number(currentFuelReserve2));
	ui.lblFuelReserve3->setText(QString::number(currentFuelReserve3));

	if (currentFuelReserve1 <= 0.01 || currentFuelReserve2 <= 0.01 || currentFuelReserve3 <= 0.01) {

	}
}

//******************************************************************************************************************
