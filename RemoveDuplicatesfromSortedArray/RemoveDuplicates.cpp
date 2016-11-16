#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
	public:
	int RemoveDuplicatesfromVector(vector<int> &vArray)
	{
		if(vArray.empty())
			return 0;
		
		int nIndex = 0;
		int nCurPos = 1;
		for(; nCurPos < vArray.size(); nCurPos++)
		{
			if(vArray[nIndex] != vArray[nCurPos])
			{
				vArray[++nIndex] = vArray[nCurPos];
			}
		}
		return ++nIndex;
	}
	int RemoveDuplicatesfromArray(int nArray[], int nLen)
	{
		if(nArray == NULL || nLen == 0)
			return 0;
		
		int nIndex = 0;
		for(int nCurPos = 1; nCurPos < nLen; nCurPos ++)
		{
			if(nArray[nIndex] != nArray[nCurPos])
			{
				nArray[++nIndex] = nArray[nCurPos];
			}
		}
		return ++nIndex;
	}
};

int main() {
	// your code goes here
	int nArray[10] = {0,0,0,1,2,3,3,3,4,5};
	vector<int> vArray(nArray,nArray+10);
	Solution A;
	int nLenV = A.RemoveDuplicatesfromVector(vArray);
	int nLen = A.RemoveDuplicatesfromArray(nArray,10);
	cout<<"nLenV = "<<nLenV<<endl; 
	cout<<"nLen = "<< nLen<<endl;

	cout<<endl;
	return 0;
}