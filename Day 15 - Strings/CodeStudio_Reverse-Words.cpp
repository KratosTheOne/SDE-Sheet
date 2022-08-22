string reverseString(string str)
{
    int i = str.length();
    string ans = "";

    while(i >= 0)
    {
        if(str[i] == ' ')
            i--;

        else
        {
            if(ans.length() > 0)
                ans.push_back(' ');

            int j = i;

            while(j >= 0 && str[j] != ' ')
                j--;

            ans.append(str.substr(j + 1, i - j));
            i = j;
        }
    }

    return ans;
}
