#ifndef NS_SCREEN_MODEL_H
#define NS_SCREEN_MODEL_H

#include <stdint.h>
#include <string.h>

typedef enum {
	ScrIdle_State,
	ScrNext_State,
} ScreenState_t;

typedef enum {
    BtnUp_Event,
    BtnDown_Event,
    BtnNext_Event,
} ScreenEvent_t;

typedef enum {
    Titled,
    Subtitled,
    Selector,
    Idle,
    IdleError,
    ActiveStatus,
    ActiveTotal,
    Debug,
    DebugError
} ScreenType_t;

typedef struct {
    uint8_t numberOfItems;
    uint8_t selected;
} ScreenSelector_t;

typedef struct {
    ScreenState_t state;
    char title[20];
    char subtitle[20];

    // ScreenSelector_t selector;
    ScreenType_t screenType;
    uint8_t refreshRate;
    
    uint8_t hasUpModel;
    uint8_t hasDownModel;
    uint8_t hasNextModel;
    // ICON icon;

} ScreenModel_t;

typedef struct {
    ScreenState_t upModel;
    ScreenState_t downModel;
    ScreenState_t nextModel;
    // const ScreenModel_t *upModel;
    // const ScreenModel_t *downModel;
    // const ScreenModel_t *nextModel;
} ScreenNav_t;

#endif
