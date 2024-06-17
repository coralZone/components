#ifndef __XF_CONFIG_H__
#define __XF_CONFIG_H__

#define CONFIG_PLATFORM "esp32"
#define CONFIG_PLATFORM_PATH "/home/kirto/xfusion/boards/espressif/esp32"
#define CONFIG_PLATFORM_ESP32 1
#define CONFIG_EN_XF_HAL_GPIO 1
#define CONFIG_EN_XF_HAL_SYSTIME 1
#define CONFIG_EN_XF_HAL_UART 1
#define CONFIG_XF_UART_BAUD_RATE 115200
#define CONFIG_XF_LOG_DEFAULT_LEVEL_INFO 1
#define CONFIG_XF_LOG_DEFAULT_LEVEL 3
#define CONFIG_XF_LOG_MINIMUM_EQUALS_DEFAULT 1
#define CONFIG_XF_LOG_MINIMUM_LEVEL 3
#define CONFIG_XF_LOG_COLORS 1
#define CONFIG_XF_LOG_BUF_SIZE 64
#define CONFIG_XF_LOG_TIMESTAMP_TIME_MS 1
#define CONFIG_XF_LOG_NEWLINE_LF 1
#define CONFIG_XF_LOG_ENABLE_EXTRA_FMT 1
#define CONFIG_XF_LOG_ONLY_FILE_NAME 1
#define CONFIG_XF_PRINTF_EN_CUSTOM_PRINTF 1
#define CONFIG_PRINTF_NTOA_BUFFER_SIZE 32
#define CONFIG_PRINTF_FTOA_BUFFER_SIZE 32
#define CONFIG_PRINTF_DISABLE_SUPPORT_EXPONENTIAL 1
#define CONFIG_PRINTF_DEFAULT_FLOAT_PRECISION 6
#define CONFIG_XF_EVT_MAX_NUM 100
#define CONFIG_XF_EVT_ALLOC_TASK_MAX_NUM 100
#define CONFIG_XF_EVT_TASK_MAX_NUM 100
#define CONFIG_XF_EVT_HANDLER_MAX_NUM 100
#define CONFIG_XF_EVT_CHECK_TICK_MS 1
#define CONFIG_XF_EVT_CHECK_TICK_BASE 0
#define CONFIG_XF_EVT_CHECK_DELAY 10
#define CONFIG_XF_EVT_SYNC_DELAY 10
#define CONFIG_XF_EVT_CHECK_BINDING_DELAY 10
#define CONFIG_XF_EVT_CHECK_BINDING_MAX_CNT 300
#define CONFIG_XF_EVT_CHECK_AND_DISPATCH_DEFAULT 1
#define CONFIG_XF_EVT_CHECK_AND_DISPATCH_MODE 0
#define CONFIG_XF_EVT_CARRIER_ONE 1
#define CONFIG_XF_EVT_TASK_CARRIER 0
#define CONFIG_XF_EVT_LOG_NOTABLE_0 1
#define CONFIG_XF_EVT_LOG_LEVEL 3
#define CONFIG_XF_INIT_DEBUG_UART_BAUD_RATE 115200
#define CONFIG_XF_INIT_DEBUG_UART_TX_RINGBUF_SIZE 128
#define CONFIG_XF_INIT_DEBUG_UART_RX_RINGBUF_SIZE 32
#define CONFIG_XF_RINGBUF_FILL_VAL 0x00
#define CONFIG_XF_RINGBUF_EN_CHECK_PARAMETER 1
#define CONFIG_XF_HEAP_SIZE 6144
#define CONFIG_XF_HEAP_DYNAMIC 1
#define CONFIG_LIBC_SYSCALLS_READ_TIMEOUT 1000
#define CONFIG_XF_ATOMIC_USING_AUTO 1
#define CONFIG_XF_ERR_TO_NAME_LOOKUP 1
#define CONFIG_XF_MUTEX_ENABLE_TIMEOUT 1
#define CONFIG_XF_MUTEX_USING_ATOMIC 1

#endif // __XF_CONFIG_H__
