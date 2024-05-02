#include "neopixel.h"
#include "main.h"

extern TIM_HandleTypeDef htim1;
extern DMA_HandleTypeDef hdma_tim1_ch1;
extern volatile uint8_t datasentflag;
extern uint8_t point;
extern uint16_t HueSeed[MAX_LED];
extern uint8_t lux;

uint8_t angle[] = {80,64,32};
uint16_t pwmData[DMA_BUFF_SIZE];
uint16_t *pbuff;

void WS2812_Send (uint32_t *color)
{
	pbuff = pwmData;

	for (int i= 0; i<MAX_LED; i++)
	{
		for (int j=23; j>=0; j--)
		{
			*pbuff = PWM_LO << ( (color[i] >> j) & 0x01 );
			pbuff++;
		}
	}
	pwmData[DMA_BUFF_SIZE -1] = 0;
	HAL_TIM_PWM_Start_DMA(&htim1, TIM_CHANNEL_1, (uint32_t *)pwmData, DMA_BUFF_SIZE);
	HAL_Delay(1);
	while (!datasentflag){}
	datasentflag = 0;
}
uint32_t HSV_Rainbow(uint16_t hue)
{
	uint8_t r,g,b;
	r=g=b=0;
	uint16_t i;
	i = hue / 60;
	switch(i)
	{
	case 0:
    	r = 255;
    	g = hue * 255/60;
    	b = 0;
    	break;
    case 1:
    	r = (120 - hue) * 255 / 60;
    	g = 255;
    	b = 0;
    	break;
    case 2:
    	r = 0;
    	g = 255;
    	b = (hue - 120) * 255 / 60;
    	break;
    case 3:
    	r = 0;
    	g = (240 - hue) * 255 / 60;
    	b = 255;
    	break;
    case 4:
    	r = (hue - 240) * 255 / 60;
    	g = 0;
    	b = 255;
    	break;
    case 5:
    	r = 255;
    	g = 0;
    	b = (360 - hue) * 255 / 60;
    	break;
	}
	r >>= lux;
	g >>= lux;
	b >>= lux;
	return ( (g << 16) | (r << 8) | (b) );
}
uint32_t Neon(uint16_t hue)
{
	uint8_t r,g,b;
	r=g=b=0;
	uint16_t i;
	i = hue / 60;
	switch(i)
	{
	case 0:
		r = 255;
		g = 0;
		b = 0;
	  break;
	case 1:
		r = 255;
		g = 255;
		b = 0;
	  break;
	case 2:
		r = 0;
		g = 0;
		b = 255;
	  break;
	case 3:
		r = 128;
		g = 0;
		b = 255;
	  break;
	case 4:
		r = 255;
		g = 0;
		b = 255;
	  break;
	case 5:
		r = 255;
		g = 0;
		b = 128;
	  break;
	}
	r >>= lux;
	g >>= lux;
	b >>= lux;
	return ( (g << 16) | (r << 8) | (b) );
}
uint32_t Cranberry(uint16_t hue)
{
	uint8_t r,g,b;
	r=g=b=0;
	uint16_t i;
	i = hue / 60;
	switch(i)
	{
	case 0:
    	r = 255;
    	g = 0;
    	b = 0;
    	break;
    case 1:
    	r = 255;
    	g = 64;
    	b = 0;
    	break;
    case 2:
    	r = 255;
    	g = 128;
    	b = 0;
    	break;
    case 3:
    	r = 255;
    	g = 64;
    	b = 0;
    	break;
    case 4:
    	r = 255;
    	g = 0;
    	b = 64;
    	break;
    case 5:
    	r = 255;
    	g = 0;
    	b = 100;
    	break;
	}
	r >>= lux;
	g >>= lux;
	b >>= lux;
	return ( (g << 16) | (r << 8) | (b) );
}
uint32_t Blueberry(uint16_t hue)
{
	uint8_t r,g,b;
	r=g=b=0;
	uint16_t i;
	i = hue / 60;
	switch(i)
	{
	case 0:
    	r = 0;
    	g = 0;
    	b = 255;
    	break;
    case 1:
    	r = 128;
    	g = 0;
    	b = 255;
      break;
    case 2:
    	r = 192;
    	g = 0;
    	b = 255;
    	break;
    case 3:
    	r = 0;
    	g = 128;
    	b = 255;
    	break;
    case 4:
    	r = 0;
    	g = 192;
    	b = 255;
    	break;
    case 5:
    	r = 0;
    	g = 32;
    	b = 255;
    	break;
	}
	r >>= lux;
	g >>= lux;
	b >>= lux;
	return ( (g << 16) | (r << 8) | (b) );
}
uint32_t Muscat(uint16_t hue)
{
	uint8_t r,g,b;
	r=g=b=0;
	uint16_t i;
	i = hue / 60;
	switch(i)
	{
	case 0:
    	r = 0;
    	g = 255;
    	b = 0;
    	break;
    case 1:
    	r = 0;
    	g = 255;
    	b = 64;
    	break;
    case 2:
    	r = 0;
    	g = 255;
    	b = 128;
      break;
    case 3:
    	r = 64;
    	g = 255;
    	b = 0;
    	break;
    case 4:
    	r = 128;
    	g = 255;
    	b = 0;
    	break;
    case 5:
    	r = 0;
    	g = 255;
    	b = 0;
    	break;
	}
	r >>= lux;
	g >>= lux;
	b >>= lux;
	return ( (g << 16) | (r << 8) | (b) );
}
uint32_t HSV_Pastel(uint16_t hue)
{
	uint8_t r,g,b;
	r=g=b=0;

	hue *= 2;
	if(hue >= 360) hue -= 360;
	uint16_t i;
	i = hue / 60;
	switch(i)
	{
	case 0:
    	r = 255;
    	g = hue * 255/60;
    	b = 0;
    	break;
    case 1:
    	r = (120 - hue) * 255 / 60;
    	g = 255;
    	b = 0;
    	break;
    case 2:
    	r = 0;
    	g = 255;
    	b = (hue - 120) * 255 / 60;
    	break;
    case 3:
    	r = 0;
    	g = (240 - hue) * 255 / 60;
    	b = 255;
    	break;
    case 4:
    	r = (hue - 240) * 255 / 60;
    	g = 0;
    	b = 255;
    	break;
    case 5:
    	r = 255;
    	g = 0;
    	b = (360 - hue) * 255 / 60;
    	break;
	}
	r >>= lux;
	g >>= lux;
	b >>= lux;

	HAL_Delay(1);

	return ( (g << 16) | (r << 8) | (b) );
}
void RGB_Generate(void)
{
	uint8_t i;
	for(i = 0; i < MAX_LED; i++)
	{
		HueSeed[i] = i * 360/LED_NUM;
		if(HueSeed[i] >= 360)
		{
			HueSeed[i] -= 360;
		}
	}
}
void Rainbow_Circle(uint8_t loop)
{
	HueSeed[loop] += angle[point];
	if(HueSeed[loop] >= 360)
	{
		HueSeed[loop] -= 360;
	}
}

