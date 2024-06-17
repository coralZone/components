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
#include "re.h"
#include <string.h>

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Static Prototypes] ================================= */

/* ==================== [Static Variables] ================================== */

/* ==================== [Macros] ============================================ */

/* ==================== [Global Functions] ================================== */

void xf_main(void)
{
    const char* pattern = "a*b";
    const char* text = "aaab"; 

    re_t compiled_pattern = re_compile(pattern);

    int matchlength = 0;
    int match = re_matchp(compiled_pattern, text, &matchlength);

    if (match != -1) {
        xf_printf("匹配成功，匹配长度: %d\n", matchlength);
        char matched_text[matchlength + 1];
        strncpy(matched_text, text + match, matchlength);
        matched_text[matchlength] = '\0';
        xf_printf("匹配的子串: %s\n", matched_text);
    } else {
        xf_printf("匹配失败\n");
    }


}

/* ==================== [Static Functions] ================================== */
