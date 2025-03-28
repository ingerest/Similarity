#include <string>

class Similarity
{
public:
	int getSimilarityScore(std::string str1, std::string str2)
	{
		int big = 0;
		int small = 0;

		if (str1.length() >= str2.length())
		{
			big = str1.length();
			small = str2.length();
		}
		else
		{
			big = str2.length();
			small = str1.length();
		}

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