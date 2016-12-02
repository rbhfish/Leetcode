#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	string convertINTtoRoman(int nTarget)
	{
		int nDivision[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
		string strDivision[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
		
		string strResult;
		int nRemainder = nTarget;

		for(int nIndex = 0; nRemainder > 0; ++nIndex)
		{
			int nResult = nRemainder/nDivision[nIndex];
			nRemainder = nRemainder%nDivision[nIndex];
			for( ; nResult > 0; --nResult)
			{
				strResult += strDivision[nIndex];
			}
			
		}
		return strResult;
	}
	
};

int main() {
	// your code goes here
	int nTarget = 3001;
	Solution A;
	string strResult = A.convertINTtoRoman(nTarget);
	cout<<"the result is "<<strResult<<endl;
	return 0;
}