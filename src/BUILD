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

cc_library(
    name = "prf",
    srcs = [
        "prf.c",
    ],
    hdrs = [
        "prf.h",
    ],
    deps = [
        ":digest",
        ":hex",
        ":hmac",
        ":md5",
        ":sha",
    ],
)

cc_library(
    name = "tls",
    srcs = [
        "tls.c",
    ],
    hdrs = [
        "tls.h",
    ],
    deps = [
        ":aes",
        ":des",
        ":dh",
        ":digest",
        ":hex",
        ":hmac",
        ":md5",
        ":prf",
        ":rc4",
        ":sha",
        ":x509",
    ],
)

cc_binary(
    name = "https",
    srcs = [
        "https.c",
    ],
    deps = [
        ":tls",
    ],
)

cc_library(
    name = "asn1",
    srcs = [
        "asn1.c",
    ],
    hdrs = [
        "asn1.h",
    ],
    deps = [
        ":base64",
    ],
)

cc_library(
    name = "x509",
    srcs = [
        "x509.c",
    ],
    hdrs = [
        "x509.h",
    ],
    deps = [
        ":asn1",
        ":digest",
        ":dsa",
        ":huge",
        ":md5",
        ":rsa",
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
    deps = [
        ":hex",
        ":md5",
        ":sha",
    ],
)

cc_binary(
    name = "asn1-main",
    srcs = [
        "asn1.c",
        "asn1.h",
    ],
    local_defines = [
        "TEST_ASN1=true",
    ],
    deps = [
        ":base64",
    ],
)

cc_binary(
    name = "x509-main",
    srcs = [
        "x509.c",
        "x509.h",
    ],
    local_defines = [
        "TEST_X509=true",
    ],
    deps = [
        ":asn1",
        ":digest",
        ":dsa",
        ":huge",
        ":md5",
        ":rsa",
        ":sha",
    ],
)
