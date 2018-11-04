

using namespace std;

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode * swapPairs(ListNode * head);

int main() {
	ListNode * t = new ListNode(1);
	t->next = new ListNode(2);
	t->next->next = new ListNode(3);
	t->next->next->next = new ListNode(4);
	t->next->next->next->next = new ListNode(5);

	ListNode * p = swapPairs(t);


	return 0;
}


ListNode * swapPairs(ListNode * head) {
	ListNode * t = nullptr;
	ListNode * p = nullptr;
	ListNode * h = nullptr;

	if (head == nullptr) {
		return nullptr;
	}

	t = head;
	p = head->next;
	h = head;

	if (head->next != nullptr) {
		head = head->next;

		h->next = p->next;
		p->next = t;

		h = t;
		t = t->next;
		if (t != nullptr) {
			p = t->next;
		}
	}

	while (t != nullptr && p != nullptr) {
		h->next = p;
		t->next = p->next;
		p->next = t;

		h = t;
		t = t->next;
		if (t != nullptr) {
			p = t->next;
		}
		
	}

	return head;
}
