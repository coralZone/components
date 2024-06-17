import xf_build

srcs = ["TinyFrame/TinyFrame.c", "*.c"]
incs = ["."]

xf_build.collect(srcs=srcs, inc_dirs=incs)
