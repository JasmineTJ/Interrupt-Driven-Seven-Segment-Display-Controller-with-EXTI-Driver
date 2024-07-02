#ifndef EXTI_H
#define EXTI_H

#include "Std_Types.h"
#include "Bit_Operations.h"

// Define the EXTI structure
typedef struct {
    uint32 IMR;
    uint32 EMR;
    uint32 RTSR;
    uint32 FTSR;
    uint32 SWIER;
    uint32 PR;
} ExtiType;

#define EXTI ((ExtiType *)0x40013C00)

#define SYSCFG_BASE (0x40013800)

#define SYSCFG_EXTICR1 (*(uint32 *)(SYSCFG_BASE + 0x08))
#define SYSCFG_EXTICR2 (*(uint32 *)(SYSCFG_BASE + 0x0C))
#define SYSCFG_EXTICR3 (*(uint32 *)(SYSCFG_BASE + 0x10))
#define SYSCFG_EXTICR4 (*(uint32 *)(SYSCFG_BASE + 0x14))

typedef enum {
    EXTI_RISING_EDGE,
    EXTI_FALLING_EDGE,
    EXTI_BOTH_EDGES
} Exti_TriggerType;

void Exti_Init(uint8 line, uint8 port, Exti_TriggerType trigger);
void Exti_Enable(uint8 line);
void Exti_Disable(uint8 line);

#endif // EXTI_H
