#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int nTime;
	int RemoveDuplicatesfromArray(int nArray[], int nLen)
	{
			
		if(nLen <= nTime)
			return nLen;
			
		int nIndex = nTime;

		for(int nCurPos = nTime ; nCurPos < nLen ; nCurPos++)
		{
			if(nArray[nCurPos] != nArray[nIndex - nTime])
			{
				nArray[nIndex++] = nArray[nCurPos];
			}
		}
		return nIndex;
	}
};

int main() {
	// your code goes here
	int nArray[] = {1,1,1,1,1,1,2,2,2,2,2,2,2,3,4,4,4,4,4,4,4,5,5,5,5,6,7,8,9};
	int nLength = sizeof(nArray)/sizeof(int);
	cout<<"nLength = "<<nLength<<endl;
	Solution A;
	A.nTime = 3;
	for(int nIndex = 0; nIndex < nLength;nIndex++)
	{
		cout<<nArray[nIndex]<<" ";
	}
	cout<<endl;
	int nLen = A.RemoveDuplicatesfromArray(nArray,nLength);
	//cout<<"nLen = "<<nLen<<endl;
	for(int nIndex = 0; nIndex < nLen;nIndex++)
	{
		cout<<nArray[nIndex]<<" ";
	}
	cout<<endl;
	return 0;
}