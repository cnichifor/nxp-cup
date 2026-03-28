/*
 * line_follow.h
 *
 *  Created on: Mar 28, 2026
 *      Author: Cristian
 */

#ifndef LINE_FOLLOW_H_
#define LINE_FOLLOW_H_

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
