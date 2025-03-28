#include "gmock/gmock.h"
#include "similarity.cpp"

class TestFixture : public ::testing::Test
{
public:
	Similarity similarity;

	void executeSimilarity(int score, std::string str1, std::string str2)
	{
		int result = similarity.getSimilarityLengthScore(str1, str2);
		EXPECT_EQ(score, result);
	}

	void executeSimilarityAlpha(int score, std::string str1, std::string str2)
	{
		int result = similarity.getSimilarityAlphaScore(str1, str2);
		EXPECT_EQ(score, result);
	}
};

TEST_F(TestFixture, TestSameLength)
{
	executeSimilarity(60, "ASD", "DSA");
}

TEST_F(TestFixture, TestDoubleDifferentLength)
{
	executeSimilarity(0, "ASD", "DSADFD");
}

TEST_F(TestFixture, TestPartialScore)
{
	executeSimilarity(40, "ASD", "DSAD");
}

TEST_F(TestFixture, TestSameAlpha)
{
	executeSimilarityAlpha(40, "ASD", "DSA");
}

TEST_F(TestFixture, TestDifferentAlpha)
{
	executeSimilarityAlpha(0, "A", "BB");
}

TEST_F(TestFixture, TestSameAlpha2)
{
	executeSimilarityAlpha(40, "AAABB", "BA");
}

TEST_F(TestFixture, TestPartialScoreAlpha)
{
	executeSimilarityAlpha(20, "AA", "AAE");
}
int main()
{
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}