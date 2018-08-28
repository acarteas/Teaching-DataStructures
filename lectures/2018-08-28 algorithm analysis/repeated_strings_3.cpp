// Complete the repeatedString function below.
long repeatedString(string s, long n)
{
	long count = 0;
	long num_loops = (n / s.length());

	for (long i = 0; i < s.length(); i++)
	{
		if (s[i] == 'a')
		{
			count++;
		}
	}

	count = count * num_loops;

	long extra = n % s.length();

	if (extra != 0)
	{
		for (long i = 0; i < extra; i++)
		{
			if (s[i] == 'a')
			{
				count++;
			}
		}
	}

	return count;


}
