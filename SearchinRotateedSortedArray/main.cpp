#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int nTarget;
	int searchTarget(vector<int> &vArray)
	{
		int nLen = vArray.size();
		if(nLen == 0)
			return -1;
		
		int nStart = 0;
		int nLast = nLen;
		int nMid;
		while(nStart != nLast)
		{
			nMid = nStart + (nLast - nStart)/2;
			if(vArray[nMid] == nTarget)
				return nMid;
			
			if(vArray[nMid] >= vArray[nStart])
			{
				if(nTarget >= vArray[nStart] && nTarget < vArray[nMid])
				{
					nLast = nMid;
				}
				else
				{
					nStart = nMid + 1;
				}
			}else
			{
				if(nTarget > vArray[nMid] && nTarget <= vArray[nLast - 1])
				{
					nStart = nMid + 1;
				}
				else
				{
					nLast = nMid;
				}
			}
		}
		return -1;
	}
};

int main() {
	// your code goes here
	int nArray[] = {9,0,1,2,3,4,5,6,7,8};
	int nLen = sizeof(nArray)/sizeof(int);
	vector<int> vArray(nArray, nArray + nLen);
	Solution A;
	A.nTarget = 10;
	int nSearch = A.searchTarget(vArray);
	if(nSearch < 0 )
		cout<<"Cannot find the Target "<<A.nTarget<<endl;
	else
	{
		cout<<"Find the Target, the nIndex is "<<nSearch<<endl;
	}
	return 0;
}