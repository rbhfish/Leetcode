#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode
{
	int nValue;
	ListNode* next;
	ListNode(int x):nValue(x),next(NULL){ };
};

class Solution
{
	public:
	ListNode* removeKthElementfromEndofList(ListNode* list, int Kth)
	{
		if(list == NULL || Kth < 1)
			return list;
		
		ListNode dummy(-1);
		dummy.next = list;
		ListNode* prev_Kth = &dummy, *curPos = &dummy, *tmp;
		for(int nIndex = 0; curPos != NULL; nIndex++)
		{
			if(nIndex > Kth)
			{
				prev_Kth = prev_Kth->next;
			}
			curPos = curPos->next;
		}

		
		{
			tmp = prev_Kth->next->next;
			delete prev_Kth->next;
			prev_Kth->next = tmp;
			return dummy.next;
		}
	}
};

int main() {
	// your code goes here
	int nArray[] = {0,1,2,3,4,5,6,7,8,9};
	int nLen = sizeof(nArray)/sizeof(int);
	ListNode dummy(-1);
	ListNode* cur = &dummy;
	for(int nIndex = 0; nIndex < nLen; nIndex++)
	{
		cur->next = new ListNode(nArray[nIndex]);
		cur = cur->next;
	}
	Solution A;
	cur = A.removeKthElementfromEndofList(dummy.next,1);
	dummy.next = cur;
	if(cur != NULL)
	{
		while(cur)
		{
			cout<<cur->nValue<<" ";
			cur = cur->next;
		}
	}
	else
	{
		cout<<"There is nothing"<<endl;
	}
	return 0;
}