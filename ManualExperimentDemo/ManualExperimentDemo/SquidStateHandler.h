#pragma once
#include "AisSquidstat.h"
#include "ExpDataNotifier.h"
#include "ExperimentSelector.h"
#include "TimerClass.h"
#include "Experiment.h"

class TimerClass;
class ExpDataNotifier;
class SquidStateHandler
{
private:
	AisSquidstat* handler = nullptr;
	QStringList connectedDevice;
	QStringList customExperiments;
	TimerClass* timerStarter = nullptr;

	ExpDataNotifier* eventHandler;
	AisDeviceSetting* deviceSettings;
	Experiment* exp;

	ExperimentSelector* expSelector;
	
	void startAlltimers();
	void startManualExperiment();
	bool FillAppData();

public:
     void addInstrumnets(QString);
     void instrumentRemove(QString);

	 void PauseExperiment(QUuid);
	 void ResumeExperiment(QUuid);
	 void StopExperiment(QUuid);
	 void ACDataExperiment(QUuid);
	 void DCDataExperiment(QUuid);


	 void PauseExperimentRequested();
	 void ResumeExperimentRequested();
	 void StopExperimentRequested();

	SquidStateHandler();
	~SquidStateHandler();
};

