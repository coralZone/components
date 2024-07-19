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
#include "xf_task.h"
#include "xf_multi_button.h"

/* ==================== [Defines] =========================================== */

#define TAG "multi_btn"

/* ==================== [Typedefs] ========================================== */

/* ==================== [Static Prototypes] ================================= */

static void button_task(xf_task_t task);

/* ==================== [Static Variables] ================================== */

/* ==================== [Macros] ============================================ */

/* ==================== [Global Functions] ================================== */

void xf_main(void)
{
    static struct Button btn;

    xf_button_init(&btn, 5, 0);
    xf_button_ticks();

    button_start(&btn);

    XF_LOGI(TAG, "muilt btn start");

    xf_ntask_create_loop(button_task, &btn, 6, 10);
}

/* ==================== [Static Functions] ================================== */

static void button_task(xf_task_t task)
{
    static PressEvent btn1_event_val;
    struct Button* btn = (struct Button*)xf_task_get_arg(task);

    if (btn1_event_val != get_button_event(btn)) {
        btn1_event_val = get_button_event(btn);

        switch (btn1_event_val)
        {
        case PRESS_DOWN:
            XF_LOGI(TAG, "PRESS_DOWN");
            break;
        case PRESS_UP:
            XF_LOGI(TAG, "PRESS_UP");
            break;
        case LONG_PRESS_HOLD:
            XF_LOGI(TAG, "LONG_PRESS_HOLD");
            break;
        case SINGLE_CLICK:
            XF_LOGI(TAG, "SINGLE_CLICK");
            break;
        case DOUBLE_CLICK:
            XF_LOGI(TAG, "DOUBLE_CLICK");
            break;

        default:
            break;
        }
    }
}
