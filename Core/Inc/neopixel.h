#ifndef NEOPIXEL_H
#define NEOPIXEL_H

#include "main.h"

/* ConnectionLED */
//#define MAX_LED 23
/* if TapeLED */
#define MAX_LED 60
/*LED Pattern */
#define LED_NUM 8
/* if TapeLED */
//#define LED_NUM 30
/* Last No. is Reset */
#define DMA_BUFF_SIZE (MAX_LED * 24) + 1
/* 72Mhz Duty */
//#define PWM_HI 60
//#define PWM_LO 30
/* 24Mhz Duty */
#define PWM_HI 20
#define PWM_LO 10
/* 16Mhz Duty */
//#define PWM_HI 10
//#define PWM_LO 5



void Set_LED (uint8_t LEDnum, uint8_t Red, uint8_t Green, uint8_t Blue);
void WS2812_Send (uint32_t *color);
uint32_t HSV_Rainbow(uint16_t hue);
uint32_t Neon(uint16_t hue);
uint32_t Cranberry(uint16_t hue);
uint32_t Blueberry(uint16_t hue);
uint32_t Muscat(uint16_t hue);
uint32_t HSV_Pastel(uint16_t hue);
void RGB_Generate(void);
void Rainbow_Circle(uint8_t loop);

#endif
