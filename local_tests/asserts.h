#ifndef MY_ASSERT_H
#define MY_ASSERT_H

#ifndef GOOGLE_TEST_BRIDGE
    #define QLL_TEST(TestSuite, TestName) void Dummy_##TestSuite##_##TestName()
    #define QLL_ASSERT_EQ(actual, expected) (void)(actual); (void)(expected);
#endif

#endif