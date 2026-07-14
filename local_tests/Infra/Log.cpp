// SPDX-License-Identifier: MIT-0 OR Zlib OR MIT OR Apache-2.0
module;
#include <gtest/gtest.h>
import QLL.Core.Base.Types;
using namespace testing::internal;
using namespace QLL;
TEST(loggerTest, OutputsDebug) {
    CaptureStdout();
    Log.Log(LogLevel::Debug)
}