/*
 * utils.h
 *
 *  Created on: 2021年12月25日
 *      Author: yaoji
 */

#ifndef SRC_UTILS_H_
#define SRC_UTILS_H_

#include "xil_printf.h"
#include "xstatus.h"

#define CHECK_STATUS(__C)                            \
    do {                                             \
        int __STATUS = (int)__C;                     \
        if (__STATUS != XST_SUCCESS) {               \
            xil_printf(                              \
                "ERROR: File:'__FILE__' Line:%d "    \
                "in Function '"#__C"' return is %d\r\n", \
                __LINE__, __STATUS);                 \
        }                                            \
    } while (0)

#define CHECK_STATUS_RET(__C)                        \
    do {                                             \
        int __STATUS = (int)__C;                     \
        if (__STATUS != XST_SUCCESS) {               \
            xil_printf(                              \
                "ERROR: File:'"__FILE__"' Line:%d "  \
                "in Function '"#__C"' return is %d\r\n", \
                __LINE__, __STATUS);                 \
            return __STATUS;                         \
        }                                            \
    } while (0)

#define CHECK_STATUS_GOTO(__STATUS, __LABEL, __C)    \
    do {                                             \
        __STATUS = (int)__C;                         \
        if (__STATUS != XST_SUCCESS) {               \
            xil_printf(                              \
                "ERROR: File:'"__FILE__"' Line:%d "  \
                "in Function '"#__C"' return is %d\r\n", \
                __LINE__, __STATUS);                 \
            goto __LABEL;                            \
        }                                            \
    } while (0)

#define CHECK_FATAL_ERROR(__C)                                                              \
    if (__C) {                                                                              \
        xil_printf("FATAL ERROR: In File:'"__FILE__"' Line:%d '"#__C"'\r\n", __LINE__);   \
        while(1);                                                                           \
    }

#endif /* SRC_UTILS_H_ */
