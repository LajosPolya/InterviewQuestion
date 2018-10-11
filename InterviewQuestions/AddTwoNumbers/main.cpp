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
	ListNode ** a = &ans;
	int sum;
	
	(*a) = new ListNode(0);

	int q = 0;
	while (p1 != nullptr || p2 != nullptr || q) {
		int r = 0;
		sum = ((p1) ? p1->val : 0) + ((p2) ? p2->val : 0) + q;
		r = sum % 10;
		q = sum / 10;

		(*a)->next = new ListNode(r);
		a = &(*a)->next;

		p1 = (p1) ? p1->next : nullptr;
		p2 = (p2) ? p2->next : nullptr;
	}
	
	return ans->next;
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
