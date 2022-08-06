int calculateMinPatforms(int a[], int d[], int n) {

    sort(a, a + n);
    sort(d, d + n);

    int plat = 1, res = 1;
    int i = 1, j = 0;

    while(i < n && j < n)
    {
        if(a[i] <= d[j])
        {
            plat++;
            i++;
        }
        else if(a[i] > d[j])
        {
            plat--;
            j++;
        }
        if(plat > res)
        {
            res = plat;
        }
    }

    return res;
}
