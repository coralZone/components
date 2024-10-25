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

#include "coremark.h"

#include "xf_utils.h"
#include "xf_osal.h"
#include "xf_sys.h"

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Static Prototypes] ================================= */

static void _example_thread(void *argument);

/* ==================== [Static Variables] ================================== */

static const char *TAG = "xf_main";

static xf_osal_thread_t s_thread_hdl = NULL;
#define EX_THREAD_NAME          "coremark"
#define EX_THREAD_PRIORITY      XF_OSAL_PRIORITY_HIGH
#define EX_THREAD_STACK_SIZE    (1024 * 8)
static const xf_osal_thread_attr_t s_thread_attr = {
    .name       = EX_THREAD_NAME,
    .priority   = EX_THREAD_PRIORITY,
    .stack_size = EX_THREAD_STACK_SIZE,
};

/* ==================== [Macros] ============================================ */

/* ==================== [Global Functions] ================================== */

void xf_main(void)
{
    s_thread_hdl = xf_osal_thread_create(_example_thread, NULL, &s_thread_attr);
    if (s_thread_hdl == NULL) {
        XF_LOGE(TAG, "xf_osal_thread_create error");
        return;
    }
}

/* ==================== [Static Functions] ================================== */

static void _example_thread(void *argument)
{
    UNUSED(argument);

    xf_sys_watchdog_disable();

    XF_LOGI(TAG, "coremark start!");
    /*
        在 components/coremark/coremark_xf_port/simple/core_portme.h
        内声明 core_main() 并覆盖 main().
     */
    core_main();
    XF_LOGI(TAG, "coremark done!");

    xf_osal_thread_delete(NULL);
}
