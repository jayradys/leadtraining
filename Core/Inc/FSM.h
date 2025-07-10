#ifndef INC_FSM_H_
#define INC_FSM_H_

#include "main.h"

#define ACTIVE 0

//Type Definitions
typedef enum{
	S1_Press, S1_Release, S2_Press, S2_Release,
	S3_Press, S3_Release, S4_Press, S4_Release
} FSMState;

typedef struct{
	FSMState CurrentState;
	uint8_t CurrentInput;
	uint16_t StateCounter;
} FSMType;

//Function Declarations
void InitializeFSM(FSMType *FSM);
FSMState NextStateFunction(FSMType *FSM);
void OutputFunction(FSMType *FSM);

#endif
