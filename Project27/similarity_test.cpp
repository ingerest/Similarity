#include "gmock/gmock.h"
#include "similarity.cpp"

class TestFixture : public ::testing::Test
{
public:
	Similarity similarity;

	void executeSimilarity(int score, std::string str1, std::string str2)
	{
		int result = similarity.getSimilarityScore(str1, str2);
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

int main()
{
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}