#include <gtest/gtest.h>
#include "ProgressState.h"

TEST(ProgressStateTest, zeroValueOfValidTargetIsZeroPercent)
{
	ProgressState progress(100);
	progress.setValue(0);
	ASSERT_EQ((unsigned int) 0, progress.getPercentage());
}


TEST(ProgressStateTest, negativeValueOfValidTargetIsZeroPercent)
{
	ProgressState progress(100);
	progress.setValue(-100);
	ASSERT_EQ((unsigned int) 0, progress.getPercentage());
}


TEST(ProgressStateTest, valueEqualTargetIsHundredPercent)
{
	ProgressState progress(200);
	progress.setValue(200);
	ASSERT_EQ((unsigned int) 100, progress.getPercentage());
}

TEST(ProgressStateTest, normalTest)
{
	ProgressState progress(100);
	progress.setValue(10);
	ASSERT_EQ((unsigned int) 10, progress.getPercentage());
}

TEST(ProgressStateTest, OverTest)
{
	ProgressState progress(10);
	progress.setValue(20);
	ASSERT_EQ((unsigned int) 100, progress.getPercentage());
}
