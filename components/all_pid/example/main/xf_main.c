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
#include "apid.h"

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Static Prototypes] ================================= */

/* ==================== [Static Variables] ================================== */

/* ==================== [Macros] ============================================ */

/* ==================== [Global Functions] ================================== */

void xf_main(void)
{
    xf_printf("Hello all pid\r\n");
    apid_t pid;
    APID_Init(&pid, PID_POSITION, 3, 0.1, 0);
    APID_Enable(&pid); // 默认已经开启

    APID_Set_Target(&pid, 50);

    for (int i = 0; i < 16; ++i)
    {
        APID_Set_Present(&pid, 32);//用户定时更新当前值数据

        APID_Hander(&pid, 1);//cycle 如果不使用，建议设置为1,使用请输入两次调用的间隔单位ms
        xf_printf("pid out %f\r\n", APID_Get_Out(&pid));
    }

    APID_Fuzzy_Fast_Init(&pid, &(APID_Fuzzy_Init_t){
        .maximum = 100,
        .minimum = -100,

        .maxdKp = 0.1,
        .mindKp = -0.1,
        .qKp = 0.1,

        .maxdKi = 0.1,
        .mindKi = -0.1,
        .qKi = 0.1,

        .maxdKd = 0.1,
       .mindKd = -0.1,
        .qKd = 0.1});

    APID_Set_Target(&pid, 50);

    for (int i = 0; i < 16; ++i)
    {
        APID_Set_Present(&pid, 32);//用户定时更新当前值数据

        APID_Hander(&pid, 1);//cycle 如果不使用，建议设置为1,使用请输入两次调用的间隔单位ms
        xf_printf("pid out1 %f\r\n", APID_Get_Out(&pid));
    }



    static apid_auto_tune_ZNmode_t tuner;
    apid_auto_tune_ZNmode_init(&pid,&tuner,ZNModeLessOvershoot,300,-20000,20000,20);
    for (int i = 0; i < 16; ++i)
    {
        APID_Set_Present(&pid, 32);//用户定时更新当前值数据

        APID_Hander(&pid, 1);//cycle 如果不使用，建议设置为1,使用请输入两次调用的间隔单位ms
        xf_printf("pid out1 %f\r\n", APID_Get_Out(&pid));
    }
}

/* ==================== [Static Functions] ================================== */
