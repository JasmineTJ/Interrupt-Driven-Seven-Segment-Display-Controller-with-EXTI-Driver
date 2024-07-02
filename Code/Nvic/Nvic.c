/**
 * Nvic.c
 *
 *  Created on: Mon May 13 2024
 *  Author    : Abdallah Darwish
 */

#include "Nvic.h"

#include "Bit_Operations.h"

#define NVIC_BASE (0xE000E100)

#define NVIC_ISER0 (*(uint32 *)(0xE000E100 + (0x04 * 0)))
#define NVIC_ISER1 (*(uint32 *)(0xE000E100 + (0x04 * 1)))
#define NVIC_ISER2 (*(uint32 *)(0xE000E100 + (0x04 * 2)))
#define NVIC_ISER3 (*(uint32 *)(0xE000E100 + (0x04 * 3)))
#define NVIC_ISER4 (*(uint32 *)(0xE000E100 + (0x04 * 4)))
#define NVIC_ISER5 (*(uint32 *)(0xE000E100 + (0x04 * 5)))
#define NVIC_ISER6 (*(uint32 *)(0xE000E100 + (0x04 * 6)))
#define NVIC_ISER7 (*(uint32 *)(0xE000E100 + (0x04 * 7)))

#define NVIC_ICER0 (*(uint32 *)0xE000E180)
#define NVIC_ICER1 (*(uint32 *)0xE000E184)
#define NVIC_ICER2 (*(uint32 *)0xE000E188)
#define NVIC_ICER3 (*(uint32 *)0xE000E18C)
#define NVIC_ICER4 (*(uint32 *)0xE000E190)
#define NVIC_ICER5 (*(uint32 *)0xE000E194)
#define NVIC_ICER6 (*(uint32 *)0xE000E198)
#define NVIC_ICER7 (*(uint32 *)0xE000E19C)

void Nvic_EnableInterrupt(uint8 IRQn) {
    if (IRQn < 240) {
        volatile uint32* NVIC_ISER[] = {
            &NVIC_ISER0, &NVIC_ISER1, &NVIC_ISER2, &NVIC_ISER3,
            &NVIC_ISER4, &NVIC_ISER5, &NVIC_ISER6, &NVIC_ISER7
        };
        uint8 register_index = IRQn / 32;
        uint8 bit_position = IRQn % 32;
        SET_BIT(*NVIC_ISER[register_index], bit_position);
    }
}

void Nvic_DisableInterrupt(uint8 IRQn) {
    if (IRQn < 240) {
        volatile uint32* NVIC_ICER[] = {
            &NVIC_ICER0, &NVIC_ICER1, &NVIC_ICER2, &NVIC_ICER3,
            &NVIC_ICER4, &NVIC_ICER5, &NVIC_ICER6, &NVIC_ICER7
        };
        uint8 register_index = IRQn / 32;
        uint8 bit_position = IRQn % 32;
        SET_BIT(*NVIC_ICER[register_index], bit_position);
    }
}
