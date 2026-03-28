#include "line_follow.h"

// calculating the line to follow
line get_line(uint16_t vectors[], size_t num_vectors)
{
	line l;
	l.x0 = 0;
	l.y0 = 0;
	l.x1 = 0;
	l.y1 = 0;

	if(num_vectors == 2)
	{
		l.x0 = (vectors[0] + vectors[4 + 0]) / 2;
		l.x1 = (vectors[1] + vectors[4 + 1]) / 2;
		l.y0 = (vectors[2] + vectors[4 + 2]) / 2;
		l.y1 = (vectors[3] + vectors[4 + 3]) / 2;
	}

	return l;
}

// get angle (radians)
double angle(line l)
{
	uint16_t dx = l.x1 - l.x0;
	uint16_t dy = - (l.y1 - l.y0);

	angle = atan2(dy, dx);
	if(angle > STEERING_LIMIT_RIGHT)
		angle = STEERING_LIMIT_RIGHT;
	else if (angle < STEERING_LIMIT_LEFT)
		angle = STEERING_LIMIT_LEFT;

	return angle;
}

double

// moving trough the line
void move(line l)
{
	double steer_angle = angle(l) + STEERING_OFFSET;
	Steer(steer_angle);
	HbridgeSpeed(&g_hbridge, 30, 30);
}
