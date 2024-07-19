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
#include "xf_task.h"

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Static Prototypes] ================================= */

static uint8_t pin_level(uint8_t btn_id);
static void timeout_cb(xf_task_t task);

/* ==================== [Static Variables] ================================== */

/* ==================== [Macros] ============================================ */

#define MB_ERR_CHECK(x) do {        \
            xf_err_t err_rc_ = (x); \
            if (err_rc_ != XF_OK) { \
                return err_rc_;     \
            }                       \
        } while (0)

/* ==================== [Global Functions] ================================== */

xf_err_t xf_button_init(struct Button *handle, xf_gpio_num_t num, uint8_t press_level)
{
    if (press_level) {
        MB_ERR_CHECK(xf_hal_gpio_init(num, XF_HAL_GPIO_DIR_IN));
        MB_ERR_CHECK(xf_hal_gpio_set_pull(num, XF_HAL_GPIO_PULL_DOWN));
    } else {
        MB_ERR_CHECK(xf_hal_gpio_init(num, XF_HAL_GPIO_DIR_IN));
        MB_ERR_CHECK(xf_hal_gpio_set_pull(num, XF_HAL_GPIO_PULL_UP));
    }

    button_init(handle, pin_level, press_level, num);

    return XF_OK;
}


xf_err_t xf_button_ticks(void)
{
    xf_ntask_create_loop(timeout_cb, NULL, 5, 10);
    return XF_OK;
}

/* ==================== [Static Functions] ================================== */

static uint8_t pin_level(uint8_t btn_id)
{
    return xf_hal_gpio_get_level(btn_id);
}

static void timeout_cb(xf_task_t task)
{
    button_ticks();
}
