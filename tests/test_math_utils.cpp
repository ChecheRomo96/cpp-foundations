#include <gtest/gtest.h>
#include "MathUtils.h"

TEST(MathUtils, ClampWithinRange) {
    EXPECT_FLOAT_EQ(MathUtils::Clamp(5.0f, 0.0f, 10.0f), 5.0f);
}

TEST(MathUtils, ClampBelowRange) {
    EXPECT_FLOAT_EQ(MathUtils::Clamp(-1.0f, 0.0f, 10.0f), 0.0f);
}

TEST(MathUtils, ClampAboveRange) {
    EXPECT_FLOAT_EQ(MathUtils::Clamp(11.0f, 0.0f, 10.0f), 10.0f);
}

TEST(MathUtils, MapMidpoint) {
    EXPECT_FLOAT_EQ(MathUtils::Map(5.0f, 0.0f, 10.0f, 0.0f, 100.0f), 50.0f);
}
