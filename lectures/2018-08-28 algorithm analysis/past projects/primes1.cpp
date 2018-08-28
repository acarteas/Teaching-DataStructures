void testPrimes()
{
	int lower, upper;
	getInput(lower, upper);
	for (int n = lower; n < upper; n++)
	{
		bool status = true;
		int m = 2;
		for (m; m < n; m++)
		{
			if (n % m == 0)
				status = false;
		}
		if (status)
			cout << n << " is prime!." << endl;

	}
}

for(int i = 0; i < n; i++)
{
	cout << "Hello, World!" << endl;
}

for(int i = 0; i < n; i++)
{
	for(int j = 0; j < i; j++)
	{
		cout << "Hello, World!" << endl;
	}
}

void testTwinPrimes()
{
	int lower, upper;
	getInput(lower, upper);
	int nMinOne = 0;

	//! varies by UPPER
	for (int n = lower; n < upper; n++)
	{
		bool status = true;
		int m = 2;

		//! varies by N (lower, 2, 3, ..., upper)
		for (m; m < n; m++)
		{
			//When analyzing nested for loops, concentrate on code
			//inside.
			if (n % m == 0)
				status = false;
		}
		if (status)
		{
			if (n - nMinOne == 2)
				cout << nMinOne << " and " << n << " are double primes!" << endl;
			nMinOne = n;
		}
	}
}


void testTriplePrimes()
{
	int lower, upper;
	getInput(lower, upper);

	int nMinTwo = 0;
	int nMinFour = 0;
	int nMinSix = 0;
	for (int n = lower; n < upper; n++)
	{
		bool status = true;
		int m = 2;
		for (m; m < n; m++)
		{
			if (n % m == 0)
				status = false;
		}
		if (status)
		{
			nMinFour = (nMinTwo - 2);
			nMinSix = (nMinTwo - 4);
			bool statusTwo = true, statusThree = true;
			int p = 2, k = 2;
			for (p; p < nMinFour; p++)
			{
				if (nMinFour % p == 0)
					statusTwo = false;
			}
			if (statusTwo && (n - nMinFour == 6))
				cout << nMinFour << ", " << nMinTwo << ", and " << n << " are a prime triplet!" << endl;

			for (k; k < nMinSix; k++)
			{
				if (nMinSix % k == 0)
					statusThree = false;
			}
			if (statusThree && (n - nMinSix == 6))
				cout << nMinSix << ", " << nMinTwo << ", and " << n << " are a prime triplet!" << endl;

			nMinTwo = n;
		}
	}
}

void testQuadPrimesTenK()
{
	//int lower, upper;
	//getInput(lower, upper);

	int nMinTwo = 0;
	int nMinSix = 0;
	int nMinEight = 0;

	for (int n = 7; n < 50000; n++)
	{
		bool status = true;
		int m = 2;
		for (m; m < n; m++)
		{
			if (n % m == 0)
				status = false;
		}
		if (status)
		{
			nMinSix = (nMinTwo - 4);
			nMinEight = (nMinTwo - 6);
			bool statusTwo = true, statusThree = true;
			int p = 2, k = 2;

			for (p; p < nMinSix; p++)
			{
				if (nMinSix % p == 0)
					statusTwo = false;
			}

			for (k; k < nMinEight; k++)
			{
				if (nMinEight % k == 0)
					statusThree = false;
			}

			if (statusTwo && statusThree && (n - nMinEight == 8))
				cout << nMinEight << ", " << nMinSix << ", " << nMinTwo << " and " << n << " are a prime quadruplet!" << endl;

			nMinTwo = n;
		}
	}
}


void testQuintPrimesTenK()
{
	//int lower, upper;
	//getInput(lower, upper);

	int nMinTwo = 0,
		nMinSix = 0,
		nMinEight = 0,
		nMinTwelve = 0;

	for (int n = 7; n < 50000; n++)
	{
		bool status = true;
		int m = 2;
		for (m; m < n; m++)
		{
			if (n % m == 0)
				status = false;
		}
		if (status)
		{
			nMinSix = (nMinTwo - 4);
			nMinEight = (nMinTwo - 6);
			nMinTwelve = (nMinTwo - 10);
			bool statusTwo = true, statusThree = true, statusFour = true;
			int p = 2, k = 2, q = 2;

			for (p; p < nMinSix; p++)
			{
				if (nMinSix % p == 0)
					statusTwo = false;
			}

			for (k; k < nMinEight; k++)
			{
				if (nMinEight % k == 0)
					statusThree = false;
			}

			for (q; q < nMinTwelve; q++)
			{
				if (nMinTwelve % q == 0)
					statusFour = false;
			}

			if (statusTwo && statusThree && statusFour && (n - nMinTwelve == 12))
			{
				cout << nMinTwelve << ", " << nMinEight << ", " << nMinSix << ", " << nMinTwo;
				cout << " and " << n << " are a prime quintuplet!" << endl;
			}

			nMinTwo = n;
		}
	}
}
