#include <iostream>

/**
* Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};



ListNode * addTwoNumbers(ListNode * l1, ListNode * l2) {
	ListNode * p1 = l1;
	ListNode * p2 = l2;
	ListNode * ans;
	ListNode * a;
	ListNode * prev = nullptr;
	int sum;
	
	ans = new ListNode(0);
	a = ans;

	int q = 0;
	while (p1 != nullptr || p2 != nullptr) {
		int r = 0;
		if (p1 != nullptr && p2 != nullptr) {
			sum = p1->val + p2->val + ans->val;
			r = sum % 10;
			q = sum / 10;
			
			ans->val = r;

			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1 != nullptr) {
			if (ans->val == 0) {
				ans->val = p1->val;
				q = 0;
			}
			else {
				sum = p1->val + ans->val;
				r = sum % 10;
				q = sum / 10;

				ans->val = r;
			}
			p1 = p1->next;
		}
		else if (p2 != nullptr) {
			if (ans->val == 0) {
				ans->val = p2->val;
				q = 0;
			}
			else {
				sum = p2->val + ans->val;
				r = sum % 10;
				q = sum / 10;

				ans->val = r;
			}
			
			p2 = p2->next;
		}

		prev = ans;
		ans->next = new ListNode(q);
		ans = ans->next;
	}

	if (ans->val == 0) {
		delete prev->next;
		prev->next = nullptr;
	}
	
	return a;
}

int main() {
	ListNode * n1;
	ListNode * n2;
	ListNode * a;

	n1 = new ListNode(2);
	n1->next = new ListNode(4);
	n1->next->next = new ListNode(3);

	n2 = new ListNode(5);
	n2->next = new ListNode(6);
	n2->next->next = new ListNode(4);


	a = addTwoNumbers(n1, n2);

	while (a != nullptr) {
		std::cout << a->val << std::endl;
		a = a->next;
	}

	while (1);

	return 0;
}
