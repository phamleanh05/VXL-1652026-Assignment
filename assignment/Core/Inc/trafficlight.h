/*
 * traffic.h
 *
 *  Created on: Nov 8, 2025
 *      Author: ATPHOME
 */

#ifndef INC_TRAFFICLIGHT_H_
#define INC_TRAFFICLIGHT_H_

#include "global.h"
#include "software_timer.h"
#include "display7segment.h"

void setTrafficLight1(int state);
void setTrafficLight2(int state);
void update7SEG_light1(int counter);
void update7SEG_light2(int counter);
int getNextState(int currentState);
int getDuration(int state);
void updateTrafficLights(int state1, int counter1, int state2, int counter2);
void init(void);
void updateLight(int *state, int *counter, int *light);
void updateState(int *state, int *counter, int *light);
void blynk_7Seg(void);

void trafficLightRun(void);

void manualLight(void);

void blynk_light(int state, int duration);

void ConfigTimeREDLight(void);
void setTimeREDLight(void);

void ConfigTimeGreenLight(void);
void setTimeGreenLight(void);

#endif /* INC_TRAFFICLIGHT_H_ */
