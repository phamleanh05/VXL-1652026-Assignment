/*
 * button.c
 *
 *  Created on: Oct 28, 2025
 *      Author: admin
 */
#include "button.h"

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;
int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;

int KeyReg00 = NORMAL_STATE;
int KeyReg01 = NORMAL_STATE;
int KeyReg02 = NORMAL_STATE;
int KeyReg03 = NORMAL_STATE;

int KeyReg10 = NORMAL_STATE;
int KeyReg11 = NORMAL_STATE;
int KeyReg12 = NORMAL_STATE;
int KeyReg13 = NORMAL_STATE;

int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}

int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}

int isButton3Pressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}

void subKey1Process(){
	//TODO
	button1_flag = 1;
}

void subKey2Process(){
	//TODO
	button2_flag = 1;
}

void subKey3Process(){
	//TODO
	button3_flag = 1;
}

void getKeyInput(){
	//Button 1
	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
	if (KeyReg0 == KeyReg1 && KeyReg1 == KeyReg2){
		 if(KeyReg3 != KeyReg2){
			 KeyReg3 = KeyReg2;
			 if(KeyReg2 == PRESSED_STATE){
				 subKey1Process();
			 }
		 }
	}
	//Button 2
	KeyReg00 = KeyReg01;
	KeyReg01 = KeyReg02;
	KeyReg02 = HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
	if (KeyReg00 == KeyReg01 && KeyReg01 == KeyReg02){
		 if(KeyReg03 != KeyReg02){
			 KeyReg03 = KeyReg02;
			 if(KeyReg02 == PRESSED_STATE){
				 subKey2Process();
			 }
		 }
	}
	//Button 3
	KeyReg10 = KeyReg11;
	KeyReg11 = KeyReg12;
	KeyReg12 = HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin);
	if (KeyReg10 == KeyReg11 && KeyReg11 == KeyReg12){
		 if(KeyReg13 != KeyReg12){
			 KeyReg13 = KeyReg12;
			 if(KeyReg12 == PRESSED_STATE){
				 subKey3Process();
			 }
		 }
	}
}
