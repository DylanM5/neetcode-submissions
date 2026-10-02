class StringIterator {
   private:
    string str;
    size_t idx{0};
    size_t sz{0};
    long long remainingCount{0};
    char currentChar{' '};

   public:
    StringIterator(string compressedString) : str{std::move(compressedString)}, sz{str.size()} {}
    char next() {
        if (!hasNext()) return ' ';
        if (remainingCount == 0) {
            currentChar = str[idx++];
            long long i{0};
            while (idx < sz && str[idx] >= '0' && std::isdigit(str[idx])) i = i * 10 + (str[idx++] - '0');
            remainingCount = i;
        }
        --remainingCount;
        return currentChar;
    }

    bool hasNext() { return remainingCount > 0 || idx < sz; }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
