/*
 * display7segment.c
 *
 *  Created on: Nov 8, 2025
 *      Author: ATPHOME
 */
#include "display7segment.h"

void display7SEG_Mode(int num) {
    if (num < 1 || num > 4) num = 1;
    switch (num){
    case 1:
        HAL_GPIO_WritePin(GPIOA, SEG2_0_Pin | SEG2_3_Pin | SEG2_4_Pin | SEG2_5_Pin | SEG2_6_Pin, SET);
        HAL_GPIO_WritePin(GPIOA, SEG2_1_Pin | SEG2_2_Pin, RESET);
        break;

    case 2:
        HAL_GPIO_WritePin(GPIOA, SEG2_2_Pin | SEG2_5_Pin, SET);
        HAL_GPIO_WritePin(GPIOA, SEG2_0_Pin | SEG2_1_Pin | SEG2_3_Pin | SEG2_4_Pin | SEG2_6_Pin, RESET);
        break;

    case 3:
        HAL_GPIO_WritePin(GPIOA, SEG2_4_Pin | SEG2_5_Pin, SET);
        HAL_GPIO_WritePin(GPIOA, SEG2_0_Pin | SEG2_1_Pin | SEG2_2_Pin | SEG2_3_Pin | SEG2_6_Pin, RESET);
        break;

    case 4:
        HAL_GPIO_WritePin(GPIOA, SEG2_0_Pin | SEG2_3_Pin | SEG2_4_Pin, SET);
        HAL_GPIO_WritePin(GPIOA, SEG2_1_Pin | SEG2_2_Pin | SEG2_5_Pin | SEG2_6_Pin, RESET);
        break;

    default:
        break;
    }
}

void display7SEG_traffic_light2(int num){
    if (num < 0 || num > 9) num = 0;

    switch (num){
    case 0:  // Hiển thị số 0: segment a,b,c,d,e,f sáng
        HAL_GPIO_WritePin(GPIOB, SEG0_6_Pin, SET);  // Tắt g
        HAL_GPIO_WritePin(GPIOB, SEG0_0_Pin | SEG0_1_Pin | SEG0_2_Pin | SEG0_3_Pin | SEG0_4_Pin | SEG0_5_Pin, RESET);
        break;

    case 1:  // Hiển thị số 1: segment b,c sáng
        HAL_GPIO_WritePin(GPIOB, SEG0_0_Pin | SEG0_3_Pin | SEG0_4_Pin | SEG0_5_Pin | SEG0_6_Pin, SET);
        HAL_GPIO_WritePin(GPIOB, SEG0_1_Pin | SEG0_2_Pin, RESET);
        break;

    case 2:  // Hiển thị số 2: segment a,b,d,e,g sáng
        HAL_GPIO_WritePin(GPIOB, SEG0_2_Pin | SEG0_5_Pin, SET);
        HAL_GPIO_WritePin(GPIOB, SEG0_0_Pin | SEG0_1_Pin | SEG0_3_Pin | SEG0_4_Pin | SEG0_6_Pin, RESET);
        break;

    case 3:  // Hiển thị số 3: segment a,b,c,d,g sáng
        HAL_GPIO_WritePin(GPIOB, SEG0_4_Pin | SEG0_5_Pin, SET);  // Tắt e,f
        HAL_GPIO_WritePin(GPIOB, SEG0_0_Pin | SEG0_1_Pin | SEG0_2_Pin | SEG0_3_Pin | SEG0_6_Pin, RESET);
        break;

    case 4:  // Hiển thị số 4: segment b,c,f,g sáng
        HAL_GPIO_WritePin(GPIOB, SEG0_0_Pin | SEG0_3_Pin | SEG0_4_Pin, SET);  // Tắt a,d,e
        HAL_GPIO_WritePin(GPIOB, SEG0_1_Pin | SEG0_2_Pin | SEG0_5_Pin | SEG0_6_Pin, RESET);
        break;

    case 5:  // Hiển thị số 5: segment a,c,d,f,g sáng
        HAL_GPIO_WritePin(GPIOB, SEG0_1_Pin | SEG0_4_Pin, SET);  // Tắt b,e
        HAL_GPIO_WritePin(GPIOB, SEG0_0_Pin | SEG0_2_Pin | SEG0_3_Pin | SEG0_5_Pin | SEG0_6_Pin, RESET);
        break;

    case 6:  // Hiển thị số 6: segment a,c,d,e,f,g sáng
        HAL_GPIO_WritePin(GPIOB, SEG0_1_Pin, SET);  // Tắt b
        HAL_GPIO_WritePin(GPIOB, SEG0_0_Pin | SEG0_2_Pin | SEG0_3_Pin | SEG0_4_Pin | SEG0_5_Pin | SEG0_6_Pin, RESET);
        break;

    case 7:  // Hiển thị số 7: segment a,b,c sáng
        HAL_GPIO_WritePin(GPIOB, SEG0_3_Pin | SEG0_4_Pin | SEG0_5_Pin | SEG0_6_Pin, SET);  // Tắt d,e,f,g
        HAL_GPIO_WritePin(GPIOB, SEG0_0_Pin | SEG0_1_Pin | SEG0_2_Pin, RESET);
        break;

    case 8:  // Hiển thị số 8: tất cả segment sáng
        HAL_GPIO_WritePin(GPIOB, SEG0_0_Pin | SEG0_1_Pin | SEG0_2_Pin | SEG0_3_Pin | SEG0_4_Pin | SEG0_5_Pin | SEG0_6_Pin, RESET);
        break;

    case 9:  // Hiển thị số 9: segment a,b,c,d,f,g sáng
        HAL_GPIO_WritePin(GPIOB, SEG0_4_Pin, SET);  // Tắt e
        HAL_GPIO_WritePin(GPIOB, SEG0_0_Pin | SEG0_1_Pin | SEG0_2_Pin | SEG0_3_Pin | SEG0_5_Pin | SEG0_6_Pin, RESET);
        break;

    default:
        break;
    }
}

