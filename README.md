# bazel c++ workspace exapmle
protobuf grpc gflag glog gtest等库的bazel编译方法和使用样例

### 注意事项
* grpc的编译未使用grpc项目自带的BUILD文件，而使用本地grpc.BUILD文件。原因为: 
    1）grpc依赖于third_party/nanopb/*.h文件，需要生称对应位置的头文件,
    ```python
    genrule(
        name = "pb_h",
        outs = ["third_party/nanopb/pb.h"],
        cmd = "echo '#include <pb.h>' >$@",
        visibility = ["//visibility:private"],
    )

    genrule(
        name = "pb_decode_h",
        outs = ["third_party/nanopb/pb_decode.h"],
        cmd = "echo '#include <pb_decode.h>' >$@",
        visibility = ["//visibility:private"],
    )

    genrule(
        name = "pb_encode_h",
        outs = ["third_party/nanopb/pb_encode.h"],
        cmd = "echo '#include <pb_encode.h>' >$@",
        visibility = ["//visibility:private"],
    )
    ```
    2) grpc模块需要--std=gnu99
* WORKSPACE中明确了protobuf和grpc库依赖
    ```python
    #use grpc.BUILD(https://github.com/tensorflow/tensorflow/blob/master/grpc.BUILD) instead of
    #grpc's raw BUILD file.
    #BUILD file of grpc has two problems:
    #1) missing nanopb header file.
    #2) grpc_unsecure needs gnu99.
    new_http_archive(
        name = "grpc",
        url = "https://github.com/grpc/grpc/archive/v1.0.0.tar.gz",
        sha256 = "c9bc77a4b20e67521f339d78b24375f6a1eddd8d203bb32796406a8005ee1c2a",
        strip_prefix = "grpc-1.0.0",
        build_file = "grpc.BUILD",
    )
    #protobuf expects //external:grpc_cpp_plugin to point to grpc's
    #C++ plugin code generator.
    #grpc_cpp_plugin of protobuf expects grpc_lib, use grpc_unsecure as default.
    bind(
        name = "grpc_cpp_plugin",
        actual = "@grpc//:grpc_cpp_plugin",
    )

    bind(
        name = "grpc_lib",
        actual = "@grpc//:grpc_unsecure",
    )
    ```
* cc_proto_library
    定义在protobuf项目中的protobuf.bzl中。cc_proto_library在参数use_grpc_plugin为True情况下，使用//external:grpc_lib，因此需要应用定义//external:grpc_lib。在WORKSPACE中将@grpc//:grpc_unsecure bind为//external:grpc_lib，如果同一工程中不同的项目需要不同的//external:grpc_lib(比如有些项目需要@grpc//:grpc)，就会有冲突的问题，而不同项目中的BUILD文件也不能进行bind。这里可能的解决方案有自己实现cc_proto_library，将//external:grpc_lib作为一个参数传入，这样每个项目可以定义自己的grpc service需要的库

