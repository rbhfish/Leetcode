#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
	public:
	int SearchTargetII(vector<int> &vArray, int nTarget)
	{
		int nLen = vArray.size();
		if(nLen == 0)
			return -1;
		
		int nStart = 0;
		int nLast = vArray.size() -1;
		int nMid = 0;
		
		while(nStart != nLast)
		{
			nMid = nStart + (nLast - nStart)/2;
			if(vArray[nMid] == nTarget)
				return nMid;
				
			if(vArray[nStart] < vArray[nMid])
			{
				if(vArray[nStart] <= nTarget && nTarget < vArray[nMid])
				{
					nLast = nMid;
				}
				else
				{
					nStart = nMid + 1;
				}
			}
			else
			{
				if(vArray[nStart] > vArray[nMid])
				{
					if(vArray[nMid] < nTarget && nTarget <= vArray[nLast])
					{
						nStart = nMid + 1;
					}
					else
					{
						nLast = nMid ;
					}
				}
				else
				{
					nStart++;
				}
			}
		}
		return -1;
	}
};

int main() {
	// your code goes here
	int nArray[] = {6,0,1,1,1,1,1,1,2,3,4,5};
	int nLen = sizeof(nArray)/sizeof(int);
	vector<int> vArray(nArray, nArray + nLen);
	int nTarget = 1;
	Solution A;
	int nSearch = A.SearchTargetII(vArray, nTarget);
	if(nSearch == -1)
		cout<<"Cannot find the Target "<<nTarget<<endl;
	else
		cout<<"Find the Target "<<nTarget<<" the Index is "<<nSearch<<endl;
	
	return 0;
}