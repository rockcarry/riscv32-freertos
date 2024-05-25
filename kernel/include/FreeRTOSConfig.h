#ifndef _FREERTOSCONFIG_H_
#define _FREERTOSCONFIG_H_

#define configMTIME_BASE_ADDRESS        0xFF000400uL
#define configMTIMECMP_BASE_ADDRESS     0xFF000408uL
#define configMINIMAL_STACK_SIZE        8192
#define configISR_STACK_SIZE_WORDS      500

#define configUSE_PREEMPTION            1
#define configUSE_TICKLESS_IDLE         1
#define configCPU_CLOCK_HZ              1000
#define configTICK_RATE_HZ              50

#define configMAX_PRIORITIES            8

#define configUSE_16_BIT_TICKS          0
#define configUSE_MUTEXES               1
#define configUSE_COUNTING_SEMAPHORES   1

#define configUSE_IDLE_HOOK             0
#define configUSE_TICK_HOOK             0

#define INCLUDE_vTaskDelay              1
#define INCLUDE_vTaskDelete             1

#endif
