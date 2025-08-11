#include "FSM.h"

//Function Definitions
void InitializeFSM(FSMType *FSM){
	FSM->CurrentState = S1;
	FSM->StateCounter = 0;
}

FSMState NextStateFunction(FSMType *FSM){
	FSMState NextState = S1;
	switch (FSM->CurrentState){
	case S1:
		NextState = S2;
		break;
	case S2:
		NextState = S3;
		break;
	case S3:
		NextState = S4;
		break;
	case S4:
		NextState = S1;
		break;
	}
	FSM->CurrentState = NextState;
	return NextState;
}


void OutputFunction(FSMType *FSM){
	switch (FSM->CurrentState){
		case S1:
			FSM->StateCounter = 500;
			break;
		case S2:
			FSM->StateCounter = 250;
			break;
		case S3:
			FSM->StateCounter = 100;
			break;
		case S4:
			FSM->StateCounter = 50;
			break;
	}
}
