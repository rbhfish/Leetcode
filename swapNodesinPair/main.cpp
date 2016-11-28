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
	ListNode* swapEveryTwoElement(ListNode* list)
	{
		if(list == NULL)
			return list;
		ListNode dummy(-1);
		dummy.next = list;
		ListNode* prev = &dummy;
		ListNode* curNode = list;
		ListNode* nxtNode = list->next;
		int nIndex = 0;

		while(curNode != NULL && nxtNode != NULL)
		{
			nIndex++;
			prev->next = nxtNode;
			curNode->next = nxtNode->next;
			nxtNode->next = curNode;
			prev = curNode;
			curNode = curNode->next;
			if(curNode != NULL)
				nxtNode = curNode->next;
		}

		return dummy.next;
	}
};

int main() {
	// your code goes here
	int nArray[] = {0,1,2,3,4,5};
	int nLen = sizeof(nArray)/sizeof(int);
	ListNode dummy(-1);
	ListNode* cur = &dummy;
	for(int nIndex = 0; nIndex < nLen; nIndex++)
	{
		cur->next = new ListNode(nArray[nIndex]);
		cur = cur->next;
	}
	Solution A;
	cur = A.swapEveryTwoElement(dummy.next);
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