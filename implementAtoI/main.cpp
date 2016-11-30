#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

class Solution
{
	public:
	bool implementAtoI(string strA,int &nResult)
	{
		if(strA.empty())
			return false;
		string tmp;
		int nIndex = 0;
		int nSigh = 1;
		int nLen = strA.length();
		for(; strA[nIndex] == " "; ++nIndex)
		
		int tmpResult = 0;
		
		if(str[nIndex] == "-")
		{
			nIndex++;
			nSigh = -1;
		}
		else if(str[nIndex] == "+")
		{
			nIndex++;
			nSigh = 1;
		}
		
		for(; nIndex< nLen ; ++nIndex)
		{
			int nTmp = strA[nIndex] - '0';
			if(nTmp < 0 || nTmp > 9)
				return false;
			else
			{
				tmpResult = tmpResult*10 + nTmp;
				int limit = (nSigh>0)?INT_MAX:INT_MIN;
				if(tmpResult > abs(limit))
					return false;
			}
		}
		nResult = sign*tmpResult;
		return true;
	}
};

int main() {
	// your code goes here
	return 0;
}