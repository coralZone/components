/**
 * @file cat.h
 * @author cangyu (sky.kirto@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-13
 * 
 * @copyright Copyright (c) 2024, CorAL. All rights reserved.
 * 
 */

#ifndef __XF_CAT_H__
#define __XF_CAT_H__

/* ==================== [Includes] ========================================== */
#include "xf_err.h"
#include "xf_hal.h"
#include "cAT/src/cat.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

xf_err_t xf_cat_init(xf_uart_num_t num, struct cat_descriptor *desc);
xf_err_t xf_cat_service(xf_timer_num_t tim_index);

/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // __XF_CAT_H__
