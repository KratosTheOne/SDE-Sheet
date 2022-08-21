class minStack{
    stack<int> s;
    int mini;
    public:
        // Constructor
        minStack(){
            mini = 1e+9;
        }

        // Function to add another element equal to num at the top of stack.
        void push(int num){
            s.push(num);
            if(mini > num)
                mini = num;
        }

        // Function to remove the top element of the stack.
        int pop(){
            if(s.empty())    return -1;
            int num = s.top();
            s.pop();
            if(mini == num){
                mini = 1e+9;
                stack<int> z;
                z = s;
                while(!z.empty()){
                    int n = z.top();
                    if(n < mini)
                        mini = n;
                    z.pop();
                }
            }
            return num;
        }

        // Function to return the top element of stack if it is present. Otherwise return -1.
        int top(){
            if(s.empty())    return -1;
            return s.top();
        }

        // Function to return minimum element of stack if it is present. Otherwise return -1.
        int getMin(){
            if(mini == 1e+9)
                return -1;
            return mini;
        }
};
