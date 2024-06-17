import xf_build

srcs = ["MultiButton/*.c", "*.c"]
incs = ["."]

xf_build.collect(srcs=srcs, inc_dirs=incs)
