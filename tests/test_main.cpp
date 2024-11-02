#include <gtest/gtest.h>
//#include "../src/YourHeaderFile.h"  // Include your source headers here

TEST(abc, TestCase1) {
    EXPECT_EQ(1, 1);  // Replace with your actual test logic
}

TEST(cdf, TestCase2) {
    EXPECT_TRUE(true);  // Replace with your actual test logic
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
