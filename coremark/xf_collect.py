import xf_build

src_path = "coremark-1.01/"

srcs = [
    "*.c",
    "coremark_xf_port/core_portme.c",
    "coremark_xf_port/ee_printf.c", # 修改了输出接口
    "coremark-1.01/barebones/cvt.c",
    "coremark-1.01/core_list_join.c",
    "coremark-1.01/core_main.c",
    "coremark-1.01/core_matrix.c",
    "coremark-1.01/core_state.c",
    "coremark-1.01/core_util.c",
]

incs = [
    ".",
    "coremark_xf_port",
    "coremark-1.01",
]

reqs = [
    "xf_utils",
    "xf_sys",
    "xf_osal",
]

cflags = [
    "-Wno-error",
    "-Wno-error=maybe-uninitialized",
    "-O3",
]

xf_build.collect(srcs=srcs, inc_dirs=incs, requires=reqs, cflags=cflags)
