#include "filter.h"

double x_at_y(double x0, double y0, double x1, double y1, double y)
{
    if (fabs(y1 - y0) < 1e-6)
        return x0;

    return x0 + (y - y0) * (x1 - x0) / (y1 - y0);
}

int crosses_y_ref(double y0, double y1)
{
    return (Y_REF >= y0 && Y_REF <= y1) || (Y_REF >= y1 && Y_REF <= y0);
}

double len_sq(double x0, double y0, double x1, double y1)
{
    double dx = x1 - x0;
    double dy = y1 - y0;
    return dx * dx + dy * dy;
}

void pick_left_right_vectors(uint16_t vectors[], size_t num_vectors, int *left_idx, int *right_idx)
{
    *left_idx = -1;
    *right_idx = -1;

    int best_left_y = -1;
    int best_right_y = -1;

    for (size_t i = 0; i < num_vectors; i++)
    {
        double x0 = vectors[4*i + 0];
        double y0 = vectors[4*i + 1];
        double x1 = vectors[4*i + 2];
        double y1 = vectors[4*i + 3];

        // 1. ignora vectorii prea scurti
        if (len_sq(x0, y0, x1, y1) < MIN_LEN_SQ)
            continue;

        // 2. ignora vectorii care nu intersecteaza Y_REF
        if (!crosses_y_ref(y0, y1))
            continue;

        double xref = x_at_y(x0, y0, x1, y1, Y_REF);
        int y_near = (y0 > y1) ? (int)y0 : (int)y1;

        // 3. margine stanga valida doar intr-o zona plauzibila
        if (xref < X_C)
        {
            if (xref < X_C - MAX_HALF_WIDTH)   // prea in exterior
                continue;
            if (xref > X_C - MIN_HALF_WIDTH)   // prea aproape de centru
                continue;

            if (*left_idx == -1 || y_near > best_left_y)
            {
                best_left_y = y_near;
                *left_idx = (int)i;
            }
        }
        else
        {
            // 4. margine dreapta valida doar intr-o zona plauzibila
            if (xref > X_C + MAX_HALF_WIDTH)   // prea in exterior
                continue;
            if (xref < X_C + MIN_HALF_WIDTH)   // prea aproape de centru
                continue;

            if (*right_idx == -1 || y_near > best_right_y)
            {
                best_right_y = y_near;
                *right_idx = (int)i;
            }
        }
    }
}
