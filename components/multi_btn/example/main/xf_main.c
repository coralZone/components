/**
 * @file xf_main.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-23
 *
 * Copyright (c) 2023, CorAL. All rights reserved.
 *
 */

/* ==================== [Includes] ========================================== */

#include "xf_hal.h"
#include "xf_multi_button.h"

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Static Prototypes] ================================= */

/* ==================== [Static Variables] ================================== */

/* ==================== [Macros] ============================================ */

/* ==================== [Global Functions] ================================== */

void xf_main(void)
{
    struct Button btn;
    static PressEvent btn1_event_val;

    xf_timer_src_init(0, 1000);

    xf_button_init(&btn, 5, 0);
    xf_button_ticks(0);

    button_start(&btn);

    xf_printf("muilt btn start\n");
    while(1)
    {
        if(btn1_event_val != get_button_event(&btn)) {
            btn1_event_val = get_button_event(&btn);

            if(btn1_event_val == PRESS_DOWN) {
                xf_printf("PRESS_DOWN\n");
            } else if(btn1_event_val == PRESS_UP) {
                xf_printf("PRESS_UP\n");
            } else if(btn1_event_val == LONG_PRESS_HOLD) {
                xf_printf("LONG_PRESS_HOLD\n");
            }
        }

        xf_delay_ms(10);
    }
}

/* ==================== [Static Functions] ================================== */
