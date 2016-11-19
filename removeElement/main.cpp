#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int RemoveInstancebyGivenTarget(vector<int> &vArray, int nTarget)
	{
		if(vArray.size() == 0)
			return 0;
			
		int nIndex = 0;
		for(int i = 0; i < vArray.size(); ++i)
		{
			if(vArray[i] != nTarget)
			{
				vArray[nIndex] = vArray[i];
				nIndex++;
			}
		}
		return nIndex;
	}
};

int main() {
	// your code goes here
	int nArray[] = {0,2,4,6,8,10,12,14};
	int nLen = sizeof(nArray)/sizeof(int);
	vector<int> vArray(nArray, nArray + nLen);
	Solution A;
	int nLength = A.RemoveInstancebyGivenTarget(vArray,0);
	for(auto i : vArray)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}