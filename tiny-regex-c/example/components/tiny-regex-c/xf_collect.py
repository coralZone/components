import xf_build

srcs = [
    "../../../tiny-regex-c/re.c",
]

incs = ["../../../tiny-regex-c"]

xf_build.collect(srcs=srcs, inc_dirs=incs)
