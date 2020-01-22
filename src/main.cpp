#include <stdio.h>
#include <time.h>
#include <string.h>
#include "screen_model.h"

void delay(int milliseconds);

ScreenModel_t currentScreen, nextScreen;
ScreenModel_t idleModel = {IDLE,	"IdleScreen",		"",		Idle,		2, 0, 0, 1};
ScreenModel_t nextModel = {NEXT,	"NextScreen",		"",		Idle, 		2, 0, 0, 1};
// ScreenModel_t nextModel = {NEXT,	"NextScreen",		"",		Idle, 		2, 0, 0, 1};

// const ScreenNav_t idleScreen = {NULL,		NULL,		&nextModel};
// const ScreenNav_t nextScreen = {NULL,		NULL,		&idleModel};

void delay(int milliseconds) {
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

int main() {
	currentScreen = idleModel;
	printf("%d title: %s\r\n", currentScreen.name, currentScreen.title);

	while(1) {
		switch(currentScreen.name) {
			case IDLE:
				nextScreen = nextModel;
				break;
			
			case NEXT:
				nextScreen = idleModel;
				break;
		}
		currentScreen = nextScreen;
		printf("%d title: %s\r\n", currentScreen.name, currentScreen.title);

		delay(2000);
	}

	return 0;
}
