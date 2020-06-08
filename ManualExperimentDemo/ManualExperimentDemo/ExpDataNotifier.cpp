#include "ExpDataNotifier.h"



ExpDataNotifier::ExpDataNotifier(SquidStateHandler* _handler):handler(_handler)
{	
}

ExpDataNotifier::~ExpDataNotifier()
{
}

/*
 *  The Squidstat Device outputs signals which are caught by the ExpDataNotifier
 *  which then is responsible for instructing the handler to execute
 *  code corresponding to the appropriate output by the device.
*/
void ExpDataNotifier::readDCExperimentData(QUuid id) {
    handler->DCDataExperiment(id); // saves DC data to DC data file.
}
void ExpDataNotifier::readACExperimentData(QUuid id) {
    handler->ACDataExperiment(id); // saves AC data to AC data file
                                   // (not executed in manual experiments)
}
void ExpDataNotifier::experimentStopped(QUuid id) {
	handler->StopExperiment(id);
}
void ExpDataNotifier::experimentPaused(QUuid id) {
	handler->PauseExperiment(id);
}
void ExpDataNotifier::experimentResumed(QUuid id) {
	handler->ResumeExperiment(id);
}
void ExpDataNotifier::instrumentReadyToUse(QString newDevice) {
    handler->addInstrumnets(newDevice);
}
void ExpDataNotifier::instrumentDisconnected(QString removeDevice) {
    handler->instrumentRemove(removeDevice);
}
