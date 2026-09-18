class DynamicArray {
   private:
    int* arr;
    int capacity;
    int length;

   public:
    DynamicArray(int capacity) {
        this->capacity = capacity;
        this->length = 0;
        this->arr = new int[capacity];
    }

    int get(int i) { return this->arr[i]; }

    void set(int i, int n) { this->arr[i] = n; }

    void pushback(int n) {
        if (length == capacity) {
            resize();
        }
        arr[length++] = n;
    }

    int popback() {
        length--;
        return arr[length];
    }

    void resize() {
        int newCapacity = this->capacity * 2;
        
        int* newArr = new int[newCapacity];
        for (int i = 0; i < length; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = nullptr;
        this->capacity=newCapacity;
        arr = newArr;
    }

    int getSize() { return this->length; }

    int getCapacity() { return this->capacity; }
};
