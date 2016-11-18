#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
	public:
	int findLongestConsecutingMap(vector<int> &vArray)
	{
		unordered_map<int, bool> map;
		int nLongest = 0;
		
		for(auto i : vArray)
			map[i] = false;
			
		for(auto i :vArray)
		{
			if(map[i])
				continue;
			int nLen = 0;
			
			map[i] = true;
			for(int j = i + 1; map.find(j) != map.end(); j++)
			{
				map[j] = true;
				nLen++;
			}
			
			for(int j = i - 1; map.find(j) != map.end(); j--)
			{
				map[j] = true;
				nLen++;
			}
			nLongest = max(nLongest, nLen);
		}
		return nLongest;
	}
	int findLongestConsecutiveVector(vector<int> &vArray)
	{
		int nLongest = 0;
		
		for(auto i : vArray)
		{
			int nLen = 0;
			vector<int>::iterator it = vArray.end();
			for(int j = i + 1; it != find(vArray.begin(),vArray.end(),j); j++)
			{
				nLen++;
			}
			for(int j = i - 1; it != find(vArray.begin(),vArray.end(),j); j--)
			{
				nLen++;
			}
			nLongest = max(nLen,nLongest);
		}
		return nLongest;
	}
};
int main() {
	// your code goes here
	int nArray[] = {100,2,3,1,6,200,4,8,300,7,5};
	int nLen = sizeof(nArray)/sizeof(int);
	vector<int> vArray(nArray, nArray + nLen);
	Solution A;
	int nLengthA = A.findLongestConsecutingMap(vArray);
	int nLengthB = A.findLongestConsecutiveVector(vArray);
	cout<<"nLengthA is "<<nLengthA<<endl;
	cout<<"nLengthB is "<<nLengthB<<endl;
	return 0;
}
