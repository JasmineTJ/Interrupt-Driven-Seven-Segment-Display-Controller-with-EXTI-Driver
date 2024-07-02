#include "Bit_Operations.h"
#include "Std_Types.h"
#include "Utils.h"
#include "Gpio.h"
#include "Rcc.h"
#include "Nvic.h"
#include "Exti.h"


#define EXTI ((ExtiType *)0x40013C00)

#define BUTTON_INC_PIN 9
#define BUTTON_DEC_PIN 4

volatile uint8 counter = 0;

void EXTI_Callback_INC_DEC(uint8 GPIO_Pin);


int main() {
	Rcc_Init();
	Rcc_Enable(RCC_GPIOA);
	Rcc_Enable(RCC_GPIOB);
	Rcc_Enable(RCC_SYSCFG);

	// Configure GPIO 7 Segment pins as outputs
	  uint32 i = 0;
	  for (i = 0; i < 7; i++) {
	    Gpio_ConfigPin(GPIO_A, i, GPIO_OUTPUT, GPIO_PUSH_PULL);
	  }

	Gpio_ConfigPin(GPIO_A, 9, GPIO_INPUT, GPIO_PULL_UP);
	Gpio_ConfigPin(GPIO_B, 4, GPIO_INPUT, GPIO_PULL_UP);

    // Initialize EXTI for PA9 with falling edge trigger
    Exti_Init(9, 0, EXTI_FALLING_EDGE); // Port A is 0

    // Initialize EXTI for PB4 with falling edge trigger
    Exti_Init(4, 1, EXTI_FALLING_EDGE); // Port B is 1

	Exti_Enable(9);
	Exti_Enable(4);

    // Enable EXTI lines on NVIC
    Nvic_EnableInterrupt(23); // EXTI9_5_IRQn is 23
    Nvic_EnableInterrupt(10); // EXTI4_IRQn is 10

	while (1) {
		// Switch case to control 7-Segment sequence based on counter value
		switch (counter)
		{
		case 0:
			Gpio_WritePin(GPIO_A, 0, HIGH);
			Gpio_WritePin(GPIO_A, 1, HIGH);
			Gpio_WritePin(GPIO_A, 2, HIGH);
			Gpio_WritePin(GPIO_A, 3, HIGH);
			Gpio_WritePin(GPIO_A, 4, HIGH);
			Gpio_WritePin(GPIO_A, 5, HIGH);
			Gpio_WritePin(GPIO_A, 6, LOW);
			break;

		case 1:
			Gpio_WritePin(GPIO_A, 0, LOW);
			Gpio_WritePin(GPIO_A, 1, HIGH);
			Gpio_WritePin(GPIO_A, 2, HIGH);
			Gpio_WritePin(GPIO_A, 3, LOW);
			Gpio_WritePin(GPIO_A, 4, LOW);
			Gpio_WritePin(GPIO_A, 5, LOW);
			Gpio_WritePin(GPIO_A, 6, LOW);

			break;
		case 2:
			Gpio_WritePin(GPIO_A, 0, HIGH);
			Gpio_WritePin(GPIO_A, 1, HIGH);
			Gpio_WritePin(GPIO_A, 2, LOW);
			Gpio_WritePin(GPIO_A, 3, HIGH);
			Gpio_WritePin(GPIO_A, 4, HIGH);
			Gpio_WritePin(GPIO_A, 5, LOW);
			Gpio_WritePin(GPIO_A, 6, HIGH);

			break;
		case 3:
			Gpio_WritePin(GPIO_A, 0, HIGH);
			Gpio_WritePin(GPIO_A, 1, HIGH);
			Gpio_WritePin(GPIO_A, 2, HIGH);
			Gpio_WritePin(GPIO_A, 3, HIGH);
			Gpio_WritePin(GPIO_A, 4, LOW);
			Gpio_WritePin(GPIO_A, 5, LOW);
			Gpio_WritePin(GPIO_A, 6, HIGH);

			break;
		case 4:
			Gpio_WritePin(GPIO_A, 0, LOW);
			Gpio_WritePin(GPIO_A, 1, HIGH);
			Gpio_WritePin(GPIO_A, 2, HIGH);
			Gpio_WritePin(GPIO_A, 3, LOW);
			Gpio_WritePin(GPIO_A, 4, LOW);
			Gpio_WritePin(GPIO_A, 5, HIGH);
			Gpio_WritePin(GPIO_A, 6, HIGH);

			break;
		case 5:
			Gpio_WritePin(GPIO_A, 0, HIGH);
			Gpio_WritePin(GPIO_A, 1, LOW);
			Gpio_WritePin(GPIO_A, 2, HIGH);
			Gpio_WritePin(GPIO_A, 3, HIGH);
			Gpio_WritePin(GPIO_A, 4, LOW);
			Gpio_WritePin(GPIO_A, 5, HIGH);
			Gpio_WritePin(GPIO_A, 6, HIGH);

			break;
		case 6:
			Gpio_WritePin(GPIO_A, 0, HIGH);
			Gpio_WritePin(GPIO_A, 1, LOW);
			Gpio_WritePin(GPIO_A, 2, HIGH);
			Gpio_WritePin(GPIO_A, 3, HIGH);
			Gpio_WritePin(GPIO_A, 4, HIGH);
			Gpio_WritePin(GPIO_A, 5, HIGH);
			Gpio_WritePin(GPIO_A, 6, HIGH);

			break;
		case 7:
			Gpio_WritePin(GPIO_A, 0, HIGH);
			Gpio_WritePin(GPIO_A, 1, HIGH);
			Gpio_WritePin(GPIO_A, 2, HIGH);
			Gpio_WritePin(GPIO_A, 3, LOW);
			Gpio_WritePin(GPIO_A, 4, LOW);
			Gpio_WritePin(GPIO_A, 5, LOW);
			Gpio_WritePin(GPIO_A, 6, LOW);

			break;
		case 8:
			Gpio_WritePin(GPIO_A, 0, HIGH);
			Gpio_WritePin(GPIO_A, 1, HIGH);
			Gpio_WritePin(GPIO_A, 2, HIGH);
			Gpio_WritePin(GPIO_A, 3, HIGH);
			Gpio_WritePin(GPIO_A, 4, HIGH);
			Gpio_WritePin(GPIO_A, 5, HIGH);
			Gpio_WritePin(GPIO_A, 6, HIGH);

			break;
		case 9:
			Gpio_WritePin(GPIO_A, 0, HIGH);
			Gpio_WritePin(GPIO_A, 1, HIGH);
			Gpio_WritePin(GPIO_A, 2, HIGH);
			Gpio_WritePin(GPIO_A, 3, HIGH);
			Gpio_WritePin(GPIO_A, 4, LOW);
			Gpio_WritePin(GPIO_A, 5, HIGH);
			Gpio_WritePin(GPIO_A, 6, HIGH);

			break;
		default:

			break;
		}
		// Delay loop to control 7-Segment sequence speed
		for(i=0 ; i <1000000;i++ ){}
	}

	return 0;
}


void EXTI4_IRQHandler(void) {
	EXTI_Callback_INC_DEC(BUTTON_DEC_PIN);
}

void EXTI9_5_IRQHandler(void) {
	EXTI_Callback_INC_DEC(BUTTON_INC_PIN);
}

void EXTI_Callback_INC_DEC(uint8 GPIO_Pin) {
    // Disable interrupts to prevent race conditions
	Exti_Disable(9);
	Exti_Disable(4);

    // Increment or decrement counter based on which button was pressed
    if (GPIO_Pin == BUTTON_INC_PIN) {
        if (counter < 9) {
            counter++;
        }
        SET_BIT(EXTI->PR, 9);
    } else if (GPIO_Pin == BUTTON_DEC_PIN) {
        if (counter > 0) {
            counter--;
        }
        SET_BIT(EXTI->PR, 4);
    }

    // Enable interrupts again
	Exti_Enable(9);
	Exti_Enable(4);
}








