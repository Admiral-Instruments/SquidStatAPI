#include "CsvFileWriter.h"

#define SAVE_DATA(varName)	\
	saveFile.write(prevChar.toLatin1()); \
	saveFile.write(QString("%1").arg(container[varName].lastDataPoint(), 0, 'g', 10).replace(QChar('.'), decimalPoint).toLatin1()); \
	prevChar = listSeparator;

#define SAVE_DATA_TEXT(varName)	\
	saveFile.write(prevChar.toLatin1()); \
	saveFile.write(container[varName].lastStringData().toLatin1()); \
	prevChar = listSeparator;

#define SAVE_DATA_END() \
	saveFile.write("\n"); \
	saveFile.flush();


CsvFileWriter::CsvFileWriter() {
	
}


CsvFileWriter::~CsvFileWriter()
{
}

void CsvFileWriter::SaveDcData(QFile &saveFile,AisDataMap &container) const {
	QString prevChar = "";

	if (!container[CURRENT_NODE_NAME].isStringDataListEmpty())
	{
		SAVE_DATA_TEXT(CURRENT_NODE_NUMBER);
		SAVE_DATA_TEXT(CURRENT_NODE_NAME);
	}
	else
	{
		saveFile.write(prevChar.toLatin1()); saveFile.write(QString("").toLatin1()); prevChar = listSeparator;
		saveFile.write(prevChar.toLatin1()); saveFile.write(QString("").toLatin1()); prevChar = listSeparator;
	}

	//SAVE_DATA(PLOT_VAR_ELAPSED_TIME_HR);
	SAVE_DATA(DCDATA_ELAPSED_TIME_S);
	SAVE_DATA(DCDATA_WORKING_ELECTRODE);
	SAVE_DATA(DCDATA_WORKING_ELECTRODE_V_NHE);
	SAVE_DATA(DCDATA_CURRENT);
	SAVE_DATA(DCDATA_CURRENT_DENSITY);
	SAVE_DATA(DCDATA_CUMU_CHARGE_MAH);
	SAVE_DATA(DCDATA_COUNTER_ELECTRODE);

	SAVE_DATA_END();
};

void CsvFileWriter::SaveAcData(QFile&saveFile, AisDataMap &container) const {
	QString prevChar = "";


	SAVE_DATA_TEXT(CURRENT_NODE_NUMBER);
	SAVE_DATA_TEXT(CURRENT_NODE_NAME);
	SAVE_DATA(ACDATA_ELAPSED_TIME_S);
	SAVE_DATA(ACDATA_WE_BIAS);
	SAVE_DATA(ACDATA_I_BIAS);
	SAVE_DATA(ACDATA_FREQ);
	SAVE_DATA(ACDATA_IMPEDANCE);
	SAVE_DATA(ACDATA_PHASE);
	SAVE_DATA(ACDATA_IMP_REAL);
	SAVE_DATA(ACDATA_NEG_IMP_IMAG);
	SAVE_DATA(ACDATA_TOTAL_HARMONIC_DIST);
	SAVE_DATA(ACDATA_AMPLITUDE);
	SAVE_DATA(ACDATA_NO_OF_CYCLES);
	SAVE_DATA(ACDATA_DURATION_OF_EACH_FREQUENCY);
	SAVE_DATA_END();
}

static QString FormatHeaderString(QString str, bool isFirstHeader = false) {
	static QChar listSeparator = (QLocale().decimalPoint() == QChar(',')) ? ';' : ',';
	QString ret = "";
	if (!isFirstHeader) {
		ret += listSeparator;
	}
	ret += QString("\"%1\"").arg(str.replace("\"", "\"\""));
	return ret;
};

QString CsvFileWriter::GetAcDataHeaderString() const {
	QString ret = "";
	ret += FormatHeaderString(CURRENT_NODE_NUMBER, true);
	ret += FormatHeaderString(CURRENT_NODE_NAME);
	ret += FormatHeaderString(ACDATA_ELAPSED_TIME_S);
	ret += FormatHeaderString(ACDATA_WE_BIAS);
	ret += FormatHeaderString(ACDATA_I_BIAS);
	ret += FormatHeaderString(ACDATA_FREQ);
	ret += FormatHeaderString(ACDATA_IMP_REAL);
	ret += FormatHeaderString(ACDATA_PHASE);
	ret += FormatHeaderString(ACDATA_IMP_IMAG);
	ret += FormatHeaderString(ACDATA_NEG_IMP_IMAG);
	ret += FormatHeaderString(ACDATA_TOTAL_HARMONIC_DIST);
	ret += FormatHeaderString(ACDATA_AMPLITUDE);
	ret += FormatHeaderString(ACDATA_NO_OF_CYCLES);
	ret += FormatHeaderString(ACDATA_DURATION_OF_EACH_FREQUENCY);
	
	ret += "\r\n";
	return ret;
};

QString CsvFileWriter::GetDcDataHeaderString() const {
	QString ret = "";
	ret += FormatHeaderString(CURRENT_NODE_NUMBER, true);
	ret += FormatHeaderString(CURRENT_NODE_NAME);
	//ret += FormatHeaderString(PLOT_VAR_ELAPSED_TIME_HR);
	ret += FormatHeaderString(DCDATA_ELAPSED_TIME_S);
	ret += FormatHeaderString(DCDATA_WORKING_ELECTRODE);
	ret += FormatHeaderString(DCDATA_WORKING_ELECTRODE_V_NHE);
	ret += FormatHeaderString(DCDATA_CURRENT);
	ret += FormatHeaderString(DCDATA_CURRENT_DENSITY);
	ret += FormatHeaderString(DCDATA_CUMU_CHARGE_MAH);
	ret += FormatHeaderString(DCDATA_COUNTER_ELECTRODE);

	ret += "\r\n";
	return ret;
};