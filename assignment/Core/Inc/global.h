/*
 * global.h
 *
 *  Created on: Nov 7, 2025
 *      Author: ATPHOME
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"

#define AUTO		1
#define MANUAL		2
#define SET_RED		3
#define SET_GREEN	4

#define LINE1_OFF	1
#define LINE1_ON	2
#define LINE2_OFF	11
#define LINE2_ON	12

extern int RED_DURATION;
extern int YELLOW_DURATION;
extern int GREEN_DURATION;

extern int temp_red_time;
extern int temp_yellow_time;
extern int temp_green_time;

#define RED 0
#define YELLOW 1
#define GREEN 2

extern int config_done_flag;
extern int mode;
extern int switch_seg;
extern int traffic_state1;
extern int traffic_state2;
extern int counter1;
extern int counter2;
extern int light1;
extern int light2;

#endif /* INC_GLOBAL_H_ */
