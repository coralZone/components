/**
 * @file multi_btn.c
 * @author cangyu (sky.kirto@qq.com)
 * @brief
 * @version 0.1
 * @date 2024-06-12
 *
 * @copyright Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

/* ==================== [Includes] ========================================== */

#include "xf_multi_button.h"

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Static Prototypes] ================================= */

static uint8_t pin_level(uint8_t btn_id);
static void timeout_cb(xf_timer_t *timer);

/* ==================== [Static Variables] ================================== */

/* ==================== [Macros] ============================================ */

#define MB_ERR_CHECK(x) do {        \
            xf_err_t err_rc_ = (x); \
            if (err_rc_ != XF_OK) { \
                return err_rc_;     \
            }                       \
        } while (0)

/* ==================== [Global Functions] ================================== */

xf_err_t xf_button_init(struct Button *handle, xf_gpio_num_t num,
                         uint8_t press_level)
{
    if (press_level) {
        MB_ERR_CHECK(xf_gpio_init(num, XF_GPIO_INPUT_PULLDOWN));
    } else {
        MB_ERR_CHECK(xf_gpio_init(num, XF_GPIO_INPUT_PULLUP));
    }


    button_init(handle, pin_level, press_level, num);

    return XF_OK;
}


xf_err_t xf_button_ticks(xf_timer_num_t tim_index)
{
    xf_timer_t *tim = xf_timer_create_by_ms(tim_index, 5, timeout_cb, NULL);
    MB_ERR_CHECK(xf_timer_start(tim, XF_TIM_ALWAYS));
    return XF_OK;
}

/* ==================== [Static Functions] ================================== */

static uint8_t pin_level(uint8_t btn_id)
{
    return xf_gpio_read(btn_id);
}

static void timeout_cb(xf_timer_t *timer)
{
    button_ticks();
}
