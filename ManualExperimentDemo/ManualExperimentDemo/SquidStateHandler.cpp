#include "SquidStateHandler.h"
#include <QThread>
#include "qdebug.h"

#define SQUIDSTAT_PORT_NAME ""
#define DEVICE_NAME	"Plus1209"
#define DOCUMENT_DIR "/Users/coltor/Documents/Admiral Instruments"
#define PATH_TO_SQUIDSTAT_EXPERIMENT_TILES "/Users/coltor/Dev/LabviewApplication/Sample_Projects/ManualExperimentDemo/Admiral/SquidStatDLL/Release/elements"

SquidStateHandler::SquidStateHandler()
{
	handler = AisSquidstat::getInstance();

	expSelector = new ExperimentSelector();
	eventHandler = new ExpDataNotifier(this);
	timerStarter = new TimerClass(this);
    handler->registerGlobalNotifier(eventHandler);
    FillAppData();


}
SquidStateHandler::~SquidStateHandler()
{
	delete timerStarter;
	delete expSelector;
	delete eventHandler;
}


bool SquidStateHandler::FillAppData() {
    bool ret = false;
    if (handler == nullptr) {
        return ret;
    }

    auto errorFlag = handler->setAppDocumentDir(DOCUMENT_DIR);
    if (errorFlag != AisStatus::NO_ERROR) {
        return ret;
    }

    handler->LoadBuilderElements(PATH_TO_SQUIDSTAT_EXPERIMENT_TILES);

    errorFlag = handler->getCustomExperiments(customExperiments);
    if (errorFlag != AisStatus::NO_ERROR) {
		qDebug() << customExperiments << "is not found in experiment list. Error code  is " << errorFlag;
        return ret;
    }

    handler->connectNewDeviceAt(SQUIDSTAT_PORT_NAME);

    ret = true;
    return ret;
}


void SquidStateHandler::startManualExperiment() {
    qDebug() << "Manual experiment started";

	auto expInfoData = expSelector->getNextExpInfo();

	if ( expInfoData.acFilePath.isEmpty() ||
		expInfoData.dcFilePath.isEmpty()) {
		handler->closeApplication();
		return;
	}

	auto deviceName = DEVICE_NAME;
	auto channelNumber = 0;

	if (!connectedDevice.contains(deviceName)) {
		qDebug() << deviceName << "is not found";
		return;
	}

	deviceSettings = new AisDeviceSetting(deviceName, channelNumber);
	exp = new Experiment(deviceSettings, eventHandler);
	exp->createACDataFile(expInfoData.acFilePath);
	exp->createDCDataFile(expInfoData.dcFilePath);

	auto errorFlag = handler->startManualExperimentM(exp->getManualExperiment());

	if (errorFlag != AisStatus::NO_ERROR) {
        delete exp;
		delete deviceSettings;
	}

	startAlltimers();
}

void SquidStateHandler::addInstrumnets(QString deviceName) {
	qDebug() << "device is added : " << deviceName;
    connectedDevice << deviceName;
	startManualExperiment();
}
void SquidStateHandler::instrumentRemove(QString deviceName) {
    auto index = connectedDevice.indexOf(deviceName);
    if (index != -1) {
        connectedDevice.removeAt(index);
    }
}

void SquidStateHandler::PauseExperiment(QUuid id) {
	if (exp->getUniqueId() == id) {
		qDebug() << "ack: Pause Manual Experiment";
	}
}
void SquidStateHandler::ResumeExperiment(QUuid id) {
	if (exp->getUniqueId() == id) {
		qDebug() << "ack: Resume Manual Experiment";
	}
}
void SquidStateHandler::StopExperiment(QUuid id) {
	qDebug() << "ack: stop Manual Experiment";
	if (exp->getUniqueId() == id) {
		delete exp;
		delete deviceSettings;
	}

	handler->closeApplication();
}
void SquidStateHandler::ACDataExperiment(QUuid id) {
	if (exp->getUniqueId() == id) {
		exp->WriteACExperimentData();
	}
}
void SquidStateHandler::DCDataExperiment(QUuid id) {
	if (exp->getUniqueId() == id) {
		exp->WriteDCExperimentData();
	}
}


void SquidStateHandler::PauseExperimentRequested() {
	auto errorFlag = handler->pauseExperiment(exp->getUniqueId());

	if (errorFlag != AisStatus::NO_ERROR) {
		delete exp;
		delete deviceSettings;
	}
	qDebug() << "Request: Pause Manual Experiment ";
}
void SquidStateHandler::ResumeExperimentRequested() {
	auto errorFlag = handler->resumeExperiment(exp->getUniqueId());

	if (errorFlag != AisStatus::NO_ERROR) {
		delete exp;
		delete deviceSettings;
	}
	qDebug() << "Request: Resume Manual Experiment ";
}
void SquidStateHandler::StopExperimentRequested() {
	auto errorFlag = handler->stopManualExperimentM(exp->getUniqueId());

	if (errorFlag != AisStatus::NO_ERROR) {
        qDebug() << "Error";
		delete exp;
		delete deviceSettings;
	}
	qDebug() << "Request: stop Manual Experiment ";

}

void SquidStateHandler::startAlltimers() {
    timerStarter->stopTimerStart();
    timerStarter->pauseTimerStart();
	timerStarter->resumeTimerStart();
}
