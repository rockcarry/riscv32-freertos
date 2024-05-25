#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <FreeRTOS.h>
#include <task.h>

#define REG_FFVM_STDIO  ((volatile uint32_t*)0xFF000000)
#define REG_FFVM_STDERR ((volatile uint32_t*)0xFF000004)
#define RISCV_CSR_MTVEC 0x305

static int stdin_getc(FILE *file)
{
    int  ch;
    do { ch = *REG_FFVM_STDIO; vTaskDelay(pdMS_TO_TICKS(20)); } while (ch == EOF);
    return ch;
}

static int stdout_putc(char c, FILE *file)
{
    return (*REG_FFVM_STDIO = c);
}

static int stdout_flush(FILE *file)
{
    *REG_FFVM_STDIO = -1;
    return 0;
}

static int stderr_putc(char c, FILE *file)
{
    return (*REG_FFVM_STDERR = c);
}

static int stderr_flush(FILE *file)
{
    *REG_FFVM_STDERR = -1;
    return 0;
}

static FILE __stdio  = FDEV_SETUP_STREAM(stdout_putc, stdin_getc, stdout_flush, _FDEV_SETUP_RW   );
static FILE __stderr = FDEV_SETUP_STREAM(stderr_putc, NULL      , stderr_flush, _FDEV_SETUP_WRITE);

FILE *const stdin  = &__stdio;
FILE *const stdout = &__stdio;
FILE *const stderr = &__stderr;

extern void freertos_risc_v_trap_handler(void);
static void install_freertos_trap_handler(void)
{
    uint32_t handler = (uint32_t)freertos_risc_v_trap_handler;
    asm volatile ( "csrw %0, %1" :: "i" (RISCV_CSR_MTVEC), "r" (handler) );
}

static void task_proc1(void *arg)
{
    while (1) {
        printf("hello1\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    vTaskDelete(NULL);
}

static void task_proc2(void *arg)
{
    while (1) {
        printf("hello2\n");
        vTaskDelay(pdMS_TO_TICKS(200));
    }
    vTaskDelete(NULL);
}

int main(void)
{
    install_freertos_trap_handler();
    xTaskCreate(task_proc1, "task1", 1024, NULL, 2, NULL);
    xTaskCreate(task_proc2, "task2", 1024, NULL, 3, NULL);
    vTaskStartScheduler();
    return 0;
}

