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

cc_library(
    name = "dh",
    hdrs = [
        "dh.h",
    ],
)

cc_library(
    name = "ecc_int",
    srcs = [
        "ecc_int.c",
    ],
    hdrs = [
        "ecc_int.h",
    ],
    deps = [
      #  ":hex",
    ],
)

cc_library(
    name = "huge",
    srcs = [
        "huge.c",
    ],
    hdrs = [
        "huge.h",
    ],
    deps = [
        ":hex",
    ],
)

cc_library(
    name = "rsa",
    srcs = [
        "rsa.c",
    ],
    hdrs = [
        "rsa.h",
    ],
    deps = [
        ":hex",
        ":huge",
    ],
)