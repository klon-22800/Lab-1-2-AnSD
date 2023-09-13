#include <gtest/gtest.h>
#include <matrix/matrix.h>

TEST(FunctionsTests, SumStubTest1) {
    // Arrange
    int lhs = 2;
    int rhs = 3;

    // Act
    int r = sum_stub(lhs, rhs);

    // Assert
    EXPECT_EQ(r, 5);
}