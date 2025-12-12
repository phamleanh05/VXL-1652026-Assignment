/*
 * global.c
 *
 *  Created on: Nov 7, 2025
 *      Author: ATPHOME
 */
#include "global.h"

int mode = 0;

int RED_DURATION = 15;
int YELLOW_DURATION = 3;
int GREEN_DURATION = 12;

int traffic_state1;
int traffic_state2;
int counter1;
int counter2;
int light1 = LINE1_OFF;
int light2 = LINE2_OFF;
int switch_seg = 0;
int temp_red_time = 15;
int temp_yellow_time = 3;
int temp_green_time = 12;
int config_done_flag = 0;
