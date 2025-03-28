#include <string>

class Similarity
{
public:
	int getSimilarityScore(std::string str1, std::string str2)
	{
		int big = str1.length();
		int small = str2.length();

		if (str1.length() < str2.length()) std::swap(big, small);

		if (big == small)
		{
			return 60;
		}
		else if (big / small >= 2)
		{
			return 0;
		}
		
		int gap = big - small;
		return (1 - (double)gap / (double)small) * 60;
	}
};