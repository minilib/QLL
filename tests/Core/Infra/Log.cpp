// SPDX-License-Identifier: MIT-0 OR Zlib OR MIT OR Apache-2.0
// //Copyright (c) 2026 minilib
#include <gtest/gtest.h>
import QLL.Core.Base.Types;
import QLL.Core.Infra.Log;

using namespace testing::internal;
using namespace QLL;
TEST(loggerTest, OutputsDebug) {
    CaptureStdout();
    Logger.Log(LogLevel::Debug)
}