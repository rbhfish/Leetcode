#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
	public:
	stack<int> CalculateAdd(vector<int> &vArray, int nTarget)
	{
		stack<int> stkResult;
		int nLen = vArray.size();
		
		int nAdd = 0;
		
		for(int nIndex = nLen - 1; nIndex >= 0; --nIndex)
		{
			int nTmp = vArray[nIndex] + nTarget + nAdd;
			nTarget = 0;
			stkResult.push(nTmp % 10);
			nAdd = nTmp / 10;
		}
		
		if(nAdd > 0)
			stkResult.push(nAdd);
		
		return stkResult;
	}
};

int main() {
	// your code goes here
	int nArray[] = {9};
	int nLen = sizeof(nArray)/sizeof(int);
	vector<int> vArray(nArray,nArray + nLen);
	Solution A;
	stack<int> stk = A.CalculateAdd(vArray,9);
	while(!stk.empty())
	{
		cout<<stk.top()<<" ";
		stk.pop();
	}
	return 0;
}