#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode * removeNthFromEnd(ListNode * head, int n);

int main() {
	ListNode * node = new ListNode(1);
	node->next = new ListNode(2);
	node->next->next = new ListNode(3);
	removeNthFromEnd(node, 3);

}


ListNode * removeNthFromEnd(ListNode * head, int n) {
	ListNode * p = head;
	ListNode * t = head;
	long ahead = 0;

	while (t->next != nullptr) {
		t = t->next;
		ahead++;
		if (ahead > n) {
			p = p->next;
		}
	}

	if (ahead > n) {
		ListNode * ne = p->next->next;
		delete p->next;
		p->next = ne;
	}
	else if(ahead == n) {
		if (p->next->next != nullptr) {
			ListNode * ne = p->next->next;
			delete p->next;
			p->next = ne;
		}
		else {
			delete p->next;
			p->next = nullptr;
		}
	}
	else {
		if (p->next != nullptr) {
			head = p->next;
			delete p;
		}
		else {
			delete head;
			head = nullptr;
		}

	}
	
	return head;
}