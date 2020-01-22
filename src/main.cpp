#include <stdio.h>
#include <time.h>
#include <string.h>
#include "screen_model.h"

void delay(int milliseconds);

ScreenModel_t scrNextState;
ScreenEvent_t btnEvent;
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
				return 
			}
 			break;

		case ScrNext_State:
			break;

		default:
			break;
	}

	return 
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
