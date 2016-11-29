#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int implementstrStr(string strD,string strT)
	{
		if(strT.empty())
			return 0;
		
		int nLenD = strD.size();
		int nLenT = strT.size();
		
		if(nLenD < nLenT)
			return -1;
		
		int nIndexT = 0;
		int nOccurance = -1;
		for(int nIndex = 0; nIndex < nLenD - nLenT + 1; ++nIndex)
		{
			int nIndexD = nIndex;
			while(strT[nIndexT] == strD[nIndexD])
			{
				if(nIndexT == 0)
					nOccurance = nIndexD;
				
				if(nIndexT == nLenT - 1)
					return nOccurance;
				
				nIndexT++;
				nIndexD++;
			}
			nOccurance = -1;
			nIndexT = 0;
		}
		return nOccurance;
	}
};

int main() {
	// your code goes here
	string strD = "This is a sentence!";
	string strT = "sentence";
	Solution A;
	int nOccurrence = A.implementstrStr(strD,strT);
	if(nOccurrence == 0)
		cout<<"strT is empty"<<endl;
	else if (nOccurrence == -1)
		cout<<"Cannot find it"<<endl;
	else
		cout<<"Find it the first occurrance is "<<nOccurrence<<endl;
	return 0;
}