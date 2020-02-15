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
    # $ find -name "*.h" |grep openssl |head -1
    # ./include/openssl/ts.h
    out_include_dir = "include",
    # $ find -name "libssl.a"
    # ./libssl.a
    static_libraries = [
        "libssl.a",
        "libcrypto.a",
    ],
    visibility = ["//visibility:public"],
)

LINKOPTS = [
    # bazel-out/k8-fastbuild/bin/openssl/lib-openssl/lib/libcrypto.a(threads_pthread.o):threads_pthread.c:
    #     function CRYPTO_THREAD_lock_new: error: undefined reference to 'pthread_rwlock_init'
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
