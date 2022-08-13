#include "led.h"
#include "uart.h"
#include "timebase.h"

void blue_led_on(void);
void blue_led_off(void);
void red_led_on(void);
void red_led_off(void);


int blue_led_main()
{
	for(;;)
	{
		blue_led_on();
		YTY_Delay(1);
		blue_led_off();
		YTY_Delay(1);

	}
}

int red_led_main()
{
	for(;;)
	{
		red_led_on();
		YTY_Delay(1);
		red_led_off();
		YTY_Delay(1);
	}
}
int main(void)
{
	uint32_t volatile start = 0U;

	RCC_Config();
	GPIO_Config();
	UART_TRANSMIT_Config();
	YTY_TIME_BASE_INIT();

	if(start)
	{
		red_led_main();
	}
	if(!start)
	{
		blue_led_main();
	}


	while(1)
	{


	}
}


void blue_led_on(void)
{
	LED_BLUE_ON();
	//printf("Motor is running\n");
}

void blue_led_off(void)
{
	LED_BLUE_OFF();
	//printf("Motor is stopping\n");
}

void red_led_on(void)
{
	LED_RED_ON();
	//printf("Motor is openning\n");
}

void red_led_off(void)
{
	LED_RED_OFF();
	printf("Motor is closing\n");
}
