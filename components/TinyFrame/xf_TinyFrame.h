/**
 * @file xf_TinyFrame.h
 * @author cangyu (sky.kirto@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-13
 * 
 * @copyright Copyright (c) 2024, CorAL. All rights reserved.
 * 
 */

#ifndef __XF_TINYFRAME_H__
#define __XF_TINYFRAME_H__

/* ==================== [Includes] ========================================== */
#include "TinyFrame/TinyFrame.h"
#include "xf_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

void xf_TF_uart_port(xf_uart_num_t uart);

/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // __XF_TINYFRAME_H__
