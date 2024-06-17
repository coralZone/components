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

    xf_uart_init(1, 115200, XF_UART_PRESET_DEFAULT, 128, 128, 4, 5, NC, NC);
    xf_TF_uart_port(1);

    //设置TinyFrame库
    demo_tf = TF_Init(TF_MASTER); // 1 = master, 0 = slave
    // 添加lintener
    TF_AddGenericListener(demo_tf, myListener);

    printf("------ Simulate sending a message --------\n");

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
    
    printf("This should fail:\n");
    
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
    printf("OK - ID Listener triggered for msg!\n");
    dumpFrameInfo(msg);
    return TF_CLOSE;
}

static void dumpFrameInfo(TF_Msg *msg)
{
    printf("\033[33mFrame info\n"
               "  type: %02Xh\n"
               "  data: \"%.*s\"\n"
               "   len: %u\n"
               "    id: %Xh\033[0m\n\n",
           msg->type, msg->len, msg->data, msg->len, msg->frame_id);
}

