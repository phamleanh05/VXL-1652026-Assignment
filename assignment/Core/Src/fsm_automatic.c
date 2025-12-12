/*
 * fsm_automatic.c
 *
 *  Created on: Nov 7, 2025
 *      Author: ATPHOME
 */

#include "fsm_automatic.h"

void fsm_mode(){
	switch(mode){
	case AUTO:
		trafficLightRun();
		display7SEG_Mode(AUTO);
		break;
	case MANUAL:
	    HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin, SET);
	    HAL_GPIO_WritePin(GPIOB, EN2_Pin | EN3_Pin, SET);
		manualLight();
		display7SEG_Mode(MANUAL);
		break;
	case SET_RED:
		setTimeREDLight();
		display7SEG_Mode(SET_RED);
		if(config_done_flag == 1){
			config_done_flag = 0;
			mode = SET_GREEN;
		}
		break;
	case SET_GREEN:
		setTimeGreenLight();
		display7SEG_Mode(SET_GREEN);
		if(config_done_flag == 1){
			config_done_flag = 0;
			mode = AUTO;
			init();
		}
		break;
	default:
		mode = AUTO;
		break;
	}
}
