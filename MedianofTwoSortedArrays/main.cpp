#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
	public:
	float SearchMedianofTwoVector(vector<int> &vArrayA, vector<int> &vArrayB)
	{
		int nLen = vArrayA.size() + vArrayB.size();
		vector<int>::iterator A = vArrayA.begin();
		vector<int>::iterator B = vArrayB.begin();
		int nLenA = vArrayA.size();
		int nLenB = vArrayB.size();
		
		if(nLen % 2 == 0)
		{
			return ( FindKthfromTwoArray(A, nLenA, B , nLenB, nLen/2) + FindKthfromTwoArray(A, nLenA,B,nLenB,nLen/2 + 1))/2.0;
		}
		else
		{
			return FindKthfromTwoArray(A,nLenA,B,nLenB,nLen/2+1);
		}
		
	}
	private:
	int FindKthfromTwoArray(vector<int>::iterator A, int m, vector<int>::iterator B, int n, int k)
	{
		if(m > n)
			return FindKthfromTwoArray(B,n,A,m,k);
		if(m == 0)
			return *(B + k - 1);
		if(k == 1)
			return min(*A, *B);
		
		int ia = min(k/2, m);
		int ib = k - ia;
		
		if(*(A + ia - 1) < *(B + ib -1))
		{
			return FindKthfromTwoArray(A + ia, m - ia, B, n , k - ia);
		}
		else if(*(A + ia - 1) > *(B + ib - 1))
		{
			return FindKthfromTwoArray(A, m, B + ib, n - ib, k - ib);
		}
		else
		{
			return *(A + ia -1);
		}
		
	}
};

int main() {
	// your code goes here
	int nArrayA[] = {0,1,3,5,7,9,11,13};
	int nArrayB[] = {2,4,6,8,10};
	int nLenA = sizeof(nArrayA)/sizeof(int);
	int nLenB = sizeof(nArrayB)/sizeof(int);
 	vector<int> vArrayA(nArrayA, nArrayA + nLenA);
 	vector<int> vArrayB(nArrayB, nArrayB + nLenB);
 	Solution A;
 	
 	float fResult = A.SearchMedianofTwoVector(vArrayA,vArrayB);
 	
 	cout<<"Result = "<<fResult<<endl;
	return 0;
}