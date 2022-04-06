/*
 * FreeRTOS_Mem.c
 *
 *  Created on: 2021年12月31日
 *      Author: yaoji
 */

#include "FreeRTOS_Mem/FreeRTOS_Mem.h"
#include "FreeRTOS.h"
#include "stdlib.h"
#include "xil_cache.h"

void *os_malloc(size_t __size) {
    vPortEnterCritical();
    void *p = malloc(__size);
    vPortExitCritical();
    return p;
}

void *os_realloc(void *__r, size_t __size) {
    vPortEnterCritical();
    void *p = realloc(__r, __size);
    vPortExitCritical();
    return p;
}

void os_free(void *__r) {
    if (__r == NULL) return;
    vPortEnterCritical();
    free(__r);
    vPortExitCritical();
}

void os_DCacheInvalidateRange(void *adr, uint32_t len) {
	vPortEnterCritical();
	Xil_DCacheInvalidateRange(adr, len);
	vPortExitCritical();
}

void os_DCacheFlushRange(void *adr, uint32_t len) {
	vPortEnterCritical();
	Xil_DCacheFlushRange(adr, len);
	vPortExitCritical();
}
