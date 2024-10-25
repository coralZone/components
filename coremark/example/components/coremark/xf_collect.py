import xf_build

src_path = "../../../"

srcs = [
    "*.c",
    src_path + "*.c",
    src_path + "coremark_xf_port/core_portme.c",
    src_path + "coremark_xf_port/ee_printf.c", # 修改了输出接口
    src_path + "coremark-1.01/barebones/cvt.c",
    src_path + "coremark-1.01/core_list_join.c",
    src_path + "coremark-1.01/core_main.c",
    src_path + "coremark-1.01/core_matrix.c",
    src_path + "coremark-1.01/core_state.c",
    src_path + "coremark-1.01/core_util.c",
]

incs = [
    ".",
    src_path,
    src_path + "coremark-1.01",
    src_path + "coremark_xf_port",
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
