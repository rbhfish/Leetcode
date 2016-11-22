#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode
{
	int nValue;
	ListNode* next;
	ListNode(int x):nValue(x),next(NULL){};
};

class Solution
{
	public:
	ListNode* AddTwoNumbyListNode(ListNode* lNode1, ListNode* lNode2)
	{
		cout<<"AddTwoNumbyListNode"<<endl;
		ListNode dummy(-1);
		if(lNode1 == NULL && lNode2 == NULL)
			return dummy.next;
		
		ListNode* prev = &dummy;
		ListNode* first = lNode1;
		ListNode* second = lNode2;
		
		int nCarry = 0;
		
		while(first != NULL || second != NULL)
		{
			int n1 = (first != NULL)?first->nValue:0;
			int n2 = (second != NULL)?second->nValue:0;
			
			int nAdd = n1 + n2 + nCarry;
			nCarry = nAdd / 10;
			int n = nAdd % 10;
			prev->next = new ListNode(n);
			prev = prev->next;
			if(first != NULL)
				first = first->next;
			if(second !=NULL)
				second = second->next;
		}
		if(nCarry > 0)
		{
			prev->next = new ListNode(nCarry);
		}
		return dummy.next;
	}
};

int main() {
	// your code goes here
	int nArray1[] = {9,9,9,9,9,9,9,0,1};
	int nLen1 = sizeof(nArray1)/sizeof(int);
	int nArray2[] = {9,9,9,9,9,9,9,9,9,1};
	int nLen2 = sizeof(nArray2)/sizeof(int);
	
	ListNode l1(-1);
	ListNode l2(-1);
	
	ListNode* first = &l1;
	ListNode* second = &l2;
	
	for(int nIndex = 0 ; nIndex <max(nLen1,nLen2) ; ++nIndex)
	{
		if(nIndex < nLen1)
		{
			first->next = new ListNode(nArray1[nIndex]);
			first = first->next;
		}
		if(nIndex < nLen2)
		{
			second->next = new ListNode(nArray2[nIndex]);
			second = second->next;
		}
	}
	Solution A;
	ListNode* B = A.AddTwoNumbyListNode(l1.next,l2.next);
	while(B != NULL)
	{
		cout<<B->nValue<<" ";
		B = B->next;
	}
	return 0;
}