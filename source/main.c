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

#include "line_follow.h"

#define MAX_VECTORS 10
#define MAX_STEER 40


int main(void)
{
    uint16_t vectors[MAX_VECTORS * 4];
    size_t   num_vectors;

    BOARD_InitHardware();
    BOARD_InitBootPins();
    BOARD_InitBootPeripherals();

    HbridgeInit(&g_hbridge,
                CTIMER0_PERIPHERAL,
                CTIMER0_PWM_PERIOD_CH,
                CTIMER0_PWM_1_CHANNEL,
                CTIMER0_PWM_2_CHANNEL,
                GPIO0, 24U,
                GPIO0, 27U);


//    Esc esc1, esc2;
//    EscInit(&esc1, CTIMER2_PERIPHERAL, CTIMER2_PWM_PERIOD_CH, kCTIMER_Match_1);
//    EscInit(&esc2, CTIMER2_PERIPHERAL, CTIMER2_PWM_PERIOD_CH, kCTIMER_Match_3);
//    EscSetSpeed(&esc1, 79.0);
//    EscBrake(&esc1);
//    EscSetSpeed(&esc2, 59.0);
//    EscBrake(&esc2);

//    TestServo();
    pixy_t cam1;
    pixy_init(&cam1, LPI2C2, 0x54U, &LP_FLEXCOMM2_RX_Handle, &LP_FLEXCOMM2_TX_Handle);
    pixy_set_led(&cam1, 255, 25, 25);

    volatile double angle = 0 + STEERING_OFFSET;


    Steer(angle);
    HbridgeSpeed(&g_hbridge, 0, 0);

    line l;

    while (1)
    {
    	if (pixy_get_vectors(&cam1, vectors, MAX_VECTORS, &num_vectors) == kStatus_Success)
    	{
			double angle = 0.0;
			for (size_t i = 0; i < num_vectors; i++)
			{
				uint16_t x0 = vectors[4*i + 0];
				uint16_t y0 = vectors[4*i + 1];
				uint16_t x1 = vectors[4*i + 2];
				uint16_t y1 = vectors[4*i + 3];
//				printf("  [%2u] (%u,%u)->(%u,%u)\r\n", (unsigned)i, x0, y0, x1, y1);
			}

			l = get_line(vectors, num_vectors);

			if(num_vectors >= 2)
			{
				move(l);
			}
			else
			{
				HbridgeSpeed(&g_hbridge, 0, 0);
			}
		}


    	SDK_DelayAtLeastUs(400000, CLOCK_GetFreq(kCLOCK_CoreSysClk));
    }
}
