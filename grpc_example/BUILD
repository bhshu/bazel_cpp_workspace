load("@protobuf//:protobuf.bzl", "cc_proto_library") 

cc_binary(
    name = 'greeter_client',
    srcs = ['greeter_client.cc'],
    deps = [
        ':helloworld_proto',
        '@grpc//:grpc++_unsecure',
    ],
    linkopts = ['-ldl'],
)

cc_binary(
    name = 'greeter_server',
    srcs = ['greeter_server.cc'],
    deps = [
        ':helloworld_proto',
        '@grpc//:grpc++_unsecure',
        "//external:gflags",
        "//external:glog",
    ],
    linkopts = ['-ldl'],
)

cc_proto_library(
    name = "helloworld_proto",
    srcs = ["helloworld.proto"],
    protoc = "@protobuf//:protoc",   
    default_runtime = "@protobuf//:protobuf",
    use_grpc_plugin=True,
)
