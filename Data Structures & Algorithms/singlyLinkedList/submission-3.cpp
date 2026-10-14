class LinkedList {
   public:
    struct Node {
        int val{};
        Node* next = nullptr;
        Node(int n) { val = n; };
    };

   private:
    int sz{0};
    Node* head{};
    Node* tail{};

   public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    };

    int get(int index) {
        if (index >= sz) return -1;

        Node* temp = head;
        for (int i{0}; i < index; ++i) temp = temp->next;

        return temp->val;
    }

    void insertHead(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
        if (!tail) tail = head;
        ++sz;
    }

    void insertTail(int val) {
        Node* n = new Node(val);
        if (!head)
            head = tail = n;
        else {
            tail->next = n;
            tail = n;
        }
        ++sz;
    }

    bool remove(int index) {
        if (index >= sz || index < 0) return false;

        Node* temp = head;
        if (index == 0) {
            head = head->next;
            if (!head) tail = nullptr;
            delete temp;
            --sz;

            return true;
        }

        Node* prev = head;
        for (int i{0}; i < index-1; ++i) {
            prev = prev->next;
        }
        temp = prev->next;
        prev->next = temp->next;
        if (temp == tail) tail = prev;
        delete temp;
        --sz;

        return true;
    }

    vector<int> getValues() {
        vector<int> ret{};
        Node* curr = head;
        while (curr != nullptr) {
            ret.push_back(curr->val);
            curr = curr->next;
        }

        return ret;
    }
};
