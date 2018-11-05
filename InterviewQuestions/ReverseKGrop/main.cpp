
using namespace std;

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode * reverseKGroup(ListNode * head, int k);

int main() {
	ListNode * h = new ListNode(1);
	h->next = new ListNode(2);
	
	h = reverseKGroup(h, 2);


	return 0;
}

ListNode * reverseKGroup(ListNode * head, int k) {
	if (head == nullptr || head->next == nullptr || k <= 1) {
		return head;
	}

	ListNode * p = head->next;
	ListNode * r = head->next->next;
	ListNode * l = head;

	for (int i = 0; i < k - 1 && r != nullptr; i++) {
		p->next = head;
		head = p;
		p = r;
		if (r != nullptr) {
			r = r->next;
		}
	}

	l->next = p;

	return head;
}
