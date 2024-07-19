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
#include "cJSON.h"
#include "cJSON_Utils.h"

/* ==================== [Defines] =========================================== */

#define TAG "cjson"

/* ==================== [Typedefs] ========================================== */

/* ==================== [Static Prototypes] ================================= */

/* ==================== [Static Variables] ================================== */

/* ==================== [Macros] ============================================ */

/* ==================== [Global Functions] ================================== */

void xf_main(void)
{
    // 定义一个复杂的 JSON 字符串
    const char *json_string = "{\"name\":\"John\", \"age\":30, \"address\":{\"city\":\"New York\", \"zipcode\":10001}, \"contacts\":[{\"type\":\"phone\", \"value\":\"123-456-7890\"}, {\"type\":\"email\", \"value\":\"john@example.com\"}]}";

    // 解析 JSON 字符串
    cJSON *root = cJSON_Parse(json_string);
    if (root == NULL) {
        XF_LOGI(TAG, "Failed to parse JSON");
        return;
    }

    // 定义指向目标数据的 JSON 指针路径
    const char *pointer_path = "/contacts/1/value";

    // 使用 cJSONUtils_GetPointer 获取路径中的 JSON 项
    cJSON *target_item = cJSONUtils_GetPointer(root, pointer_path);
    if (target_item == NULL) {
        XF_LOGI(TAG, "Failed to find target item");
        cJSON_Delete(root);
        return;
    }

    // 打印目标项的值
    char *target_value = target_item->valuestring;
    if (target_value != NULL) {
        XF_LOGI(TAG, "Target value: %s", target_value);
    } else {
        XF_LOGI(TAG, "Failed to print target value");
    }

    // 清理
    cJSON_Delete(root);

}

/* ==================== [Static Functions] ================================== */
