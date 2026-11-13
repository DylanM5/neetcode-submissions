class Deque {
   private:
    struct Node {
        int val{};
        Node* prev{};
        Node* next{};
        Node(int v) : val(v) {}
        Node(int v, Node* p, Node* n) : val(v), prev{p}, next{n} {}
    };
    size_t sz{0};
    Node* head{nullptr};
    Node* tail{nullptr};

   public:
    Deque() {};
    bool isEmpty() { return sz == 0; }

    void append(int value) {
        Node* n = new Node(value, tail, nullptr);
        if (tail)
            tail->next = n;
        else
            head = n;
        tail = n;
        ++sz;
    }

    void appendleft(int value) {
        Node* n = new Node(value, nullptr, head);
        if (head)
            head->prev = n;
        else
            tail = n;
        head = n;
        ++sz;
    }

    int pop() {
        if (isEmpty()) return -1;
        Node* old = tail;
        int ret = old->val;
        tail = tail->prev;
        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;
        delete old;
        --sz;
        return ret;
    }

    int popleft() {
        if (isEmpty()) return -1;
        Node* old = head;
        int ret = old->val;
        head = head->next;
        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete old;
        --sz;
        return ret;
    }
};
