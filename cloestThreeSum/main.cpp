#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class Solution
{
	public:
	int findClosestSum(vector<int> &vArray, int nTarget)
	{
		if(vArray.size() < 3)
			return INT_MAX;
		
		sort(vArray.begin(),vArray.end());
		
		int nResult = 0;
		int nDiff = 0;
		auto last = vArray.end() - 1;
		for(auto i = vArray.begin(); i < last - 1 ; ++i)
		{
			if(i > vArray.begin() && (*i == *( i - 1)))
				continue;
			
			auto j = i + 1;
			auto k = last;
			int nSum = *i + *j + *k;
			
			int nTmp = abs(nSum - nTarget);
			if(nTmp < nDiff)
			{
				nDiff = nTmp;
				nResult = nSum;
			}
			
			if(nSum < nTarget)
			{
				j++;
				while(j < k && (*j == *(j - 1)))
					j++;
			}
			else if(nSum > nTarget)
			{
				k--;
				while((j < k) && (*k == *(k + 1)))
					k--;
			}
			else
			{
				nResult = 0;
				break;
			}
		}
		return nResult;
	}
};

int main() {
	// your code goes here
	int nArray[] = {-4,-6,-2,3,5,-1,0,2,0,6,7,-7,-9,10};
	int nLen = sizeof(nArray)/sizeof(int);
	vector<int> vArray(nArray, nArray + nLen);
	Solution A;
	int nResult = A.findClosestSum(vArray,0);
	if(nResult != INT_MAX)
	{
		cout<<"nResult = "<<nResult<<endl;
	}
	
	return 0;
}