cc_library(
    name = "base64",
    srcs = [
        "base64.c",
    ],
    hdrs = [
        "base64.h",
    ],
)

cc_binary(
    name = "webserver",
    srcs = [
        "webserver.c",
    ],
    deps = [
        ":base64",
    ],
)

cc_binary(
    name = "http",
    srcs = [
        "http.c",
    ],
    deps = [
        ":base64",
    ],
)

cc_library(
    name = "hex",
    srcs = [
        "hex.c",
    ],
    hdrs = [
        "hex.h",
    ],
)

cc_library(
    name = "aes",
    srcs = [
        "aes.c",
    ],
    hdrs = [
        "aes.h",
    ],
    deps = [
        ":hex",
    ],
)


cc_library(
    name = "des",
    srcs = [
        "des.c",
    ],
    hdrs = [
        "des.h",
    ],
    deps = [
        ":hex",
    ],
)


cc_library(
    name = "rc4",
    srcs = [
        "rc4.c",
    ],
    hdrs = [
        "rc4.h",
    ],
    deps = [
        ":hex",
    ],
)