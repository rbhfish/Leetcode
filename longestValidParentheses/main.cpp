#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
	public:
	int longestValidParentheses(string A)
	{
		if(A.length() < 1)
			return 0;
			
		stack<int> stk;
		int nMaxLen = 0;
		int nStart = -1;
		
		for(int nIndex = 0; nIndex < A.length() ; ++nIndex)
		{
			string tmp(A,nIndex,1);
			if(tmp == "(")
			{
				stk.push(nIndex);
			}
			else
			{
				if(!stk.empty())
				{
					stk.pop();
					if(stk.empty())
						nMaxLen = (nMaxLen, nIndex - nStart);
					else
						nMaxLen = (nMaxLen, nIndex - stk.top());
				}
				else
				{
					nStart = nIndex;
				}
			}
		}
		return nMaxLen;
	}
};
int main() {
	// your code goes here
	return 0;
}