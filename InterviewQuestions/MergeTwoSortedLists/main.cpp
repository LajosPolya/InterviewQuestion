using namespace std;

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(nullptr) {}
	
};

ListNode * mergeTwoLists(ListNode * l1, ListNode * l2);

int main() {
	ListNode * one = new ListNode(1);
	one->next = new ListNode(2);
	one->next->next = new ListNode(4);

	ListNode * two = new ListNode(1);
	two->next = new ListNode(3);
	two->next->next = new ListNode(4);
	
	ListNode * a = mergeTwoLists(one, two);

	return 0;
}


ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {

	if (l1 == nullptr && l2 != nullptr) {
		return l2;
	}
	else if (l2 == nullptr && l1 != nullptr) {
		return l1;
	}
	else if (l2 == nullptr && l1 == nullptr) {
		return nullptr;
	}

	ListNode * h = nullptr;
	ListNode * p = nullptr;

	if (l1->val < l2->val) {
		h = l1;
		p = l1;
		l1 = l1->next;
	}
	else {
		p = l2;
		h = l2;
		l2 = l2->next;
	}

	while (l1 != nullptr && l2 != nullptr) {
		if (l1->val <= l2->val) {
			p->next = l1;
			p = p->next;
			l1 = l1->next;
		}
		else {
			p->next = l2;
			p = p->next;
			l2 = l2->next;
		}
	}

	if (l1 != nullptr) {
		p->next = l1;
	}
	else if (l2 != nullptr) {
		p->next = l2;
	}

	return h;
}
