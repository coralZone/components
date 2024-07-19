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
#include "xf_cat.h"

/* ==================== [Defines] =========================================== */

#define UART_NUM        1
#define UART_BAUDRATE   115200
#define UART_TX_NUM     4
#define UART_RX_NUM     5

/* ==================== [Typedefs] ========================================== */

/* ==================== [Static Prototypes] ================================= */

static int print_run(const struct cat_command *cmd);
static int print_cmd_list(const struct cat_command *cmd);

/* ==================== [Static Variables] ================================== */

static uint8_t x;
static uint8_t y;
static char message[16];

static struct cat_variable print_vars[] = {
        {
                .type = CAT_VAR_UINT_DEC,
                .data = &x,
                .data_size = sizeof(x),
                .name = "X",
                .access = CAT_VAR_ACCESS_READ_WRITE,
        },
        {
                .type = CAT_VAR_UINT_DEC,
                .data = &y,
                .data_size = sizeof(y),
                .name = "Y",
                .access = CAT_VAR_ACCESS_READ_WRITE,
        },
        {
                .type = CAT_VAR_BUF_STRING,
                .data = message,
                .data_size = sizeof(message),
                .name = "MESSAGE",
                .access = CAT_VAR_ACCESS_READ_WRITE,
        }
};

static struct cat_command cmds[] = {
        {
                .name = "+PRINT",
                .description = "Printing something special at (X,Y).",
                .run = print_run,
                .var = print_vars,
                .var_num = sizeof(print_vars) / sizeof(print_vars[0]),
                .need_all_vars = true
        },
        {
                .name = "#HELP",
                .run = print_cmd_list,
        }
};

static uint8_t buf[512];

static struct cat_command_group cmd_group = {
        .cmd = cmds,
        .cmd_num = sizeof(cmds) / sizeof(cmds[0]),
};

static struct cat_command_group *cmd_desc[] = {
        &cmd_group
};

static struct cat_descriptor desc = {
        .cmd_group = cmd_desc,
        .cmd_group_num = sizeof(cmd_desc) / sizeof(cmd_desc[0]),

        .buf = buf,
        .buf_size = sizeof(buf)
};

/* ==================== [Macros] ============================================ */

/* ==================== [Global Functions] ================================== */

void xf_main(void)
{
    xf_hal_uart_init(UART_NUM, UART_BAUDRATE);
    xf_hal_uart_set_gpio(UART_NUM, UART_TX_NUM, UART_RX_NUM);
    xf_hal_uart_enable(UART_NUM);
    xf_cat_init(1, &desc);
    xf_cat_service();
}

/* ==================== [Static Functions] ================================== */

static int print_run(const struct cat_command *cmd)
{
        printf("some printing at (%d,%d) with text \"%s\"\n", x, y, message);
        return 0;
}

/* run command handler attached to HELP command for printing commands list */
static int print_cmd_list(const struct cat_command *cmd)
{
        return CAT_RETURN_STATE_PRINT_CMD_LIST_OK;
}


