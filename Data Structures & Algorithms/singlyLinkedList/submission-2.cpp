class LinkedList {
   private:
    class Node {
       public:
        friend class LinkedList;
        int elem{};
        Node* next{};
        Node(const int& element, Node* next = nullptr) : elem{element}, next{next} {}
    };
    int sz{0};
    Node* head{nullptr};
    Node* tail{nullptr};

   public:
    LinkedList() {};

    int get(int index) {
        if (sz <= index) return -1;
        Node* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp->elem;
    }

    void insertHead(int val) {
        head = new Node(val, head);
        if (sz == 0) tail = head;
        sz++;
    }

    void insertTail(int val) {
        Node* newest{new Node(val)};
        if (sz == 0)
            head = newest;
        else
            tail->next = newest;
        tail = newest;

        sz++;
    }

    bool remove(int index) {
        if (index < 0 || index >= sz) return false;
        Node* temp = head;
        if (index == 0) {
            // head
            head = head->next;
            delete temp;
            sz--;
            if (sz == 0) tail = nullptr;
            return true;
        }

        else {
            for (int i{0}; i < index-1; ++i) {
                temp = temp->next;
            }
            Node* old{temp->next};
            temp->next = old->next;
            if(old == tail)
                tail=temp;
            delete old;
            sz--;
            if (sz == 0) tail = nullptr;
            return true;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> vec{};
        Node* temp = head;
        for (int i{0}; i < sz; ++i) {
            vec.push_back(temp->elem);
            temp = temp->next;
        }
        return vec;
    }
};