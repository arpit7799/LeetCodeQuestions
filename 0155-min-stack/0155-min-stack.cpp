class MinStack {

    stack<int> st;
    stack<int> minSt;

  public:

    MinStack() {
        
    }

    void push(int x) {

        st.push(x);

        if (minSt.empty())
            minSt.push(x);
        else
            minSt.push(min(x, minSt.top()));
    }

    void pop() {

        if (st.empty())
            return;

        st.pop();
        minSt.pop();
    }

    int top() {

        if (st.empty())
            return -1;

        return st.top();
    }

    int getMin() {

        if (minSt.empty())
            return -1;

        return minSt.top();
    }
};