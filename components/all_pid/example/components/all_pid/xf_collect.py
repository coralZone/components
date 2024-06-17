import xf_build

srcs = [
    "../../../all_pid/src/*.c",
]

incs = ["../../../all_pid/src/"]

xf_build.collect(srcs=srcs, inc_dirs=incs)
