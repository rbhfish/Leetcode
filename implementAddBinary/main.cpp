#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	string implementAddBinary(string strA, string strB)
	{
		string strC;
		if(strA.empty() || strB.empty())
			return strC;
		
		int nCarry = 0;
		reverse(strA.begin(),strA.end());
		reverse(strB.begin(),strB.end());
		
		int nLenA = strA.length();
		int nLenB = strB.length();
		int nMax = (nLenA > nLenB)?nLenA:nLenB;
		
		for(int nIndex = 0; nIndex < nMax; ++nIndex)
		{
			int nA = (nIndex < nLenA)?(strA[nIndex] - '0'):0;
			int nB = (nIndex < nLenB)?(strB[nIndex] - '0'):0;
			
			int nC = nA + nB + nCarry;
			nCarry = nC / 2;
			strC.insert(strC.begin(),(nC%2)?'1':'0');
		}
		if(nCarry)
			strC.insert(strC.begin(),'1');
			
		return strC;
	}
};
int main() {
	// your code goes here
	string strA("1111");
	string strB("111111");
	Solution A;
	string strC = A.implementAddBinary(strA,strB);
	if(strC.empty())
		cout<<"there is something wrong"<<endl;
	else
		cout<<strC<<endl;
	return 0;
}