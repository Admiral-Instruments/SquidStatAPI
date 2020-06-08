#pragma once
#include "qtimer.h"
#include "SquidStateHandler.h"
class SquidStateHandler;
class TimerClass
{
public:
	TimerClass(SquidStateHandler*);
	void stopTimerStart();
	void resumeTimerStart();
	void pauseTimerStart();

private:
	SquidStateHandler* handler;
};
