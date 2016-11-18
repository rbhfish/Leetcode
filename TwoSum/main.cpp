#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<int> findResult(vector<int> &vArray, int nTarget)
	{
		vector<int> vResult;
		if(vArray.size() < 2)
			return vResult;
		
		unordered_map<int,int> mapInput;
		
		
		for(int nIndex = 0; nIndex < vArray.size(); nIndex++)
		{
			mapInput[vArray[nIndex]  ]= nIndex;
		}
		
		for(int nIndex = 0; nIndex < vArray.size(); nIndex++)
		{
			int n = nTarget - vArray[nIndex];
			if(mapInput.find(n) != mapInput.end() && vArray[nIndex] < n)
			{
				unordered_map<int,int>::iterator it = mapInput.find(n);
				vResult.push_back(nIndex + 1);
				vResult.push_back(it->second + 1);
			}
		}
		return vResult;
	}
};

int main() {
	// your code goes here
	int nArray[] = {0,1,2,3,4,5,6,7,8,9};
	int nLen = sizeof(nArray)/sizeof(int);
	vector<int> vArray(nArray, nArray + nLen);
	int nTarget = 9;
	Solution A;
	vector<int> vResult = A.findResult(vArray,nTarget);
	for(auto i : vResult)
	{
		cout<<" "<<i;
	}
	cout<<endl;
	return 0;
}