## Project Overview
This project is a software solution that performs a decimal counter on a seven-segment display, controlled by two push buttons. It demonstrates the use of interrupts, the NVIC capabilities, and the complete cycle of configuring an interrupt.

## Features
- **NVIC and EXTI Drivers**: The NVIC (Nested Vectored Interrupt Controller) and EXTI (External Interrupt) drivers are implemented. The NVIC driver is used to understand its capabilities and differences from typical interrupt controllers, while the EXTI driver is used to initialize, enable, and disable external interrupts.
- **Interrupt Service Routines (ISRs)**: Two ISRs are configured on GPIO falling edge, one for each button. The first ISR increments the counter, while the second ISR decrements the counter.
- **Seven Segment Display Control**: The main function uses the GPIO, NVIC, and EXTI functions to control a seven-segment display and display a decimal counter upon a button press.

## Implementation Details
- The system inputs are two push buttons connected on pins PA9 and PB5.
- The system output is a seven-segment display.
- The main function performs the display actions, not the ISRs.
- Race conditions are taken into consideration to protect the counters from being corrupted.