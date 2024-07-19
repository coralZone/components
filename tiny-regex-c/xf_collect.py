import xf_build

srcs = ["tiny-regex-c/re.c"]
incs = ["."]

xf_build.collect(srcs=srcs, inc_dirs=incs)
