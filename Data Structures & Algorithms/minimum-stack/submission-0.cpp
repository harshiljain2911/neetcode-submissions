class MinStack {
public:
    vector<int> arr;
    vector<int> marr;

    MinStack() {
    }
    
    void push(int val) {
        arr.push_back(val);

        if (marr.empty()) {
            marr.push_back(val);
        } else {
            marr.push_back(min(marr.back(), val));
        }
    }
    
    void pop() {
        marr.pop_back();
        arr.pop_back();
    }
    
    int top() {
        return arr.back();
    }
    
    int getMin() {
        return marr.back();
    }
};