#include "gmock/gmock.h"
#include "similarity.cpp"


TEST(TestGroup, TestSameLength)
{
	Similarity similarity;
	int result = similarity.getSimilarityScore("ASD", "DSA");
	EXPECT_EQ(60, result);
}

int main()
{
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}