//
// Created by yaoji on 2022/1/22.
//

#ifndef ZYNQ7020_MAIN_H
#define ZYNQ7020_MAIN_H

#include "FreeRTOS.h"
#include "semphr.h"

#include "xiicps.h"
#include "xgpiops.h"
#include "xaxidma.h"
#include "xqspips.h"
#include "xadcps.h"

#define BTN_GPIO_PIN 54
#define LED_GPIO_PIN 51
#define GT911_RST_GPIO_PIN 56
#define GT911_INT_GPIO_PIN 57

#define GPIO_DIR_INPUT 0
#define GPIO_DIR_OUTPUT 1

extern XIicPs iic0, iic1;
extern XGpioPs gpio;
extern XAxiDma dma0, dma1;
extern XQspiPs QspiInstance;
extern XAdcPs xAdcPs;
extern SemaphoreHandle_t key_handle;

#endif //ZYNQ7020_MAIN_H
