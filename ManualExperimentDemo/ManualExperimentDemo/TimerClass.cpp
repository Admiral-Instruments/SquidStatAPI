
#include "TimerClass.h"
#include "qdebug.h"

TimerClass::TimerClass(SquidStateHandler* _handler):handler(_handler) {
}
void TimerClass::stopTimerStart() {
    QTimer::singleShot(120000, [=]() {
        handler->StopExperimentRequested();
    });
}

void TimerClass::resumeTimerStart() {
    QTimer::singleShot(60000, [=]() {
        handler->ResumeExperimentRequested();
    });
}

void TimerClass::pauseTimerStart() {
    QTimer::singleShot(30000, [=]() {
        handler->PauseExperimentRequested();
    });
}








