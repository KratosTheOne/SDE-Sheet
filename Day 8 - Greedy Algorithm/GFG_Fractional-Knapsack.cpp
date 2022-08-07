//T.C & S.C -> O(nlogn) & O(1)

/*
struct Item{
    int value;
    int weight;
};
*/

bool comp(Item a, Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item a[], int n)
    {
        sort(a, a + n, comp);

        int currWeight = 0;
        double maxValue = 0.0;

        for(int i = 0; i < n; i++)
        {
            if(currWeight + a[i].weight <= W)
            {
                currWeight += a[i].weight;
                maxValue += a[i].value;
            }
            else
            {
                int remain = W - currWeight;
                maxValue += (a[i].value / (double)a[i].weight) * remain;
                break;
            }
        }

        return maxValue;
    }

};
