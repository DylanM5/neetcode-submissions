class MyLinkedList {
   private:
    struct Node {
        int val{};
        Node* prev;
        Node* next;
        Node(int n) { val = n; };
    };
    Node* head;
    Node* tail;
    int sz{};

   public:
    MyLinkedList() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    };

    int get(int index) {
        if (index >= 0 && index < sz) {
            Node* node = head->next;
            for (int i{0}; i < index; ++i) {
                node = node->next;
            }
            return node->val;
        }
        return -1;
    }

    void addAtHead(int val) { addAtIndex(0, val); }

    void addAtTail(int val) { addAtIndex(sz, val); }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > sz) return;
        Node* temp = head->next;
        for (int i{0}; i < index; ++i) {
            temp = temp->next;
        }

        Node* node = new Node(val);
        Node* prev = temp->prev;

        node->prev = prev;
        node->next = temp;
        prev->next = node;
        temp->prev = node;

        ++sz;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= sz) return;
        Node* temp = head->next;
        for (int i{0}; i < index; ++i) {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
        --sz;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */