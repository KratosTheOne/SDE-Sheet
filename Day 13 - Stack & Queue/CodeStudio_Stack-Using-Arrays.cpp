// Stack class.
class Stack {
    int *ar;
    int topp;
    int size;
public:

    Stack(int capacity) {
        ar = new int[capacity];
        topp = -1;
        size = capacity;
    }

    void push(int num) {
        topp++;
        ar[topp] = num;
    }

    int pop() {
        if(isEmpty()){
            return -1;
        }
        int x = ar[topp];
        topp--;
        return x;
    }

    int top() {
        if(isEmpty()){
            return -1;
        }
        return ar[topp];
    }

    int isEmpty() {
        return (topp == -1) ? 1 : 0;
    }

    int isFull() {
        return (topp == size) ? 1 : 0;
    }

};
