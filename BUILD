package(default_visibility = ["//visibility:public"])

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

cc_library(
    name = "ecc",
    srcs = [
        "ecc.c",
    ],
    hdrs = [
        "ecc.h",
    ],
    deps = [
        ":huge",
    ],
)

cc_library(
    name = "sha",
    srcs = [
        "sha.c",
    ],
    hdrs = [
        "digest.h",
        "sha.h",
    ],
)

cc_library(
    name = "md5",
    srcs = [
        "md5.c",
    ],
    hdrs = [
        "digest.h",
        "md5.h",
    ],
)

cc_library(
    name = "dsa",
    srcs = [
        "dsa.c",
    ],
    hdrs = [
        "dsa.h",
    ],
    deps = [
        ":hex",
        ":huge",
        ":sha",
    ],
)

cc_library(
    name = "ecdsa",
    srcs = [
        "ecdsa.c",
    ],
    hdrs = [
        "ecdsa.h",
    ],
    deps = [
        ":dsa",
        ":ecc",
        ":sha",
    ],
)

cc_library(
    name = "hmac",
    srcs = [
        "hmac.c",
    ],
    hdrs = [
        "digest.h",
        "hmac.h",
    ],
    deps = [
        ":hex",
        ":md5",
        ":sha",
    ],
)

cc_library(
    name = "digest",
    srcs = [
        "digest.c",
    ],
    hdrs = [
        "digest.h",
    ],
    deps = [
        ":hex",
        ":md5",
        ":sha",
    ],
)

cc_binary(
    name = "digest-main",
    srcs = [
        "digest.c",
        "digest.h",
    ],
    local_defines = [
        "TEST_DIGEST=true",
    ],
    # hdrs = [
    # ],
    deps = [
        ":hex",
        ":md5",
        ":sha",
    ],
)
