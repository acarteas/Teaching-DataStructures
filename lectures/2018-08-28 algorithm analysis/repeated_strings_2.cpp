long repeatedString(string s, long n)
{
    char goal = 'a';
    int chamnt = 0;
    long up = 0;  //began to work once switched from int type to long type

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == goal)
        {
            ++ chamnt;
        }
    }

    if(n % s.size() == 0)
    {
        if(chamnt != 1)
        {
            up = (n/s.size())*chamnt;
        }
        else
        {
            up = chamnt * n;
        }
    }

    else
    {
        if(chamnt != 1)
        {
            up = ((n-1)/s.size());
            up = (up * chamnt) + 1;
        }
        else
        {
            up = n;
        }
    }

    return up;
}
