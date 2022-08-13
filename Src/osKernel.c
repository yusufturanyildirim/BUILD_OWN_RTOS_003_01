#include "osKernel.h"

#define NUMBER_OF_THREADS	3
#define STACK_SIZE			100


/* Create TCB */
struct tcb{
	int32_t *stackPt;
	struct tcb *nextPt;
};


typedef struct tcb tcbType;


tcbType tcbs[NUMBER_OF_THREADS];
tcbType *currentPt;

/* Each thread will have stacksize of 100 i.e. 400 byte */
int32_t TCB_STACK[NUMBER_OF_THREADS][STACK_SIZE];

/*
 * First paremater will be thread
 */
void osKernelStackInit(int a_thread)
{

	/*Stack Pointer is from core register ... (generic user guide)*/
	tcbs[a_thread].stactPt = &TCB_STACK[a_thread][STACK_SIZE-16]; /*STACK POINTER */
	/* 16 comes from here, our psr register is 16, but not sure*/




	/* SET BIT21 (T- bit) in PSR to 1, to operate in THUMB MODE */
	/* for information about thumb mode refer to generic user  guide */

	TCB_STACK[a_thread][STACK_SIZE-1] = (1U<<21); /* PSR Register*/

	/* @Note : Block below is optional, for debugging purpose only */
	/* Dummy Stack Content */
	/* I did these because when I go to memory and see these, I know place
	 * of my stack for the thread
	 */
	TCB_STACK[a_thread][STACK_SIZE-3]  = 0xAAAAAAAA;	/*R14 i.e LR */
	TCB_STACK[a_thread][STACK_SIZE-4]  = 0xAAAAAAAA;	/*R12*/
	TCB_STACK[a_thread][STACK_SIZE-5]  = 0xAAAAAAAA;	/*R3*/
	TCB_STACK[a_thread][STACK_SIZE-6]  = 0xAAAAAAAA;	/*R2*/
	TCB_STACK[a_thread][STACK_SIZE-7]  = 0xAAAAAAAA;	/*R1*/
	TCB_STACK[a_thread][STACK_SIZE-8]  = 0xAAAAAAAA;	/*R0*/


	TCB_STACK[a_thread][STACK_SIZE-9]  = 0xAAAAAAAA;	/*R11*/
	TCB_STACK[a_thread][STACK_SIZE-10] = 0xAAAAAAAA;	/*R10*/
	TCB_STACK[a_thread][STACK_SIZE-11] = 0xAAAAAAAA;	/*R9*/
	TCB_STACK[a_thread][STACK_SIZE-12] = 0xAAAAAAAA;	/*R8*/
	TCB_STACK[a_thread][STACK_SIZE-13] = 0xAAAAAAAA;	/*R7*/
	TCB_STACK[a_thread][STACK_SIZE-14] = 0xAAAAAAAA;	/*R6*/
	TCB_STACK[a_thread][STACK_SIZE-15] = 0xAAAAAAAA;	/*R5*/
	TCB_STACK[a_thread][STACK_SIZE-16] = 0xAAAAAAAA;	/*R4*/


}
