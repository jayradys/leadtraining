// Debug functions that will print to UART3 port, which is connected to the USB (ST-link) of the Nucleo
#ifndef __DEBUG_H
#define __DEBUG_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "stm32f7xx_hal.h"



void writeDebug(const char *buffer, uint8_t length);
void writeDebugString(const char *buffer);
void writeDebugFormat(const char *format, ...);

#endif
