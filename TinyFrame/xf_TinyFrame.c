/**
 * @file xf_TinyFrame.c
 * @author cangyu (sky.kirto@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-13
 * 
 * @copyright Copyright (c) 2024, CorAL. All rights reserved.
 * 
 */

/* ==================== [Includes] ========================================== */
#include "xf_TinyFrame.h"

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Static Prototypes] ================================= */

/* ==================== [Static Variables] ================================== */

static xf_uart_num_t uart_num ;

/* ==================== [Macros] ============================================ */

/* ==================== [Global Functions] ================================== */

void TF_WriteImpl(TinyFrame *tf, const uint8_t *buff, uint32_t len)
{
    xf_uart_write(uart_num, buff, len, 0);
}

void xf_TF_uart_port(xf_uart_num_t uart)
{
    uart_num = uart;
}

/* ==================== [Static Functions] ================================== */
