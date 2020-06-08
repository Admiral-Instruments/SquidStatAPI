#pragma once
#include "qlist.h"
#include <QStandardPaths>

typedef struct {
	QString acFilePath;
	QString dcFilePath;
}ExpPreInfo;


class ExperimentSelector
{
public:
	ExperimentSelector();
	~ExperimentSelector();
	ExpPreInfo getNextExpInfo();

private:
	int nextIndex;
	QList<ExpPreInfo> expPreRequireData;
	
	void FillData();
};

