#include <gtest/gtest.h>
#include "gtest_example/lib/hello-greet.h"

TEST(FactorialTest, Negative) {
  EXPECT_EQ(get_greet("Bazel"), "Hello Bazel");
}
