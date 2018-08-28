long repeatedString(string s, long n) 
{
    vector <char> poo;
    long SIZE = s.size();

    if (s.size() < 2)
    {
        if (s == "a")
        {
            return n;
        }
        else
        {
          return 0;
        }
    }
    else
    {
       vector <char> poo(s.begin(), s.end());

        for (long i = SIZE; i < n; i += SIZE)
        {
            copy(s.begin(), s.end(), back_inserter(poo));
        }
            poo.resize(n);
        long i = 0;
        long j = 0;
        for (long i =0 ; i < poo.size(); i++)
        {
            if(poo[i] == 'a')
                j++;
        }
        return j;
        }
  }