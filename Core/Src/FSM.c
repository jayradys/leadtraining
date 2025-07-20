#include "FSM.h"

//Function Definitions
void InitializeFSM(FSMType *FSM){
	FSM->CurrentState = S1_Press;
	FSM->StateCounter = 0;
}

FSMState NextStateFunction(FSMType *FSM){
	FSMState NextState = S1_Press;
	FSM->CurrentInput = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);
	switch (FSM->CurrentState){
	case S1_Press:
		if(FSM->CurrentInput == ACTIVE){
			NextState = S1_Release;
		} else {
			NextState = S1_Press;
		}
		break;
	case S1_Release:
		if(FSM->CurrentInput == ACTIVE){
			NextState = S1_Release;
		} else {
			NextState = S2_Press;
		}
		break;
	case S2_Press:
		if(FSM->CurrentInput == ACTIVE){
			NextState = S2_Release;
		} else {
			NextState = S2_Press;
		}
		break;
	case S2_Release:
		if(FSM->CurrentInput == ACTIVE){
			NextState = S2_Release;
		} else {
			NextState = S3_Press;
		}
		break;
	case S3_Press:
		if(FSM->CurrentInput == ACTIVE){
			NextState = S3_Release;
		} else {
			NextState = S3_Press;
		}
		break;
	case S3_Release:
		if(FSM->CurrentInput == ACTIVE){
			NextState = S3_Release;
		} else {
			NextState = S4_Press;
		}
		break;
	case S4_Press:
		if(FSM->CurrentInput == ACTIVE){
			NextState = S4_Release;
		} else {
			NextState = S4_Press;
		}
		break;
	case S4_Release:
		if(FSM->CurrentInput == ACTIVE){
			NextState = S4_Release;
		} else {
			NextState = S1_Press;
		}
		break;
	}
	FSM->CurrentState = NextState;
	return NextState;
}


void OutputFunction(FSMType *FSM){
	switch (FSM->CurrentState){
		case S1_Press:
		case S1_Release:
			FSM->StateCounter = 500;
			break;
		case S2_Press:
		case S2_Release:
			FSM->StateCounter = 250;
			break;
		case S3_Press:
		case S3_Release:
			FSM->StateCounter = 100;
			break;
		case S4_Press:
		case S4_Release:
			FSM->StateCounter = 50;
			break;
	}
}

