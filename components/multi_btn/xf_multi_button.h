/**
 * @file multi_btn.h
 * @author cangyu (sky.kirto@qq.com)
 * @brief
 * @version 0.1
 * @date 2024-06-12
 *
 * @copyright Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

#ifndef __XF_MULTI_BUTTON_H__
#define __XF_MULTI_BUTTON_H__

/* ==================== [Includes] ========================================== */

#include "MultiButton/multi_button.h"
#include "xf_err.h"
#include "xf_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

xf_err_t xf_button_init(struct Button *handle, xf_gpio_num_t num,
                         uint8_t press_level);
xf_err_t xf_button_ticks(xf_timer_num_t tim_index);

/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // __XF_MULTI_BUTTON_H__
