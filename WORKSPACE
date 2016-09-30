git_repository(
    name = "gflags_git",
    commit = "7d31c02de8345d0a12010a0c1c8ebae37898f10e",
    remote = "https://github.com/gflags/gflags.git",
)

bind(
    name = "gflags",
    actual = "@gflags_git//:gflags",
)

new_git_repository(
    name = "googletest",
    build_file = "gmock.BUILD",
    remote = "https://github.com/google/googletest",
    tag = "release-1.8.0",
)

bind(
    name = "gtest",
    actual = "@googletest//:gtest",
)

bind(
    name = "gtest_main",
    actual = "@googletest//:gtest_main",
)

bind(
    name = "glog",
    actual = "//third_party/glog:glog"
)

http_archive(
    name = "protobuf",
    url = "http://github.com/google/protobuf/archive/v3.1.0.tar.gz",
    sha256 = "0a0ae63cbffc274efb573bdde9a253e3f32e458c41261df51c5dbc5ad541e8f7",
    strip_prefix = "protobuf-3.1.0",
)

# grpc expects //external:protobuf_clib and //external:protobuf_compiler
# to point to the protobuf's compiler library.
bind(
    name = "protobuf_clib",
    actual = "@protobuf//:protoc_lib",
)

bind(
    name = "protobuf_compiler",
    actual = "@protobuf//:protoc_lib",
)

#use grpc.BUILD(https://github.com/tensorflow/tensorflow/blob/master/grpc.BUILD) instead of grpc's raw BUILD file
#BUILD file of grpc has two problems:
#1) missing nanopb header file.
#2) grpc_unsecure needs gnu99
new_http_archive(
    name = "grpc",
    url = "https://github.com/grpc/grpc/archive/v1.0.0.tar.gz",
    sha256 = "c9bc77a4b20e67521f339d78b24375f6a1eddd8d203bb32796406a8005ee1c2a",
    strip_prefix = "grpc-1.0.0",
    build_file = "grpc.BUILD",
)

# protobuf expects //external:grpc_cpp_plugin to point to grpc's
# C++ plugin code generator.
# grpc_cpp_plugin of protobuf expects grpc_lib, use grpc_unsecure as default.
bind(
    name = "grpc_cpp_plugin",
    actual = "@grpc//:grpc_cpp_plugin",
)

bind(
    name = "grpc_lib",
    actual = "@grpc//:grpc_unsecure",
)

new_http_archive(
    name = "nanopb_git",
    url = "http://github.com/nanopb/nanopb/archive/1251fa1065afc0d62f635e0f63fec8276e14e13c.tar.gz",
    sha256 = "ab1455c8edff855f4f55b68480991559e51c11e7dab060bbab7cffb12dd3af33",
    strip_prefix = "nanopb-1251fa1065afc0d62f635e0f63fec8276e14e13c",
    build_file = "nanopb.BUILD",
)

bind(
    name = "nanopb",
    actual = "@nanopb_git//:nanopb",
)

new_http_archive(
    name = "zlib_archive",
    url = "http://zlib.net/zlib-1.2.8.tar.gz",
    sha256 = "36658cb768a54c1d4dec43c3116c27ed893e88b02ecfcb44f2166f9c0b7f2a0d",
    strip_prefix = "zlib-1.2.8",
    build_file = "zlib.BUILD",
)

bind(
    name = "zlib",
    actual = "@zlib_archive//:zlib",
)

#grpc_unsecure does not need libssl
#http_archive(
#    name = "boringssl",
#    url = "http://github.com/google/boringssl/archive/bbcaa15b0647816b9a1a9b9e0d209cd6712f0105.tar.gz",
#    sha256 = "025264d6e9a7ad371f2f66d17a28b6627de0c9592dc2eb54afd062f68f1f9aa3",
#    strip_prefix = "boringssl-bbcaa15b0647816b9a1a9b9e0d209cd6712f0105",
#)

#bind(
#    name = "libssl",
#    actual = "@boringssl//:ssl",
#)
