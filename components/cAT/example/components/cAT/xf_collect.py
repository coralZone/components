import xf_build

srcs = ["../../../cAT/src/*.c", "../../../*.c"]
incs = ["../../../"]

xf_build.collect(srcs=srcs, inc_dirs=incs)
