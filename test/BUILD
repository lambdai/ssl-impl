cc_library(
    name = "test_common",
    srcs = [
        "test_common.cc",
    ],
    hdrs = [
        "test_common.h",
    ],
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "@gtest//:main",
    ],
)

cc_test(
    name = "digest_test",
    srcs = [
        "digest_test.cc",
    ],
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "//src:digest",
        "@gtest//:main",
    ],
)

cc_test(
    name = "asn1_test",
    srcs = [
        "asn1_test.cc",
    ],
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "//src:asn1",
        "@gtest//:main",
    ],
)

cc_test(
    name = "x509_test",
    srcs = [
        "x509_test.cc",
    ],
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "//src:x509",
        "@gtest//:main",
    ],
)

cc_test(
    name = "prf_test",
    srcs = [
        "prf_test.cc",
    ],
    copts = ["-Iexternal/gtest/include"],
    deps = [
        ":test_common",
        "//src:prf",
        "@gtest//:main",
    ],
)
