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

    void deleteFromHeap()
    {
        //Step 1: put last in 1st
        arr[1] = arr[sz];

        //Step 2: delete last ele
        sz--;

        //step 3: build heap by verification
        int i = 1;
        while(i < sz)
        {
            int lChild = 2 * i;
            int rChild = 2 * i + 1;

            if(lChild < sz && arr[i] < arr[lChild])
            {
                swap(arr[i], arr[lChild]);
                i = lChild;
            }
            else if(rChild < sz && arr[i] < arr[rChild])
            {
                swap(arr[i], arr[lChild]);
                i = rChild;
            }
            else
                return;
        }
    }

    void heapify(int arr[], int n, int i)
    {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if(left <= n && arr[largest] < arr[left])
            largest = left;

        if(right <= n && arr[largest] < arr[right])
            largest = right;

        if(largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    void heapSort(int arr[], int n)
    {
        int sz = n;

        while(sz > 1)
        {
            swap(arr[sz], arr[1]);
            sz--;

            int i = 1;

            heapify(arr, sz, i);
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

    h.deleteFromHeap();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    for(int i = n / 2; i > 0; i--)
    {
        h.heapify(arr, n, i);
    }
    cout << "printing arr" << "\n";

    for(int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    cout << "printing arr after sort" << "\n";

    h.heapSort(arr, n);

    for(int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}


