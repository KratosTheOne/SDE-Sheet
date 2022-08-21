//T.C & S.C -> O(1) & O(n)

class MinStack {

    stack<long long> st;
    long long mini;

public:
    MinStack() {

        mini = INT_MAX;

    }

    void push(int value) {

        long long val = value;
        if(st.empty())
        {
            mini = val;
            st.push(val);
        }
        else
        {
            if(val < mini)
            {
                st.push(2 * val * 1LL - mini);
                mini = val;
            }
            else
                st.push(val);
        }

    }

    void pop() {

        if(st.empty())
            return;

        long long el = st.top();
        st.pop();

        if(el < mini)
            mini = 2 * mini - el;

    }

    int top() {

        if(st.empty())
            return -1;

        long long el = st.top();

        if(el < mini)
            return mini;

        return el;

    }

    int getMin() {

        return mini;

    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/*
//T.C & S.C -> O(1) & O(2*n)

class MinStack {

    stack<pair<int, int>> st;

public:
    MinStack() {

    }

    void push(int val) {
        int mini;

        if(st.empty())
            mini = val;
        else
            mini = std::min(st.top().second, val);

        st.push({val, mini});
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
