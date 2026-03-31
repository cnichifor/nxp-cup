#ifndef FILTER_H_
#define FILTER_H_

#include <stddef.h>
#include <stdint.h>
#include <math.h>
#include "config.h"

#define MIN_LEN_SQ      25.0   // ex: lungime minima ~5 pixeli
#define MIN_HALF_WIDTH  8.0
#define MAX_HALF_WIDTH  30.0

int crosses_y_ref(double y0, double y1);

double len_sq(double x0, double y0, double x1, double y1);

void pick_left_right_vectors(uint16_t vectors[], size_t num_vectors, int *left_idx, int *right_idx);

#endif
