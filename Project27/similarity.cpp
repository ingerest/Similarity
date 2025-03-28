#include <string>
#include <set>

class Similarity
{
public:
	int getSimilarityLengthScore(std::string str1, std::string str2)
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

	int getSimilarityAlphaScore(std::string str1, std::string str2)
	{
		std::set<char> set1, set2;

		for (char ch : str1) {
			if (isupper(ch)) set1.insert(ch);
		}
		for (char ch : str2) {
			if (isupper(ch)) set2.insert(ch);
		}

		int sameCnt = 0;
		for (char ch : set1) {
			if (set2.count(ch)) sameCnt++;
		}

		std::set<char> unionSet = set1;
		unionSet.insert(set2.begin(), set2.end());
		int totalCnt = unionSet.size();

		if (totalCnt == 0) return 0;

		return ((double)sameCnt / (double)totalCnt) * 40;
	}
};