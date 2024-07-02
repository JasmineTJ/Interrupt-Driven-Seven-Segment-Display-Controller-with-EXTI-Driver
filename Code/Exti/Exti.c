//EXTI DRIVER--------------------------------

#include "Exti.h"
//#include "Nvic.h"
//#include "Rcc.h"
//#include "Gpio.h"

void Exti_Init(uint8 line, uint8 port, Exti_TriggerType trigger) {
//	Declare pointer to register
	volatile uint32* EXTICR;

	if (line <= 3){
		EXTICR = &SYSCFG_EXTICR1;
	}else if(line <= 7){
		EXTICR = &SYSCFG_EXTICR2;
	}else if(line <= 11){
		EXTICR = &SYSCFG_EXTICR3;
	}else if(line <= 15){
		EXTICR = &SYSCFG_EXTICR4;
	}

    // Select the port for the EXTI line
    uint8 shift = (line % 4) * 4;
    *EXTICR &= ~(0xF << shift);
    *EXTICR |= (port << shift);

    // Configure the trigger type
    switch (trigger) {
        case EXTI_RISING_EDGE:
            SET_BIT(EXTI->RTSR, line);
            CLEAR_BIT(EXTI->FTSR, line);
            break;
        case EXTI_FALLING_EDGE:
            CLEAR_BIT(EXTI->RTSR, line);
            SET_BIT(EXTI->FTSR, line);
            break;
        case EXTI_BOTH_EDGES:
            SET_BIT(EXTI->RTSR, line);
            SET_BIT(EXTI->FTSR, line);
            break;
    	}


    // Clear any pending interrupt for the line
//    SET_BIT(EXTI->PR, line);
}

void Exti_Enable(uint8 line) {
    SET_BIT(EXTI->IMR, line);
}

void Exti_Disable(uint8 line) {
    CLEAR_BIT(EXTI->IMR, line);
}
