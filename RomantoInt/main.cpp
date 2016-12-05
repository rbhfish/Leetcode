#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int mapRoman(char str)
	{
			
		int nResult = 0;
		switch(str)
		{
			case 'I':
				nResult = 1;
				break;
			case 'V':
				nResult = 5;
				break;
			case 'X':
				nResult = 10;
				break;
			case 'L':
				nResult = 50;
				break;
			case 'C':
				nResult = 100;
				break;
			case 'D':
				nResult = 500;
				break;
			case 'M':
				nResult = 1000;
				break;
			default:
				break;
		}
		return nResult;
	}
	int translateRomantoInt(string str)
	{
		int nResult = 0;
		if(str.length() < 1)
			return nResult;
			
		for(int nIndex = 0; nIndex < str.length(); ++nIndex)
		{
			int nTmp = nIndex + 1;
			int m = mapRoman(str[nIndex]);
			int n = (nTmp < str.length())?mapRoman(str[nTmp]):0;
			if(m > n)
			{
				nResult += m;
			}
			else
			{
				nResult +=n - m;
				nIndex++;
			}
		}
		return nResult;
	}
};

int main() {
	// your code goes here
	string str = "MCMVM";
	Solution A;
	int nResult = A.translateRomantoInt(str);
	cout<<nResult<<endl;
	return 0;
}