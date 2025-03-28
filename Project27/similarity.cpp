#include <string>

class Similarity
{
public:
	int getSimilarityScore(std::string str1, std::string str2)
	{
		if (str1.length() == str2.length())
		{
			return 60;
		}

		return 0;
	}
};