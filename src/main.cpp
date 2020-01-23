#include <stdio.h>
#include <time.h>
#include <string.h>
#include "screen_model.h"

void delay(int milliseconds);

ScreenEvent_t btnEvent;
ScreenModel_t scrNextState;
ScreenModel_t idleModel = {ScrIdle_State, "IdleScreen",		"",		Idle,		2, 0, 0, 1};
ScreenModel_t nextModel = {ScrNext_State, "NextScreen",		"",		Idle, 		2, 0, 0, 1};
// ScreenModel_t nextModel = {NEXT,	"NextScreen",		"",		Idle, 		2, 0, 0, 1};

// const ScreenNav_t idleScreen = {NULL,		NULL,		&nextModel};
// const ScreenNav_t nextScreen = {NULL,		NULL,		&idleModel};

ScreenModel_t getNextState(ScreenState_t screen, ScreenEvent_t btn) {
	ScreenModel_t nextScreen;

	switch(screen) {
		case ScrIdle_State:
			if (btn == BtnNext_Event) {
				return idleModel;
			}
 			break;

		case ScrNext_State:
			break;

		default:
			break;
	}

	return idleModel;
}

void delay(int milliseconds) {
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

int main() {
	scrNextState = idleModel;
	btnEvent = BtnNext_Event;
	printf("%d title: %s\r\n", scrNextState.state, scrNextState.title);

	while(1) {
		scrNextState = getNextState(scrNextState.state, btnEvent);
		printf("%d title: %s\r\n", scrNextState.state, scrNextState.title);
		delay(2000);
	}

	return 0;
}


/* 
Simple scheduler

// run the scheduler after initialization is complete
LastScheduleTime = TimeNow()

Loop forever:
	if TimePassed(LastScheduleTime) > ONE_SECOND
		// Run the scheduler, it will call the functions (tasks) when they are due
		LastScheduleTime = TimeNow()

struct Task;
typedef void (*TaskCallback)(struct Task *);

typedef struct Task {
	tTime runNextAt;				// next timer tick at which to run this task
	tTime timeBetweenRuns;			// for periodic tasks
	TaskCallback callback;
	int enabled;					// current status
};

void TaskResetPeriodic(struct Task *t);
void TaskSetNextTime(struct Task *t, tTime timeFromNow, tTime now);
void TaskDisable(struct Task *t);

void SchedulerRun(tTime now);
void SchedulerAddTask(struct Task *t);
 */


/* 
Table-driven State machine

struct sStateTableEntry {
	tLight light;				// all states have associated lights
	tState goEvent;				// state to enter when go event occurs
	tState stopEvent;			// when stop event occurs
	tState timeoutEvent;		// when timeout occurs
}

// event handler
void HandleEventGo(struct sStateTableEntry *currentState) {
	// turn off the light (unless we're just going to turn it back on)
	if (currentState->light != currentState->go.light) {
		LightOff(currentState->light);
	}
	currentState = currentState->go;
	LightOn(currentState->light);
	StartTimer();
}

typedef enum { kRedState = 0, kYellowState = 1, kGreenState = 2 } tState;

struct sStateTableEntry stateTable[] = {
	{ kRedLight,	kGreenState,	kRedState,		kRedState },
	{ kYellowLight,	kYellowState,	kYellowState,	kRedState },
	{ kGreenLight,	kGreenState,	kYellowState,	kGreenState },
}

 */
