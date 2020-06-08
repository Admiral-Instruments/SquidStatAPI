#pragma once
#include "AisManualExperimentInfo.h"
#include "CsvFileWriter.h"
#include "qfile.h"

class Experiment
{
public:
	void WriteDCExperimentData();
	void WriteACExperimentData();
	AisManualExperimentInfo* getManualExperiment();
	QUuid getUniqueId();
	void createACDataFile(QString filePath);
	void createDCDataFile(QString filePath);

	Experiment(AisDeviceSetting* deviceSettings, AisSquidstatNotifier* eventHandler);
	~Experiment();

private:
	AisManualExperimentInfo* exp = nullptr;
	CsvFileWriter* writer = nullptr;
	QFile *Acfile = nullptr;
	QFile *Dcfile = nullptr;
};

