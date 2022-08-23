int atoi(string str) {
    int temp = 0;

    int n = str.size();

    for(int i=0; i<n; i++)
    {
        if(str[i] - '0'>=0 && str[i] - '0' <= 9)
        {
            temp = temp*10 + (str[i]-'0');
        }
    }
    if(str[0] == '-')
        return -1*temp;
    return temp;
}
