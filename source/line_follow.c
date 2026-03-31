#include "line_follow.h"
#include "filter.h"



static int dist = 0;

// calculating the line to follow
line get_line(uint16_t vectors[], size_t num_vectors)
{

	line l;
	l.x0 = 0;
	l.y0 = 0;
	l.x1 = 0;
	l.y1 = 0;

	if(num_vectors >= 2)
	{
		int left_idx = 0, right_idx = 1;
//		pick_left_right_vectors(vectors, num_vectors, &left_idx, &right_idx);

		l.x0 = 39;
		l.y0 = 51;
//		l.x0 = (vectors[0] + vectors[4 + 0]) / 2;
//		l.y0 = (vectors[1] + vectors[4 + 1]) / 2;
		l.x1 = (vectors[4 * left_idx + 2] + vectors[4 * right_idx + 2]) / 2;
		l.y1 = (vectors[4 * left_idx + 3] + vectors[4 * right_idx + 3]) / 2;
//		dist = abs(vectors[2] - vectors[0]);
	}
	else if (num_vectors == 1)
	{
		l.x0 = vectors[0];
    	l.y0 = vectors[1];
		l.x1 = vectors[2];
		l.y1 = vectors[3];
	}

	return l;
}

// get angle (radians)
double angle(line l)
{
    double dx = (double)l.x1 - (double)l.x0;
    double dy = (double)l.y0 - (double)l.y1;

    double a = atan2(dx, dy) * 60;

    if (a > STEERING_LIMIT_RIGHT)
        a = STEERING_LIMIT_RIGHT;
    else if (a < STEERING_LIMIT_LEFT)
        a = STEERING_LIMIT_LEFT;

    return a;
}

// moving trough the line
void move(line l)
{
	double ref_angle = angle(l);
    double steer_angle = ref_angle + STEERING_OFFSET;
    short int speed = 100;
    if(fabs(ref_angle) >= 10)
    	speed = 25;

//    printf("steer_x10  00=%d\n", (int)(steer_angle));

    Steer(steer_angle);
    HbridgeSpeed(&g_hbridge, speed, speed);
}
