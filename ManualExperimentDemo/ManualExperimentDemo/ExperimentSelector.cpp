#include "ExperimentSelector.h"


#define CSVFOLDER(nameOfFile) QStandardPaths::writableLocation(QStandardPaths::DesktopLocation)+QString("/csv/")+QString(nameOfFile)
ExperimentSelector::ExperimentSelector():nextIndex(0) {
	FillData();
}

//Load value is starting from small b to s;
void ExperimentSelector::FillData() {
	expPreRequireData = {
		//index 0
		{
         CSVFOLDER("ac_1.csv"),
         CSVFOLDER("dc_1.csv")
		}
		
		
	};
}

ExperimentSelector::~ExperimentSelector() {
}

ExpPreInfo ExperimentSelector::getNextExpInfo() {
	ExpPreInfo ret;
	if (nextIndex < expPreRequireData.count()) {
		ret = expPreRequireData.at(nextIndex);
		nextIndex++;
	}
	return ret;
}



