/*
 * line_follow.h
 *
 *  Created on: Mar 28, 2026
 *      Author: Cristian
 */

#ifndef LINE_FOLLOW_H_
#define LINE_FOLLOW_H_

#include <stddef.h>
#include <stdint.h>
#include "config.h"

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "app.h"
#include "fsl_pwm.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "hbridge.h"
#include "pixy.h"
#include "fsl_common.h"
#include "Config.h"
#include "servo.h"
#include "esc.h"

#include<math.h>

typedef struct
{
	uint16_t x0;
	uint16_t y0;
	uint16_t x1;
	uint16_t y1;
} line;

line get_line(uint16_t vectors[], size_t num_vectors);

double angle(line l);

void move(line l);

#endif /* LINE_FOLLOW_H_ */
