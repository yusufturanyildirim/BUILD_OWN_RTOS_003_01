#include "timebase.h"
#include "stm32f4xx.h"

/* Internal Oscillator frequency is equal to 16MHz */
#define ONE_SEC_LOAD		16000000


/* Go to Generic User Guide for SysTick Control Register and
 * Status Register. Configure these registers.
 */

#define CTRL_EN				(1U<<0)
#define CTRL_TICK_IT		(1U<<1)
#define CTRL_CLCKSRC		(1U<<2)
#define CTRL_COUNT_FLAG		(1U<<16)
#define MAX_DELAY			0xFFFFFFFFU

volatile uint32_t g_curr_tick;
volatile uint32_t g_curr_tick_prime;
volatile uint32_t tick_freq = 1;

/* Parameter takes value in seconds */
void YTY_Delay(uint32_t delay)
{
	uint32_t tickStart = Get_Tick();
	uint32_t wait = delay;
	if(wait < MAX_DELAY)
	{
		wait += tick_freq;
	}

	while((Get_Tick() - tickStart) < wait){}

}

void Tick_Increment(void)
{
	g_curr_tick += tick_freq;
}

uint32_t Get_Tick(void)
{
	__disable_irq();
	g_curr_tick_prime = g_curr_tick;
	__enable_irq();

	return g_curr_tick_prime;
}

void YTY_TIME_BASE_INIT(void)
{
	/* Reload the timer with number of cycles per second */

	/* I wrote -1 because it becomes from 0 */
	SysTick->LOAD = ONE_SEC_LOAD - 1 ;

	/* Clear Systick Current value register */
	SysTick->VAL = 0 ;
	/* Select Internal Clock Source */
	SysTick->CTRL |=  CTRL_CLCKSRC ;

	/* Enable Interrupt */
	SysTick->CTRL |= CTRL_TICK_IT;

	/* Enable Systick */
	SysTick->CTRL |= CTRL_EN;

	/* Enable Global Interrupt */
	__enable_irq();

}

void SysTick_Handler(void)
{
	Tick_Increment();
}



