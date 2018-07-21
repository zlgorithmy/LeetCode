#include <assert.h>
#include <unordered_map>
#include <vector>

#include "../Utility/type.h"

using namespace std;

class Solution2
{
  public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		if (l1 == nullptr)
		{
			return l2;
		}
		if (l2 == nullptr)
		{
			return l1;
		}

		struct ListNode *p = l1;
		struct ListNode *p1 = l1;
		struct ListNode *p2 = l2;
		int c = 0;

		while (l1 && l2)
		{
			p1 = l1;
			p2 = l2;

			int k = l1->val + l2->val + c;
			l1->val = k % 10;
			c = k / 10;

			l1 = l1->next;
			l2 = l2->next;
		}
		if (l2)
		{
			p1->next = l2;
			l1 = l2;
		}
		while (l1)
		{
			p1 = l1;
			int k = l1->val + c;
			l1->val = k % 10;
			c = k / 10;

			l1 = l1->next;
		}
		if (c)
		{
			struct ListNode *nc = (struct ListNode *)malloc(sizeof(struct ListNode));
			nc->next = NULL;
			nc->val = c;

			p1->next = nc;
		}
		return p;
	}
};