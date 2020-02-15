load("@rules_foreign_cc//tools/build_defs:configure.bzl", "configure_make")

configure_make(
    name = "lib-openssl",
    configure_command = "config",
    configure_env_vars = {
    },
    configure_options = [
        "no-shared",
    ],
    lib_source = "@libopenssl//:all",
    #out_lib_dir = "lib",
    out_include_dir = "include",
    static_libraries = [
        "libssl.a",
        "libcrypto.a",
    ],
    visibility = ["//visibility:public"],
)

LINKOPTS = [
    "-lpthread",
    "-ldl",
]

cc_binary(
    name = "main",
    srcs = ["common.cc"],
    linkopts = LINKOPTS,
    deps = [
        "lib-openssl",
    ],
)
