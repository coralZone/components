# coremark - coremark 基准测试示例

## 支持情况

1.  espressif

    1.  esp32

1.  nearlink

    1.  ws63
    1.  bs21

## 示例简述

本示例演示 xfuison 平台移植 coremark 并运行 coremark 基准测试。

## 如何使用

1.  所需的软件和硬件。

    1.  外部软件包。

        无。

    1.  硬件。

        通用。

1.  配置。

    1.  迭代次数。

        通过 `xf menuconfig` 可以配置 coremark 迭代次数，请确保迭代次数足够大，能让 coremark 运行时间超过 10s.

        推荐迭代次数：

        1.  ws63: 10000
        1.  bs21: 3000
        1.  esp32: 8000

    1.  对于 esp32.

        请用 `xf menuconfig sub` 打开原生 sdk 菜单，并修改 cpu 频率为 240M, 优化等级开到 -O2。
        当前示例只是测试 esp32 的单核性能。

    1.  关于 osal。

        1.  配置位于 `Menu path: (Top) -> public components -> xf_osal -> Use osal → OSAL Port`.
        1.  对于 esp32, 请选择 `FreeRTOS OSAL`.
        1.  对于 ws63 和 bs21, 请选择 `CMSIS OSAL`.

1.  构建和烧录步骤与要点。

    无。

## 运行现象

本示例启动后立刻进行 coremark 基准测试，正常情况下至少需要等待 10s 才有正常输出结果，如 `CoreMark 1.0 : 734.411905 / GCC7.3.0 -O3 / STACK`.

## 常见问题

如果输出 `ERROR! Must execute for at least 10 secs for a valid result!` 则说明迭代次数太少，请打开菜单增加位于 `(Top) -> user components -> coremark -> Number of iterations of coremark.` 的迭代次数。

## 示例平台差异

此示例对以下目标无明显差异：

1. esp32
1. ws63
1. bs21

## 运行日志

以下是 esp32 的运行日志。

```
I (48)-xf_main: coremark start!
2K performance run parameters for coremark.
CoreMark Size    : 666
Total ticks      : 16429140
Total time (secs): 16.429140
Iterations/Sec   : 486.939669
Iterations       : 8000
Compiler version : GCC11.2.0
Compiler flags   : -O3
Memory location  : STACK
seedcrc          : 0xe9f5
[0]crclist       : 0xe714
[0]crcmatrix     : 0x1fd7
[0]crcstate      : 0x8e3a
[0]crcfinal      : 0x5275
Correct operation validated. See readme.txt for run and reporting rules.
CoreMark 1.0 : 486.939669 / GCC11.2.0 -O3 / STACK
I (16516)-xf_main: coremark done!
```

以下是 ws63 的运行日志。

```
I (142)-xf_main: coremark start!
xo update temp:3,diff:0,xo:0x3083c
2K performance run parameters for coremark.
CoreMark Size    : 666
Total ticks      : 13616311
Total time (secs): 13.616311
Iterations/Sec   : 734.413308
Iterations       : 10000
Compiler version : GCC7.3.0
Compiler flags   : -O3
Memory location  : STACK
seedcrc          : 0xe9f5
[0]crclist       : 0xe714
[0]crcmatrix     : 0x1fd7
[0]crcstate      : 0x8e3a
[0]crcfinal      : 0x988c
Correct operation validated. See readme.txt for run and reporting rules.
CoreMark 1.0 : 734.413308 / GCC7.3.0 -O3 / STACK
I (13799)-xf_main: coremark done!
```

以下是 bs21 的运行日志。

```
I (85)-xf_main: coremark start!
2K performance run parameters for coremark.
CoreMark Size    : 666
Total ticks      : 15337316
Total time (secs): 15.337316
Iterations/Sec   : 195.601369
Iterations       : 3000
Compiler version : GCC7.3.0
Compiler flags   : -O3
Memory location  : STACK
seedcrc          : 0xe9f5
[0]crclist       : 0xe714
[0]crcmatrix     : 0x1fd7
[0]crcstate      : 0x8e3a
[0]crcfinal      : 0xcc42
Correct operation validated. See readme.txt for run and reporting rules.
CoreMark 1.0 : 195.601369 / GCC7.3.0 -O3 / STACK
I (15462)-xf_main: coremark done!
```
