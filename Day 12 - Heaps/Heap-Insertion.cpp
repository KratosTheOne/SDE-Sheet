//For max-heap
//For min-heap just reverse the if conditions for parent;

#include<bits/stdc++.h>
using namespace std;

class heap{
public:
    int arr[100];
    int sz;

    heap()
    {
        arr[0] = -1;
        sz = 0;
    }

    void insertHeap(int val)
    {
        sz = sz + 1;
        int i = sz;
        arr[i] = val;

        while(i > 1)
        {
            int parent = i / 2;

            if(arr[parent] < arr[i])
            {
                swap(arr[parent], arr[i]);
                i = parent;
            }
            else
                return;
        }
    }

    void print()
    {
        for(int i = 1; i <= sz; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    heap h;
    h.insertHeap(50);
    h.insertHeap(55);
    h.insertHeap(53);
    h.insertHeap(52);
    h.insertHeap(54);

    h.print();

    return 0;
}
