/*
 * trafficlight.c
 *
 *  Created on: Nov 8, 2025
 *      Author: ATPHOME
 */

#include "trafficlight.h"

void setTrafficLight1(int state) {
    switch (state) {
	case RED:
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin | LED_GREEN_1_Pin, SET);
		break;
	case YELLOW:
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin | LED_GREEN_1_Pin, SET);
		break;
	case GREEN:
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin | LED_YELLOW_1_Pin, SET);
		break;
    }
}

void setTrafficLight2(int state) {
    switch (state) {
	case RED:
		HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin | LED_GREEN_2_Pin, SET);
		break;
	case YELLOW:
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin | LED_GREEN_2_Pin, SET);
		break;
	case GREEN:
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin | LED_YELLOW_2_Pin, SET);
		break;
    }
}

void update7SEG_light1(int counter) {
    int tens = counter / 10;
    int units = counter % 10;

	if (switch_seg == 0) {
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, EN1_Pin, SET);

		display7SEG_traffic_light1(tens);

	} else {
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);

		display7SEG_traffic_light1(units);
	}
}

void update7SEG_light2(int counter) {
    int tens = counter / 10;
    int units = counter % 10;

	if (switch_seg == 0) {
		HAL_GPIO_WritePin(GPIOB, EN2_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, EN3_Pin, SET);

		display7SEG_traffic_light2(tens);

	} else {
		HAL_GPIO_WritePin(GPIOB, EN2_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, EN3_Pin, RESET);

		display7SEG_traffic_light2(units);
	}
}


int getNextState(int currentState) {
    switch(currentState) {
        case RED: return GREEN;
        case GREEN: return YELLOW;
        case YELLOW: return RED;
        default: return RED;
    }
}

int getDuration(int state) {
    switch(state) {
        case RED: return RED_DURATION;
        case GREEN: return GREEN_DURATION;
        case YELLOW: return YELLOW_DURATION;
        default: return RED_DURATION;
    }
}

void init(void){
	traffic_state1 = RED;
	traffic_state2 = GREEN;
	counter1 = RED_DURATION;
	counter2 = GREEN_DURATION;
	setTrafficLight1(traffic_state1);
	setTrafficLight2(traffic_state2);
}

void updateLight(int *state, int *counter, int *light){
    switch(*light){
    case LINE1_ON:
        *light = LINE1_OFF;
        setTrafficLight1(*state);
        update7SEG_light1(*counter);
        break;
    case LINE2_ON:
        *light = LINE2_OFF;
        setTrafficLight2(*state);
        update7SEG_light2(*counter);
        break;  // Added missing break
    }
}

void updateState(int *state, int *counter, int *light){
    if(*counter <= 0){
        *state = getNextState(*state);
        *counter = getDuration(*state);
        (*light)++;
        updateLight(state, counter, light);
    }
}

void blynk_7Seg(void){
    if (timer2_flag == 1) {
        setTimer2(50);
        switch_seg = 1 - switch_seg;
        update7SEG_light1(counter1);
        update7SEG_light2(counter2);
    }
}
void trafficLightRun(void) {
	blynk_7Seg();
    if (timer1_flag == 1) {
        setTimer1(100);
        counter1--;
        counter2--;

        updateState(&traffic_state1, &counter1, &light1);
        updateState(&traffic_state2, &counter2, &light2);
    }
}

void manualLight(void){
	if(traffic_state1 == YELLOW){
		traffic_state1 = GREEN;
		setTrafficLight1(traffic_state1);
	}
	if(traffic_state2 == YELLOW){
		traffic_state2 = GREEN;
		setTrafficLight2(traffic_state2);
	}
	if(isButton2Pressed() == 1){
		if(traffic_state1 == RED){
			traffic_state1 = GREEN;
			traffic_state2 = RED;
		} else if(traffic_state1 == GREEN) {
			traffic_state1 = RED;
			traffic_state2 = GREEN;
		}
		setTrafficLight1(traffic_state1);
		setTrafficLight2(traffic_state2);
	}
}

void blynk_light(int state, int duration){
	if (timer2_flag == 1) {
		setTimer2(50);
		switch_seg = 1 - switch_seg;
		setTrafficLight1(state);
		setTrafficLight2(state);
		update7SEG_light1(duration);
		update7SEG_light2(duration);
	}
}

void ConfigTimeREDLight(void){
	if (isButton2Pressed() == 1){
		temp_red_time++;
		if(temp_red_time > 99){
			temp_red_time = 1;
		}
	}

	blynk_light(RED, temp_red_time);
}

void setTimeREDLight() {
	ConfigTimeREDLight();
	if (isButton3Pressed() == 1){
		RED_DURATION = temp_red_time;
		config_done_flag = 1;
	}
}

void ConfigTimeGreenLight(void){
	if (isButton2Pressed() == 1){
		temp_green_time++;
		if(temp_green_time > RED_DURATION - YELLOW_DURATION){
			temp_green_time = 1;
		}
	}

	blynk_light(GREEN, temp_green_time);
}

void setTimeGreenLight() {
	ConfigTimeGreenLight();
	if (isButton3Pressed() == 1){
		GREEN_DURATION = temp_green_time;
		YELLOW_DURATION = RED_DURATION - GREEN_DURATION;
		config_done_flag = 1;
	}
}
