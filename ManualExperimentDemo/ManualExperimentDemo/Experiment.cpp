#include "Experiment.h"
#include <QDebug>

Experiment::Experiment(AisDeviceSetting* deviceSettings, AisSquidstatNotifier* eventHandler)	 {
	exp = new AisManualExperimentInfo(deviceSettings, eventHandler);
	writer = new CsvFileWriter();
}


Experiment::~Experiment()
{
	if (Acfile != nullptr) {
		Acfile->close();
		Acfile->deleteLater();
	}
	if (Dcfile != nullptr) {
		Dcfile->close();
		Dcfile->deleteLater();
	}
	delete writer;
	delete exp;
}

void Experiment::WriteDCExperimentData() {
	writer->SaveDcData(*Dcfile, exp->container);
}
void Experiment::WriteACExperimentData() {
	writer->SaveAcData(*Acfile, exp->container);
}

AisManualExperimentInfo* Experiment::getManualExperiment() {
	AisManualExperimentInfo* ret = nullptr;
	if (exp) {
		ret = exp;
	}
	return ret;
}

QUuid Experiment::getUniqueId() {
	return exp->getExperimentID();
}

void Experiment::createACDataFile(QString filePath) {
	Acfile = new QFile(filePath);
	if (!Acfile->open(QIODevice::WriteOnly)) {
		Acfile->deleteLater();
		return;
	}
	Acfile->write(writer->GetAcDataHeaderString().toLatin1());
}

void Experiment::createDCDataFile(QString filePath) {
	Dcfile = new QFile(filePath);
	if (!Dcfile->open(QIODevice::WriteOnly)) {
		Dcfile->deleteLater();
		return;
	}
	Dcfile->write(writer->GetDcDataHeaderString().toLatin1());
}
