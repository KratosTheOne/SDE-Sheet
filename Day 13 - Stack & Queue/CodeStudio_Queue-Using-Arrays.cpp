class Queue {
    int *arr;
    int s, e, currSize, maxSize;
public:
    Queue() {
        s = -1;
        e = -1;
        currSize = 0;
        maxSize = 100001;
        arr = new int[maxSize];
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(s == e)
            return true;
        return false;
    }

    void enqueue(int data) {
        if(currSize == maxSize)
            cout << "Queue is Full";
        else
        {
            arr[e] = data;
            e++;
        }
    }

    int dequeue() {
        if(s == e)
            return -1;
        else
        {
            int ans = arr[s];
            arr[s] = -1;
            s++;
            if(s == e)
            {
                s = 0;
                e = 0;
            }
            return ans;
        }
    }

    int front() {
        if(s == e)
            return -1;
        return arr[s];
    }
};
