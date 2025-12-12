/*
 * button.h
 *
 *  Created on: Oct 28, 2025
 *      Author: admin
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern int button1_flag;
extern int button2_flag;
extern int button3_flag;
int isButton1Pressed();
int isButton2Pressed();
int isButton3Pressed();
void subKey1Process();
void subKey2Process();
void subKey3Process();
void getKeyInput();

#endif /* INC_BUTTON_H_ */
