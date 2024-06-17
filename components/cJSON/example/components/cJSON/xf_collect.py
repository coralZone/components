import xf_build

srcs = [
    "../../../cJSON/cJSON_Utils.c",
    "../../../cJSON/cJSON.c"
]

incs = ["../../../cJSON"]

xf_build.collect(srcs=srcs, inc_dirs=incs)
