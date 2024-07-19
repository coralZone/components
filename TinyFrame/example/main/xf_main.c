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
#include "xf_TinyFrame.h"

/* ==================== [Defines] =========================================== */

#define TAG "TinyFrame"

/* ==================== [Typedefs] ========================================== */

/* ==================== [Static Prototypes] ================================= */

static TF_Result myListener(TinyFrame *tf, TF_Msg *msg);
static TF_Result testIdListener(TinyFrame *tf, TF_Msg *msg);
static void dumpFrameInfo(TF_Msg *msg);

/* ==================== [Static Variables] ================================== */

static TinyFrame *demo_tf;

static bool do_corrupt = false;

/* ==================== [Macros] ============================================ */

/* ==================== [Global Functions] ================================== */

void xf_main(void)
{
    TF_Msg msg;
    const char *longstr = "Lorem ipsum dolor sit amet.";

    xf_hal_uart_init(1, 115200);
    xf_hal_uart_set_gpio(1, 4, 5);
    xf_hal_uart_enable(1);
    xf_TF_uart_port(1);

    //设置TinyFrame库
    demo_tf = TF_Init(TF_MASTER); // 1 = master, 0 = slave
    // 添加lintener
    TF_AddGenericListener(demo_tf, myListener);

    XF_LOGI(TAG, "------ Simulate sending a message --------");

    TF_ClearMsg(&msg);
    msg.type = 0x22;
    msg.data = (uint8_t *) "Hello TinyFrame";
    msg.len = 16;
    TF_Send(demo_tf, &msg);

    msg.type = 0x33;
    msg.data = (uint8_t *) longstr;
    msg.len = (TF_LEN) (strlen(longstr) + 1); // 添加null类型
    TF_Send(demo_tf, &msg);

    msg.type = 0x44;
    msg.data = (uint8_t *) "Hello2";
    msg.len = 7;
    TF_Send(demo_tf, &msg);

    msg.len = 0;
    msg.type = 0x77;
    TF_Query(demo_tf, &msg, testIdListener, NULL, 0);

    XF_LOGI(TAG, "This should fail:");

    // 测试校验和
    do_corrupt = true;
    msg.type = 0x44;
    msg.data = (uint8_t *) "Hello2";
    msg.len = 7;
    TF_Send(demo_tf, &msg);

}

/* ==================== [Static Functions] ================================== */

/** 一个监听器函数的示例 */
static TF_Result myListener(TinyFrame *tf, TF_Msg *msg)
{
    dumpFrameInfo(msg);
    return TF_STAY;
}

static TF_Result testIdListener(TinyFrame *tf, TF_Msg *msg)
{
    XF_LOGI(TAG, "OK - ID Listener triggered for msg!");
    dumpFrameInfo(msg);
    return TF_CLOSE;
}

static void dumpFrameInfo(TF_Msg *msg)
{
    XF_LOGI(TAG, "Frame info");
    XF_LOGI(TAG, "  type: %02X", msg->type);
    XF_LOGI(TAG, "  data: \"%.*s\"", msg->len, msg->data);
    XF_LOGI(TAG, "   len: %u", msg->len);
    XF_LOGI(TAG, "    id: %X", msg->frame_id);
}

