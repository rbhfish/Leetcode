#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
	public:
	vector<vector<int> > findThreeSumbyTarget(vector<int> &vArray, int nTarget)
	{
		vector<vector<int> > vResult;
		if(vArray.size() < 3)
			return vResult;
		
		sort(vArray.begin(),vArray.end());

		for(vector<int>::iterator it = vArray.begin(); it != vArray.end(); ++it)
		{
			int nTwoSum = nTarget - *it;
			
			vector<int>::iterator itA = it + 1;
			for( ; itA != vArray.end(); ++itA)
			{
				int nTmp = nTwoSum - *itA;
				vector<int>::iterator tmpIt = find(itA,vArray.end(),nTmp);
				if(tmpIt != vArray.end())
				{
					if(*it != *itA || *it != *tmpIt || *itA != *tmpIt)
					{
						vector<int> tmp;
						tmp.push_back(*it);
						tmp.push_back(*itA);
						tmp.push_back(*tmpIt);
						vResult.push_back(tmp);
					}
				}
			}
		}
		return vResult;
	}
	vector<vector<int> > findThreeSumImproved(vector<int> &vArray,int nTarget)
	{
		vector<vector<int> > vResult;
		if(vArray.size() < 3)
			return vResult;
		
		sort(vArray.begin(),vArray.end());
		
		auto last = vArray.end();
		
		for(auto i = vArray.begin(); i < last - 2; ++i)
		{
			if(i > vArray.begin() && (*i == *(i - 1) ) )
				continue;
			
			auto j = i + 1;
			auto k = last - 1;
			
			while( j < k)
			{
				int nSum = *i + *j + *k;
				if(nSum < nTarget)
				{
					j++;
					while( (*j == *(j - 1)) && j < k)
						j++;
				}
				else if(nSum > nTarget)
				{
					k--;
					while((j < k) && (*(k) == *(k+1)))
						k--;
				}
				else
				{
					vector<int> tmp;
					tmp.push_back(*i);
					tmp.push_back(*j);
					tmp.push_back(*k);
					vResult.push_back(tmp);
					j++;
					k--;
					while((*j == *(j-1))&&(*k == *(k+1)) && j < k)
						j++;
				}
			}
		}
		
		return vResult;
	}
};

int main() {
	// your code goes here
	int nArray[] = {-1,-2,-5,0,1,4,6,7,8,9,0,3,10,0};
	int nLen = sizeof(nArray)/sizeof(int);
	vector<int> vArray(nArray, nArray + nLen);
	Solution A;
	int nTarget = 10;
	
	vector<vector<int> >vResult = A.findThreeSumbyTarget(vArray,nTarget);
	for(auto i : vResult)
	{
		for(auto j : i)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}
