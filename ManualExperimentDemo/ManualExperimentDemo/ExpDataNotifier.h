#pragma once
#include "AisSquidstatNotifier.h"
#include "SquidStateHandler.h"


class SquidStateHandler;
class ExpDataNotifier:public AisSquidstatNotifier
{
public:
	ExpDataNotifier(SquidStateHandler*);
	~ExpDataNotifier();

    void instrumentReadyToUse(QString);
    void instrumentDisconnected(QString);
	 void experimentStopped(QUuid);
	 void experimentPaused(QUuid);
	 void experimentResumed(QUuid);
	 void readDCExperimentData(QUuid);
	 void readACExperimentData(QUuid);

private:
	SquidStateHandler* handler;

};