void display7SEG_traffic_light1(int num){
    if (num < 0 || num > 9) num = 0;
    switch (num){
    case 0:  // Hiển thị số 0: segment a,b,c,d,e,f sáng
        HAL_GPIO_WritePin(GPIOB, SEG1_6_Pin, SET);  // Tắt g
        HAL_GPIO_WritePin(GPIOB, SEG1_0_Pin | SEG1_1_Pin | SEG1_2_Pin | SEG1_3_Pin | SEG1_4_Pin | SEG1_5_Pin, RESET);
        break;

    case 1:  // Hiển thị số 1: segment b,c sáng
        HAL_GPIO_WritePin(GPIOB, SEG1_0_Pin | SEG1_3_Pin | SEG1_4_Pin | SEG1_5_Pin | SEG1_6_Pin, SET);
        HAL_GPIO_WritePin(GPIOB, SEG1_1_Pin | SEG1_2_Pin, RESET);
        break;

    case 2:  // Hiển thị số 2: segment a,b,d,e,g sáng
        HAL_GPIO_WritePin(GPIOB, SEG1_2_Pin | SEG1_5_Pin, SET);
        HAL_GPIO_WritePin(GPIOB, SEG1_0_Pin | SEG1_1_Pin | SEG1_3_Pin | SEG1_4_Pin | SEG1_6_Pin, RESET);
        break;

    case 3:  // Hiển thị số 3: segment a,b,c,d,g sáng
        HAL_GPIO_WritePin(GPIOB, SEG1_4_Pin | SEG1_5_Pin, SET);  // Tắt e,f
        HAL_GPIO_WritePin(GPIOB, SEG1_0_Pin | SEG1_1_Pin | SEG1_2_Pin | SEG1_3_Pin | SEG1_6_Pin, RESET);
        break;

    case 4:  // Hiển thị số 4: segment b,c,f,g sáng
        HAL_GPIO_WritePin(GPIOB, SEG1_0_Pin | SEG1_3_Pin | SEG1_4_Pin, SET);  // Tắt a,d,e
        HAL_GPIO_WritePin(GPIOB, SEG1_1_Pin | SEG1_2_Pin | SEG1_5_Pin | SEG1_6_Pin, RESET);
        break;

    case 5:  // Hiển thị số 5: segment a,c,d,f,g sáng
        HAL_GPIO_WritePin(GPIOB, SEG1_1_Pin | SEG1_4_Pin, SET);  // Tắt b,e
        HAL_GPIO_WritePin(GPIOB, SEG1_0_Pin | SEG1_2_Pin | SEG1_3_Pin | SEG1_5_Pin | SEG1_6_Pin, RESET);
        break;

    case 6:  // Hiển thị số 6: segment a,c,d,e,f,g sáng
        HAL_GPIO_WritePin(GPIOB, SEG1_1_Pin, SET);  // Tắt b
        HAL_GPIO_WritePin(GPIOB, SEG1_0_Pin | SEG1_2_Pin | SEG1_3_Pin | SEG1_4_Pin | SEG1_5_Pin | SEG1_6_Pin, RESET);
        break;

    case 7:  // Hiển thị số 7: segment a,b,c sáng
        HAL_GPIO_WritePin(GPIOB, SEG1_3_Pin | SEG1_4_Pin | SEG1_5_Pin | SEG1_6_Pin, SET);  // Tắt d,e,f,g
        HAL_GPIO_WritePin(GPIOB, SEG1_0_Pin | SEG1_1_Pin | SEG1_2_Pin, RESET);
        break;

    case 8:  // Hiển thị số 8: tất cả segment sáng
        HAL_GPIO_WritePin(GPIOB, SEG1_0_Pin | SEG1_1_Pin | SEG1_2_Pin | SEG1_3_Pin | SEG1_4_Pin | SEG1_5_Pin | SEG1_6_Pin, RESET);
        break;

    case 9:  // Hiển thị số 9: segment a,b,c,d,f,g sáng
        HAL_GPIO_WritePin(GPIOB, SEG1_4_Pin, SET);  // Tắt e
        HAL_GPIO_WritePin(GPIOB, SEG1_0_Pin | SEG1_1_Pin | SEG1_2_Pin | SEG1_3_Pin | SEG1_5_Pin | SEG1_6_Pin, RESET);
        break;

    default:
        break;
    }
}

