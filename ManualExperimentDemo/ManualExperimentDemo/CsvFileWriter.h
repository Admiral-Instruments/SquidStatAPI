#pragma once
#include "qfile.h"
#include "DataLabels.h"
#include "AisDataStore.h"
#include "qlocale.h"

class CsvFileWriter
{
	QChar decimalPoint = QLocale().decimalPoint(); 
	QChar listSeparator = (decimalPoint == QChar(',')) ? ';' : ','; 
	
public:
	void SaveAcData(QFile&saveFile, AisDataMap &container) const;
	void SaveDcData(QFile &saveFile,AisDataMap &container) const;
	QString GetAcDataHeaderString() const;
	QString GetDcDataHeaderString() const;

	CsvFileWriter();
	~CsvFileWriter();
};

