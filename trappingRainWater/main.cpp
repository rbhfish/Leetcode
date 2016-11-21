#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
	public:
	int CalculateMaxbyUsingArray(vector<int> &vArray)
	{
		int nResult = 0;
		if(vArray.size() < 3)
			return -1;
			
		int nSize = vArray.size();
		
		int *lMax = new int[nSize]();
		int *rMax = new int[nSize]();
		
		
		for(int i = 1; i < nSize; ++i)
		{
			lMax[i] = max(vArray[i - 1],lMax[i - 1]);
			rMax[nSize - i - 1] = max(vArray[nSize - i], rMax[nSize - i]);
		}
		
		for(int i = 1; i < nSize; ++i)
		{
			int height = min(lMax[i],rMax[i]);
			if(height > vArray[i])
				nResult += height - vArray[i];
		}
		
		delete[] lMax;
		delete[] rMax;
		
		return nResult;
	}
	
	int CalculateMaxbyUsingArrayII(vector<int> &vArray)
	{
		int nSize = vArray.size();
		int nResult = 0;
		if(nSize < 3)
			return -1;
		
		int nMax = 0;
		
		int lMax = 0;
		int rMax = 0;
		
		for(int i = 0; i < nSize; ++i)
		{
			if(vArray[nMax] < vArray[i])
				nMax = i;
		}
		
		for(int i = 0; i < nMax ; ++i)
		{
			if(lMax < vArray[i])
				lMax = vArray[i];
			else
				nResult += lMax - vArray[i];
		}
		
		for(int i = nSize - 1; i != nMax ; --i)
		{
			if(rMax < vArray[i])
				rMax = vArray[i];
			else
				nResult += rMax - vArray[i];
		}
		
		return nResult;
	}

};

int main() {
	// your code goes here
	int nArray[] = {0,9,5,11,15,6,7,4,3,9,0};
	int nLen = sizeof(nArray)/sizeof(int);
	vector<int> vArray(nArray,nArray + nLen);
	Solution A;
	int nResultA = A.CalculateMaxbyUsingArray(vArray);
	int nResultB = A.CalculateMaxbyUsingArrayII(vArray);
	cout<<"A = "<<nResultA<<endl;
	cout<<"B = "<<nResultB<<endl;
	return 0;
}
