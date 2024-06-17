/**
 * @file cat.c
 * @author cangyu (sky.kirto@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-13
 * 
 * @copyright Copyright (c) 2024, CorAL. All rights reserved.
 * 
 */

/* ==================== [Includes] ========================================== */

#include "xf_cat.h"

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Static Prototypes] ================================= */

static int read_char(char *ch);
static int write_char(char ch);
static void timeout_cb(xf_timer_t *timer);

/* ==================== [Static Variables] ================================== */

static xf_uart_num_t uart_num ;
static struct cat_object at;
static struct cat_io_interface iface = {
        .read = read_char,
        .write = write_char
};

/* ==================== [Macros] ============================================ */

#define CAT_ERR_CHECK(x) do {        \
            xf_err_t err_rc_ = (x); \
            if (err_rc_ != XF_OK) { \
                return err_rc_;     \
            }                       \
        } while (0)

/* ==================== [Global Functions] ================================== */

xf_err_t xf_cat_init(xf_uart_num_t num, struct cat_descriptor *desc)
{
    uart_num = num;
    cat_init(&at, desc, &iface, NULL);
    return XF_OK;
}

xf_err_t xf_cat_service(xf_timer_num_t tim_index)
{
    xf_timer_t *tim = xf_timer_create_by_ms(tim_index, 10, timeout_cb, NULL);
    CAT_ERR_CHECK(xf_timer_start(tim, XF_TIM_ALWAYS));
    return XF_OK;
}

/* ==================== [Static Functions] ================================== */

static int read_char(char *ch)
{
    xf_uart_read(uart_num, ch, 1, 0);
    return 1;
}

static int write_char(char ch)
{
    xf_uart_write(uart_num, &ch, 1, 0);
    return 1;
}

static void timeout_cb(xf_timer_t *timer)
{
    cat_service(&at);
}

